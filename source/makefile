all: LinkedList

LinkedList: LinkedList.o LinkFun.o
	g++ LinkedList.o LinkFun.o -o LinkedList

LinkedList.o: LinkedList.cpp link.h
	g++ -c LinkedList.cpp

LinkFun.o: LinkFun.cpp link.h
	g++ -c LinkFun.cpp

clean: 
	rm -rf *o LinkedList
