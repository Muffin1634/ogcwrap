#-------------------------------------------------------------------------------
# clear defaults
.SUFFIXES:
.SECONDARY:

#-------------------------------------------------------------------------------
# directories and files

DIRS_DOXYGEN			:=	doxygen

#-------------------------------------------------------------------------------
# targets

# mark phony targets
.PHONY: all doxygen clean debug

# default target
all: doxygen

# doxygen target
doxygen:
ifeq ($(DIRS_DOXYGEN),)
	$(error uh-oh! your DIRS_DOXYGEN variable is not set! \
	give this variable a value to avoid deleting the root directory)
else
	@echo Compiling doxygen
	@cd $(DIRS_DOXYGEN)/src && doxygen ../../Doxyfile
	@cp -vrf $(DIRS_DOXYGEN)/doxygen/html/* ../../../docs/muffin/libwrap/
endif

# clean target
clean:
	@echo cleaning...
	@rm -vrf $(DIRS_DOXYGEN)/doxygen/*
	@echo clean successful

# actual debug target
debug:
	@echo debug build target
	@echo
	@echo CURDIR: $(CURDIR)
	@echo DIRS_DOXYGEN: $(DIRS_DOXYGEN)
	@echo VPATH: $(VPATH)
