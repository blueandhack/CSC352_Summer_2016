.PHONY : all clean
all : driver mru
driver : llist.o driver.o
	gcc -Wall llist.o driver.o -o driver
mru : llist.o mru.o
	gcc -Wall llist.o mru.o -o mru 
llist.o : llist.c llist.h
	gcc -Wall -c llist.c
driver.o : driver.c llist.h
	gcc -Wall -c driver.c
mru.o : mru.c llist.h
	gcc -Wall -c mru.c
clean :
	rm -f *.o driver mru
