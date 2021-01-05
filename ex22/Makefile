CFLAGS=-Wall	-g	-DNDEBUG

all:
	cc	-c -o ex22.o ex22.c
	cc	 ex22_main.c ex22.o -o ex22_main.o
clean:
	-rm	-f	ex22
	-rm -f	ex22_main
#-Wall: enable all warnings
#-g: add debug symbols(inorder to use gdb symbols)
#-o: name of the of the output files to create
#-c: do not link
