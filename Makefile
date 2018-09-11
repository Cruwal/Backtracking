objects= list.c

all:
	gcc -o exe main.c $(objects) -I.
