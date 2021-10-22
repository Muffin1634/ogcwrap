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

OBJFILES_EXCLUDE		:=	debug
OBJFILES_FINAL			:=	$(filter-out $(foreach file,$(OBJFILES_EXCLUDE),$(file).o),$(OBJFILES))

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

FLAGS_INCLUDE			:=	$(addprefix -I,$(INCLUDE_LOCAL)) \
							$(addprefix -I,$(INCLUDE_SYSTEM))

CFLAGS_STANDARDS		:=	-std=c++17
CFLAGS_WARNINGS			:=	-Wall -Wextra -Wno-comment -Wno-cpp -Wno-uninitialized

CXXFLAGS_DEBUG			:=	-save-temps

CPPFLAGS_OPTIMIZATION	:=	-O2 -ftabstop=4

CFLAGS					:=	$(CFLAGS_STANDARDS) $(CFLAGS_WARNINGS) $(CFLAGS_OPTIMIZATION) $(FLAGS_INCLUDE)
CXXFLAGS				:=	$(CFLAGS) $(CXXFLAGS_DEBUG)
CPPFLAGS				:=	$(CPPFLAGS_OPTIMIZATION)

#-------------------------------------------------------------------------------
# targets

# mark phony targets
.PHONY: all rebuild load clean debug

# default target
all: libwrap.a load

# build target
# build: libwrap.a

# rebuild target
rebuild:
	@echo rebuilding library
	@make --no-print-dir clean
	@make --no-print-dir libwrap.a

# load target
load:
	@cp -vrf \
		$(DIRS_LIB)/libwrap.a \
		$(DEVKITPRO)/libogc/lib/wii/libwrap.a
	@rm -vrf \
		../libwraptest/lib/local/include/*
	@cp -vrf \
		include/* \
		../libwraptest/lib/local/include/
	@rm -vrf \
		../libwraptest/lib/local/include/wrapinclude.hpp \
		$(addprefix ../libwraptest/lib/local/include/,$(OBJFILES_EXCLUDE))

# clean target
clean:
	@echo cleaning...
	@rm -vrf \
		$(DIRS_BUILD)/* \
		$(DIRS_LIB)/*
	@echo clean successful

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

%.o: %.cpp %.hpp %_td.hpp
	@echo compiling C++ file $@
	@$(CXX) \
		-c $(DIRS_SOURCE)/$(notdir $<) \
		-o $(DIRS_BUILD)/$(notdir $@) \
		   $(CXXFLAGS) \
		   $(CPPFLAGS)

libwrap.a: $(OBJFILES_FINAL)
	@echo building static library archive $@
	@$(AR) \
		-rvlsf \
		$(DIRS_LIB)/$@ \
		$(addprefix $(DIRS_BUILD)/,$(OBJFILES_FINAL))
	@echo done building archive