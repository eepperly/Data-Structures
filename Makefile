CXX=g++
flags=-std=c++11

all: test

test: list.o test.cpp
	${CXX} ${flags} list.o test.cpp -o test

list.o : list.cpp list.h
	${CXX} ${flags} -c list.cpp

clean:
	rm -f test *.o *~
