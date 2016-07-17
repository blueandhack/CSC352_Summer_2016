.PHONY : all clean
all : scores
scores : player.o scores.o
	gcc -Wall player.o scores.o -o scores
player.o : player.h player.c
	gcc -Wall -c player.c
scores.o : scores.c player.h
	gcc -Wall -c scores.c
clean :
	rm -f *.o scores
