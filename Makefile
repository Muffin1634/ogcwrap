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
DIRS_DOXYGEN			:=	doxygen

# build list of source files by extension
SRCFILES_C				:=	$(foreach dir,$(DIRS_SOURCE),$(notdir $(wildcard $(dir)/*.c)))
SRCFILES_CPP			:=	$(foreach dir,$(DIRS_SOURCE),$(notdir $(wildcard $(dir)/*.cpp)))
SRCFILES				:=	$(SRCFILES_C) $(SRCFILES_CPP)

# build list of object files by extension
OBJFILES_C				:=	$(SRCFILES_C:.c=.o)
OBJFILES_CPP			:=	$(SRCFILES_CPP:.cpp=.o)
OBJFILES				:=	$(OBJFILES_C) $(OBJFILES_CPP)

OBJFILES_EXCLUDE		:=	gx
OBJFILES_FINAL			:=	$(filter-out $(OBJFILES_EXCLUDE).o,$(OBJFILES))

INCLUDE_LOCAL			:=	$(DIRS_INCLUDE)
INCLUDE_SYSTEM			:=	$(DEVKITPRO)/libogc/include

LD_LIBDIRS				:=	$(DIRS_LIB) $(DEVKITPRO)/libogc
LD_LIBS					:=	wrap ogc m

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

LDFLAGS_LIBDIRS			:=	$(addprefix -L,$(LD_LIBDIRS))
LDFLAGS_LIBS			:=	$(addprefix -l,$(LD_LIBS))

CFLAGS					:=	$(CFLAGS_STANDARDS) $(CFLAGS_WARNINGS) $(CFLAGS_OPTIMIZATION) $(FLAGS_INCLUDE)
CXXFLAGS				:=	$(CFLAGS) $(CXXFLAGS_DEBUG)
CPPFLAGS				:=	$(CPPFLAGS_OPTIMIZATION)
LDFLAGS					:=	$(FLAGS_INCLUDE) $(LDFLAGS_LIBDIRS) $(LDFLAGS_LIBS)

#-------------------------------------------------------------------------------
# targets

# mark phony targets
.PHONY: all deploy load clean debug doxygen

# default target
all: deploy doxygen

# deploy target
deploy: libwrap.a load

# build target

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
		../libwraptest/lib/local/include/debug \
		../libwraptest/lib/local/include/gx

# clean target
clean:
	@echo cleaning...
	@rm -vrf $(DIRS_DOXYGEN)/doxygen/*
	@echo clean successful

# actual debug target
debug:
	@echo debug build target
	@echo CURDIR: $(CURDIR)
	@echo SRCFILES: $(SRCFILES)
	@echo OBJFILES: $(OBJFILES)
	@echo OBJFILES_FINAL: $(OBJFILES_FINAL)
	@echo VPATH: $(VPATH)

# doxygen target
doxygen:
	@echo Compiling doxygen
	@cd doxygen/src && doxygen ../../Doxyfile
	@cp -vrf doxygen/doxygen/html/* ../../../docs/muffin/libwrap/

#-------------------------------------------------------------------------------
# generic (header+source)->object->archive rules

%.o: %.cpp %.hpp
	@echo compiling C++ file $@
	@$(CXX) \
		-c $(DIRS_SOURCE)/$(notdir $<) \
		-o $(DIRS_BUILD)/$(notdir $@) \
		   $(CPPFLAGS) \
		   $(CXXFLAGS)

libwrap.a: $(OBJFILES_FINAL)
	@echo building static library archive $@
	@$(AR) \
		-rvlsf \
		$(DIRS_LIB)/$@ \
		$(addprefix $(DIRS_BUILD)/,$(OBJFILES_FINAL))
	@echo done building archive

#-------------------------------------------------------------------------------
# explicit rules

# .PHONY: wrapinclude.hpp

# wrapinclude.hpp:
# 	@$(CXX) \
# 		-E include/$(notdir $@)
# 		-o include/$(notdir $@.gch)
# 		   $(CFLAGS) \
# 		   $(CPPFLAGS)

# wiiuse.o: wiiuse.cpp # act as .ii with .gch
# 	@echo compiling C++ file $@
# 	@$(CXX) -v \
# 		-c $(DIRS_SOURCE)/$(notdir $<) \
# 		-o $(DIRS_BUILD)/$(notdir $@) \
# 		   $(CXXFLAGS) -Winvalid-pch \
# 		   $(CPPFLAGS) -fdirectives-only

#-------------------------------------------------------------------------------
# list of implicit rules

# C: n.o is made automatically from n.c with $(CC) -c $(CPPFLAGS) $(CFLAGS)
# C++: n.o is made automatically from n.cc or n.cpp with $(CXX) -c $(CPPFLAGS) $(CXXFLAGS)
# Linking a single object file: n is made automatically from n.o with $(CC) $(LDFLAGS) n.o $(LOADLIBES) $(LDLIBS)