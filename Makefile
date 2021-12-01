#-------------------------------------------------------------------------------
# clear defaults
.SUFFIXES:
.SECONDARY:

#-------------------------------------------------------------------------------
# directories and files

# sdk directories (environment)
export DEVKITPRO		:=	/home/muffin/Desktop/code/sdk/devkitpro
export DEVKITPPC		:=	$(DEVKITPRO)/devkitPPC

# file prefix (environment)
export PREFIX			:=	powerpc-eabi-

# directories
DIRS_SOURCE				:=	source
DIRS_INCLUDE			:=	include
DIRS_BUILD				:=	build
DIRS_LIB				:=	lib

# build list of source files by extension
SRCFILES_C				:=	$(foreach dir,$(DIRS_SOURCE),$(notdir $(wildcard $(dir)/*.c)))
SRCFILES_CPP			:=	$(foreach dir,$(DIRS_SOURCE),$(notdir $(wildcard $(dir)/*.cpp)))
SRCFILES				:=	$(SRCFILES_C) $(SRCFILES_CPP)

# build list of object files by extension
OBJFILES_C				:=	$(SRCFILES_C:.c=.o)
OBJFILES_CPP			:=	$(SRCFILES_CPP:.cpp=.o)
OBJFILES				:=	$(OBJFILES_C) $(OBJFILES_CPP)

OBJFILES_INPROGRESS		:=	lwp
OBJFILES_EXCLUDE		:=	$(OBJFILES_INPROGRESS) debug
OBJFILES_FINAL			:=	$(filter-out $(addsuffix .o,$(OBJFILES_EXCLUDE)),$(OBJFILES))

INCLUDE_LOCAL			:=	$(DIRS_INCLUDE)
INCLUDE_SYSTEM			:=	$(DEVKITPRO)/libogc/include

VPATH					:=	$(DIRS_LIB) $(DIRS_BUILD) $(DIRS_SOURCE) $(DIRS_INCLUDE) \
							$(foreach \
								dir,\
								$(DIRS_INCLUDE),\
								$(filter-out \
									$(wildcard */*.*),\
									$(wildcard $(dir)/*)\
								)\
							)

#-------------------------------------------------------------------------------
# compiler and archiver + flags
CC						:=	$(DEVKITPPC)/bin/$(PREFIX)gcc.exe
CXX						:=	$(DEVKITPPC)/bin/$(PREFIX)g++.exe
AR						:=	$(DEVKITPPC)/bin/$(PREFIX)ar.exe

CFLAGS_WARNINGS			:=	all extra no-comment no-cpp no-uninitialized

CXXFLAGS_STANDARDS		:=	-std=c++17
CXXFLAGS_DEBUG			:=	-save-temps

CPPFLAGS_INCLUDE		:=	$(addprefix -I,$(INCLUDE_LOCAL)) \
							$(addprefix -I,$(INCLUDE_SYSTEM))
CPPFLAGS_OPTIMIZATION	:=	-O2
CPPFLAGS_OTHER			:=	-ftabstop=4

CFLAGS					:=	$(addprefix -W,$(CFLAGS_WARNINGS))
CXXFLAGS				:=	$(CFLAGS) $(CXXFLAGS_STANDARDS) $(CXXFLAGS_DEBUG)
CPPFLAGS				:=	$(CPPFLAGS_INCLUDE) $(CPPFLAGS_OPTIMIZATION) $(CPPFLAGS_OTHER)

#-------------------------------------------------------------------------------
# targets

# mark phony targets
.PHONY: all rebuild install clean debug

# default target
all: libwrap.a install

# build target
# build: libwrap.a

# rebuild target
rebuild:
	@echo rebuilding library
	@make --no-print-dir clean
	@make --no-print-dir libwrap.a

# install target
install:
	@cp -vrf \
		$(DIRS_LIB)/libwrap.a \
		$(DEVKITPRO)/libogc/lib/wii/libwrap.a
	@cp -vrf \
		include \
		../libwraptest/lib/local/
	@rm -vrf \
		../libwraptest/lib/local/include/wrapinclude.hpp \
		$(addprefix ../libwraptest/lib/local/include/,$(OBJFILES_EXCLUDE))

# clean target
clean:
	@echo cleaning...
ifeq ($(DIRS_BUILD),)
	$(error uh-oh! your DIRS_BUILD variable is not set! \
	give this variable a value to avoid deleting the root directory)
else ifeq ($(DIRS_LIB),)
	$(error uh-oh! your DIRS_LIB variable is not set! \
	@echo give this variable a value to avoid deleting the root directory)
else
	@rm -vrf \
		$(DIRS_BUILD)/* \
		$(DIRS_LIB)/*
	@echo clean successful
endif

# actual debug target
debug:
	@echo debug build target
	@echo
	@echo CURDIR: $(CURDIR)
	@echo SRCFILES: $(SRCFILES)
	@echo OBJFILES: $(OBJFILES)
	@echo OBJFILES_FINAL: $(OBJFILES_FINAL)
	@echo VPATH: $(VPATH)

#-------------------------------------------------------------------------------
# generic (header+source)->object->archive rules

%.o: %.cpp %.hpp # %_td.hpp
	@echo [CXX] $< =\> $@
	@$(CXX) \
		-c $(DIRS_SOURCE)/$(<F) \
		-o $(DIRS_BUILD)/$(@F) \
		   $(CXXFLAGS) \
		   $(CPPFLAGS)

libwrap.a: $(OBJFILES_FINAL)
	@echo [AR] $@
	@$(AR) \
		-rvlsf \
		$(DIRS_LIB)/$@ \
		$(addprefix $(DIRS_BUILD)/,$(OBJFILES_FINAL))
	@echo done building archive