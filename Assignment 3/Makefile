.PHONY: all clean

all : part editor sim

part : part.c
	gcc -Wall part.c -o part

editor : editor.c
	gcc -Wall editor.c -o editor

sim : sim.c
	gcc -Wall sim.c -o sim

clean :
	rm -f part editor sim
