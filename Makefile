#-------------------------------------------------------------------------------
# built-in targets

# clear default suffixes and implicit rules
.SUFFIXES:

# define all files as secondary files, preventing deletion by make
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
DIRS_TESTPROJECT		:=	cpptest

# build list of source files by extension
SRCFILES_C				:=	$(foreach dir,$(DIRS_SOURCE),$(notdir $(wildcard $(dir)/*.c)))
SRCFILES_CPP			:=	$(foreach dir,$(DIRS_SOURCE),$(notdir $(wildcard $(dir)/*.cpp)))
SRCFILES				:=	$(SRCFILES_C) $(SRCFILES_CPP)

# build list of object files by extension
OBJFILES_C				:=	$(SRCFILES_C:.c=.o)
OBJFILES_CPP			:=	$(SRCFILES_CPP:.cpp=.o)
OBJFILES				:=	$(OBJFILES_C) $(OBJFILES_CPP)

OBJFILES_INPROGRESS		:=
OBJFILES_EXCLUDE		:=
OBJFILES_FINAL			:=	$(filter-out \
								$(addsuffix \
									.o,\
									$(OBJFILES_EXCLUDE) \
									$(OBJFILES_INPROGRESS)\
								),\
								$(OBJFILES)\
							)

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
							) # just in case DIRS_INCLUDE is more than one folder

#-------------------------------------------------------------------------------
# compiler and archiver + flags

# compiler and archiver
CC						:=	$(DEVKITPPC)/bin/$(PREFIX)gcc.exe
CXX						:=	$(DEVKITPPC)/bin/$(PREFIX)g++.exe
AR						:=	$(DEVKITPPC)/bin/$(PREFIX)ar.exe

# C/C++ source flags
CFLAGS_WARNINGS_ENABLE	:=	all extra
CFLAGS_WARNINGS_DISABLE	:=	comment cpp uninitialized
CFLAGS_WARNINGS			:=	$(addprefix \
								-W,\
								$(CFLAGS_WARNINGS_ENABLE) \
								$(addprefix \
									no-,\
									$(CFLAGS_WARNINGS_DISABLE)\
								)\
							)
CFLAGS_DEBUG			:=	-save-temps

# C-specific source flags
# CCFLAGS_STANDARDS		:=	-std=c17

# C++-specific source flags
CXXFLAGS_STANDARDS		:=	-std=c++17

# C/C++ source preprocessor flags
CPPFLAGS_INCLUDE		:=	$(addprefix -I,$(INCLUDE_LOCAL)) \
							$(addprefix -I,$(INCLUDE_SYSTEM))
CPPFLAGS_OPTIMIZATION	:=	-O2
CPPFLAGS_OTHER			:=	-ftabstop=4

# Final flags
CFLAGS					:=	$(CFLAGS_WARNINGS) $(CFLAGS_DEBUG)
CCFLAGS					:=	$(CCFLAGS_STANDARDS) $(CFLAGS)
CXXFLAGS				:=	$(CXXFLAGS_STANDARDS) $(CFLAGS)
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
	@echo
	@make --no-p clean
	@echo
	@make --no-p libwrap.a

# install target
install:
	@cp -vrf \
		$(DIRS_LIB)/libwrap.a \
		$(DEVKITPRO)/libogc/lib/wii/libwrap.a
	@cp -vrf \
		include \
		../$(DIRS_TESTPROJECT)/lib/local/
	@rm -vrf \
		../$(DIRS_TESTPROJECT)/lib/local/include/wrapinclude.hpp \
		$(addprefix ../$(DIRS_TESTPROJECT)/lib/local/include/,$(OBJFILES_EXCLUDE))

# clean target
clean:
	@echo cleaning...
ifeq ($(DIRS_BUILD),)
	$(error uh-oh! your DIRS_BUILD variable is not set! \
	give this variable a value to avoid deleting the root directory)
else ifeq ($(DIRS_LIB),)
	$(error uh-oh! your DIRS_LIB variable is not set! \
	give this variable a value to avoid deleting the root directory)
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
	@echo CFLAGS_WARNINGS: $(CFLAGS_WARNINGS)

#-------------------------------------------------------------------------------
# generic (header+source)->object->archive rules

# C source files to object files
%.o: %.c # %.h # %_td.hpp
	@echo [CC] $< =\> $@
	@$(CC) \
		-c $(DIRS_SOURCE)/$(<F) \
		-o $(DIRS_BUILD)/$(@F) \
		   $(CCFLAGS) \
		   $(CPPFLAGS)

# C++ source files to object files
%.o: %.cpp %.hpp # %_td.hpp
	@echo [CXX] $< =\> $@
	@$(CXX) \
		-c $(DIRS_SOURCE)/$(<F) \
		-o $(DIRS_BUILD)/$(@F) \
		   $(CXXFLAGS) \
		   $(CPPFLAGS)

# Object files to library archive
libwrap.a: $(OBJFILES_FINAL)
	@echo [AR] $@
	@$(AR) \
		-rvlfs \
		$(DIRS_LIB)/$@ \
		$(addprefix $(DIRS_BUILD)/,$(OBJFILES_FINAL))
	@echo done building archive