hello.bpf.o: %o: %.c
	gcc \
		-target bpf \
		-I/usr/include/$(shell uname -m)-linux-gnu \
		-g \
		-O2 -c $< -o $@
