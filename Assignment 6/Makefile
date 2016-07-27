.PHONY : all clean
all : wf
wf : wf.o hashtable.o
	gcc -Wall wf.o hashtable.o -o wf
wf.o : hashtable.h wf.c
	gcc -Wall -c wf.c
hashtable.o : hashtable.h hashtable.c
	gcc -Wall -c hashtable.c
clean :
	rm -f *.o wf 
