#-------------------------------------------------------------------------------
# clear defaults
.SUFFIXES:
.SECONDARY:

# mark phony targets
.PHONY: all load clean debug

#-------------------------------------------------------------------------------
# directories and files

# sdk directories (environment)
export DEVKITPRO	:= /home/muffin/Desktop/code/sdk/devkitpro
export DEVKITPPC	:= $(DEVKITPRO)/devkitPPC

# file prefix (environment)
export PREFIX		:= powerpc-eabi-

# directories
DIRS_SOURCE			:= source
DIRS_BUILD			:= build
DIRS_LIB			:= lib

# build list of source files by extension
SRCFILES_C			:= $(foreach dir,$(DIRS_SOURCE),$(notdir $(wildcard $(CURDIR)/$(dir)/*.c)))
SRCFILES_CPP		:= $(foreach dir,$(DIRS_SOURCE),$(notdir $(wildcard $(CURDIR)/$(dir)/*.cpp)))
SRCFILES			:= $(SRCFILES_C) $(SRCFILES_CPP)

# build list of object files by extension
OBJFILES_C			:= $(SRCFILES_C:.c=.o)
OBJFILES_CPP		:= $(SRCFILES_CPP:.cpp=.o)
OBJFILES			:= $(OBJFILES_C) $(OBJFILES_CPP)

OBJFILES_NONLIB		:= test.o
OBJFILES_LIB		:= $(foreach srcf,$(OBJFILES_NONLIB),$(patsubst $(srcf),,$(OBJFILES)))

INCLUDE				:= includes $(DEVKITPRO)/libogc/include

LD_LIBDIRS			:= ./$(DIRS_LIB) $(DEVKITPRO)/libogc
LD_LIBS				:= wrap ogc m

#-------------------------------------------------------------------------------
# compiler and archiver + options
CC					:= $(DEVKITPPC)/bin/$(PREFIX)gcc.exe
CXX					:= $(DEVKITPPC)/bin/$(PREFIX)g++.exe
AR					:= $(DEVKITPPC)/bin/$(PREFIX)ar.exe

CFLAGS_STANDARDS	:= -std=c++17
CFLAGS_WARNINGS		:= -Wall -Wextra -Wno-comment -Wno-cpp
CFLAGS_OPTIMIZATION	:= -O2

FLAGS_INCLUDE		:= $(addprefix -I,$(INCLUDE))
LDFLAGS_LIBDIRS		:= $(addprefix -L,$(LD_LIBDIRS))
LDFLAGS_LIBS		:= $(addprefix -l,$(LD_LIBS))

CFLAGS				:= $(CFLAGS_STANDARDS) $(CFLAGS_WARNINGS) $(CFLAGS_OPTIMIZATION) $(FLAGS_INCLUDE)
CXXFLAGS			:= $(CFLAGS)
CPPFLAGS			:=
LDFLAGS				:= $(FLAGS_INCLUDE) $(LDFLAGS_LIBDIRS) $(LDFLAGS_LIBS)

#-------------------------------------------------------------------------------
# targets

# default target
all:
	@make --no-print-dir libwrap.a
	@echo
	@make --no-print-dir load

# load target
load:
	@cp -vf $(DIRS_LIB)/libwrap.a $(DEVKITPRO)/libogc/lib/wii/libwrap.a
	@rm -vrf ../libwraptest/lib/local/include/*
	@cp -vr includes/* ../libwraptest/lib/local/include/
	@rm -vf ../libwraptest/lib/local/include/wrapinclude.hpp

# clean target
clean:
	@echo cleaning...
	@rm -f $(DIRS_BUILD)/*
	@rm -f $(DIRS_LIB)/*
	@echo clean successful

# actual debug target
debug:
	@echo debug build target
	@echo CURDIR: $(CURDIR)
	@echo SRCFILES: $(SRCFILES)
	@echo OBJFILES: $(OBJFILES)
	@echo OBJFILES_LIB: $(OBJFILES_LIB)
	@echo $(addprefix $(DIRS_BUILD)/,$(OBJFILES_LIB))

#-------------------------------------------------------------------------------
# generic source-to-object rules
%.o: %.cpp
	@echo compiling C++ file $@
	@$(CXX) -c $(DIRS_SOURCE)/$< -o $(DIRS_BUILD)/$@ $(CPPFLAGS) $(CXXFLAGS)

%.c:
	@true
%.cpp:
	@true

#-------------------------------------------------------------------------------
# explicit rules
test.elf: test.o
	@$(LD) $(OBJFILES) -o $@ $(LDFLAGS)

libwrap.a: $(OBJFILES)
	@echo building static library archive $@
	@$(AR) -rvlsf $(DIRS_LIB)/libwrap.a $(addprefix $(DIRS_BUILD)/,$(OBJFILES_LIB))
	@echo done building archive

#-------------------------------------------------------------------------------
# list of implicit rules

# C: n.o is made automatically from n.c with $(CC) -c $(CPPFLAGS) $(CFLAGS)
# C++: n.o is made automatically from n.cc or n.cpp with $(CXX) -c $(CPPFLAGS) $(CXXFLAGS)
# Linking a single object file: n is made automatically from n.o with $(CC) $(LDFLAGS) n.o $(LOADLIBES) $(LDLIBS)
