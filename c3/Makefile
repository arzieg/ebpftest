CC = gcc
CLANG ?= clang
CFLAGS ?= -g -O2 -Wall -Wextra -Werror -std=c17

hello.bpf.o: %o: %c
	$(CLANG) \
		-target bpf \
		-I/usr/include/linux/ \
		-I/usr/include/bpf/ \
                -I/usr/src/kernels/${shell uname -r}/tools/lib/ \
		-g \
		-O2 -c $< -o $@
hello-func.bpf.o: %o: %c
	$(CLANG) \
		-target bpf \
		-I/usr/include/linux/ \
		-I/usr/include/bpf/ \
                -I/usr/src/kernels/${shell uname -r}/tools/lib/ \
		-g \
		-O2 -c $< -o $@
hello-func2.bpf.o: %o: %c
	$(CLANG) \
		-target bpf \
		-I/usr/include/linux/ \
		-I/usr/include/bpf/ \
                -I/usr/src/kernels/${shell uname -r}/tools/lib/ \
		-g \
		-O2 -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

recursion1: recursion1.o 
	$(CC) $(CFLAGS) -o $@ $^

recursion2: recursion2.o 
	$(CC) $(CFLAGS) -o $@ $^

clean: 
	rm recursion1
	rm recursion2
	rm *.o
