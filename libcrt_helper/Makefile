.DEFAULT_GOAL := all

.DEFAULT:
	$(MAKE) -C $(CURDIR) -f lib.mk LIBCRT_STUBS=0 $@
	$(MAKE) -C $(CURDIR) -f lib.mk LIBCRT_STUBS=1 $@
