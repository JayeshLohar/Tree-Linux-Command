all : tree clean
color.o : color.c color.h
	        gcc -Wall -c -g color.c
tree.o : tree.c tree.h
	        gcc -c -g tree.c
main.o : main.c color.c color.h tree.c tree.h
	        gcc -Wall -c -g main.c
tree : color.o tree.o main.o
	        gcc -Wall -g color.o tree.o main.o -o tree
clean :
	rm *.o