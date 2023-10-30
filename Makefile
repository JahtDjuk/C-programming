# file: GNUMakefile
#
# Note that this make file uses "-g" to compile and link "debug".
#

# define a target for the application
#
all: myprog.exe

# define a target to link the application
#
myprog.exe: myprog.o myfuncts_00.o
	g++ -g -lm myprog.o myfuncts_00.o -o myprog.exe

# define targets to compile the source code
#
myprog.o: myprog.cc myprog.h Makefile
	g++ -g -c myprog.cc -o myprog.o

myfuncts_00.o: myfuncts_00.cc myprog.h Makefile
	g++ -g -c myfuncts_00.cc -o myfuncts_00.o

# define a target to clean the directory
#
clean:
	rm -f myprog.o myfuncts_00.o myprog.exe

#
# end of file


