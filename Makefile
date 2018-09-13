all:
	gcc -o exe src/*.c -Iinc/

run:
	./exe
