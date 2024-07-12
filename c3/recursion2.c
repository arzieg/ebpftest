#include <stdint.h>
#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>

static uint64_t 
fib_tail(uint64_t n, uint64_t a, uint64_t b)
{
    if (n == 0)
        return a;
    if (n == 1)
        return b;

    return fib_tail( n-1, b, a+b);
}

uint64_t 
fib(uint64_t n)
{
    return fib_tail(n,1,1);
}

int
main(int argc, char *argv[]) 
{
    char *p;
    int num;

    if (argc <2)
       exit(1);

    errno = 0;
    long conv = strtol(argv[1], &p, 10);

    // Check for errors: e.g., the string does not represent an integer
    // or the integer is larger than int
    if (errno != 0 || *p != '\0' || conv > INT_MAX || conv < INT_MIN) {
        // Put here the handling of the error, like exiting the program with
        // an error message
    } else {
        // No error
        num = conv;
        printf("fibonacci %lu\n", fib(num));
    }
    return 0;
}
