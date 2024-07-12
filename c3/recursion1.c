#include <stdint.h>
#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>

uint64_t fib(uint64_t n)
{
    if ( n == 0 || n == 1)
        return 1;
    return fib(n-1)+fib(n-2);
}

int
main(int argc, char *argv[]) 
{
    char *p;
    int num;

    if (argc <2)
      exit (1);

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
