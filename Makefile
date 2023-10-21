all: create_dirs 
	$(MAKE) -C libcrt -j$(shell nproc) all install 
	$(MAKE) -C libcrt_helper -j$(shell nproc) all install
	$(MAKE) -C dietlibc -j$(shell nproc) all install
	$(MAKE) -C libm -j$(shell nproc) all install
	$(MAKE) -C libucsupc++ -j$(shell nproc) all install
	$(MAKE) -C libuclibc++ -j$(shell nproc) all install
	$(MAKE) -C libz -j$(shell nproc) all install
	$(MAKE) -C libjpeg -j$(shell nproc) all install
	$(MAKE) -C libpng -j$(shell nproc) all install
	$(MAKE) -C libft -j$(shell nproc) all install

create_dirs:
	mkdir -p lib/NSG lib/SG lib/ELKA

clean:
	$(MAKE) -C libcrt clean
	$(MAKE) -C libcrt_helper clean
	$(MAKE) -C dietlibc clean
	$(MAKE) -C libm clean
	$(MAKE) -C libucsupc++ clean
	$(MAKE) -C libuclibc++ clean
	$(MAKE) -C libz clean
	$(MAKE) -C libjpeg clean
	$(MAKE) -C libpng clean
	$(MAKE) -C libsigc++ clean
	$(MAKE) -C libft clean

libs_release:
	tools/lib-pkg.sh

.PHONY: all clean
