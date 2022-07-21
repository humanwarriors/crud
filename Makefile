all:
	clang -o main main.c create.c
	clang -c main create.c main.c
clean:
	rm -rf main *.o
	rm -rf crud *.o
	rm -rf create *.o
	
