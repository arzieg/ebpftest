
hello.bpf.o: %o: %c
	clang \
		-target bpf \
		-I/usr/include/linux/ \
		-I/usr/include/bpf/ \
                -I/usr/src/kernels/${shell uname -r}/tools/lib/ \
		-g \
		-O2 -c $< -o $@
