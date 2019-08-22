#Try to detect INET if variable is not set
ifndef INET_PROJ
    ifneq ($(wildcard ../inet),)
        INET_PROJ=../../inet
    else
        $(error "Cannot find INET framework in the usual location. You have to set the PATH to INET in the INET_PROJ variable")
    endif
endif
#Try to detect CoRE4INET if variable is not set
ifndef CORE4INET_PROJ
    ifneq ($(wildcard ../CoRE4INET),)
        CORE4INET_PROJ=../../CoRE4INET
    else
        $(error "Cannot find CoRE4INET framework in the usual location. You have to set the PATH to INET in the INET_PROJ variable")
    endif
endif
#Try to detect INET if variable is not set
ifndef OPENFLOW_PROJ
    ifneq ($(wildcard ../OpenFlow),)
        OPENFLOW_PROJ=../../OpenFlow
    else
        $(error "Cannot find OpenFlow framework in the usual location. You have to set the PATH to OpenFlow in the OPENFLOW_PROJ variable")
    endif
endif

all: checkmakefiles
	cd src && $(MAKE)

clean: checkmakefiles
	cd src && $(MAKE) clean

cleanall: checkmakefiles
	cd src && $(MAKE) MODE=release clean
	cd src && $(MAKE) MODE=debug clean
	rm -f src/Makefile

MAKEMAKE_OPTIONS := --make-so -f --deep --no-deep-includes -I. -I$(INET_PROJ)/src/ -I$(CORE4INET_PROJ)/src/ -I$(OPENFLOW_PROJ)/src/ -L$(INET_PROJ)/src -L$(CORE4INET_PROJ)/src -L$(OPENFLOW_PROJ)/src -lCoRE4INET -lINET -lOpenFlow -KINET_PROJ=$(INET_PROJ) -KCORE4INET_PROJ=$(CORE4INET_PROJ) -KOPENFLOW_PROJ=$(OPENFLOW_PROJ)

makefiles:
	cd src && opp_makemake $(MAKEMAKE_OPTIONS)

checkmakefiles:
	@if [ ! -f src/Makefile ]; then \
	echo; \
	echo '======================================================================='; \
	echo 'src/Makefile does not exist. Please use "make makefiles" to generate it!'; \
	echo '======================================================================='; \
	echo; \
	exit 1; \
	fi
	

doxy:
	doxygen doxy.cfg
	
