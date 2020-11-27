mybank: 
	gcc -Wall -c myBank.c
	ar rcs libmyBank.a myBank.o

main:
	gcc -Wall -c main.c
	gcc -Wall -g main.o libmyBank.a -o program

all:
	make mybank
	make main

clean:
	rm -f *.o *.a program
