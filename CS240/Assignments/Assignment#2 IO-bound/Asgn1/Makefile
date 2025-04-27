cc = gcc
cflags = -std=c99
tgts = CPU-bound.out IO-bound.out


all:
	make CPU-bound
	make IO-bound

CPU-bound: CPU-bound.c
	$(cc) $(cflags) CPU-bound.c -o CPU-bound.out

IO-bound: IO-bound.c
	$(cc) $(cflags) CPU-bound.c -o IO-bound.out

clean:
	rm $(tgts)