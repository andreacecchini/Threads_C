C_FLAGS = -ansi -Wall -Wpedantic -Werror
C_SYMBOLS = -D_THREAD_SAFE -D_POSIX_C_SOURCE
L_FLAGS = -lpthread

all: main.exe

main.exe: main.o
	gcc -o main.exe main.o ${L_FLAGS}

main.o: main.c
	gcc -c ${C_FLAGS} -o main.o main.c ${C_SYMBOLS} 

clean: 
	rm *.exe *.o

run:
	./main.exe