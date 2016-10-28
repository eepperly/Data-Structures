CXX=g++
flags=-std=c++11

all: test

test: list.cpp list.h test.cpp
	${CXX} ${flags} test.cpp -o test

#list.o : list.cpp list.h
#	${CXX} ${flags} -c list.cpp

clean:
	rm -f test *.o *~
