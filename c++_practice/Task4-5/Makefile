all: list

list:
	g++ -c Sources/List.cpp Sources/ForwardIterator.cpp Sources/Exception.cpp Sources/ReverseIterator.cpp
	g++ -g -o list test_list.cpp List.o ForwardIterator.o Exception.o ReverseIterator.o

clean:
	rm -rf *.o list