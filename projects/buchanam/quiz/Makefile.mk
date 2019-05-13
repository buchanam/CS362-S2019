CFLAGS= -Wall -fpic -coverage -lm -std=c99

test: testme.c 
    gcc -o test1 testme.c $(CFLAGS)
    gcov testme.c