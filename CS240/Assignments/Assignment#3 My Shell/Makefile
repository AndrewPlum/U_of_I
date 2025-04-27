cc = gcc
cflags = -std=c99 
tgts = msh


all:
	make msh

msh: msh.c
	$(cc) $(cflags) msh.c -o msh

clean:
	rm $(tgts)