g:
	java -jar ../antlr-3.4-complete.jar ./ExprCppTree.g

all: main.cpp
	java -jar ../antlr-3.4-complete.jar ./ExprCppTree.g
	g++ -g -Wall -O0 *.cpp *.c  ./src/*.cpp ../libantlr3c-3.4/.libs/libantlr3c.a -std=c++11 -Wunused-function -o test -I. -I ../libantlr3c-3.4/include/
	./test data

