HEADERS		= header.h

C_SRCS		= is_prime.cpp main.cpp 

C_OBJS		= is_prime.o main.o

OBJS		= ${C_OBJS}

EXE		= output


GCC		= g++

GCC_FLAGS	= -g -O3 -lpthread -c -Wall -std=c++11
LD_FLAGS	= -g -lpthread -Wall

output:main.o
	g++ main.cpp -std=c++11 -o output -lpthread

.cpp.o:
	
	$(GCC) $(GCC_FLAGS) $<

	

${C_OBJS}:      ${HEADERS}


clean:
	
	rm -f *.o $(EXE) *.ln core a.out
	

new:
	make clean
	make

