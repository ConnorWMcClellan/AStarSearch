runMe: Graph.o main.o
	g++ -o runMe Graph.o main.o
	
Graph.o: Graph.cpp Graph.hpp
	g++ -c -g -Wall -ansi -pedantic -std=c++11 Graph.cpp
		
main.o: main.cpp
	g++ -c -g -Wall -ansi -pedantic -std=c++11 main.cpp