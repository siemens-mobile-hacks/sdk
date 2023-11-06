# C
PROJECTS += libcrt libcrt_helper dietlibc libm

# C++
PROJECTS += libc++ libuc++ libsupc++

# Other libs
PROJECTS += libz libjpeg libpng libsigc++ libft libft_server

all: create_dirs
	@for _PROJECT in $(PROJECTS); do \
		$(MAKE) -C $$_PROJECT all install  ; \
	done

create_dirs:
	mkdir -p lib/NSG lib/SG lib/ELKA

clean:
	@for _PROJECT in $(PROJECTS); do \
		$(MAKE) -C $$_PROJECT clean  ; \
	done

libs_release:
	tools/lib-pkg.sh

.PHONY: all clean
