FLAGS = -L/opt/gtest/lib -lgtest -lgtest_main -lpthread -I/opt/gtest/include

all: list

list:
	g++ -c Sources/List.cpp Sources/ForwardIterator.cpp Sources/Exception.cpp Sources/ReverseIterator.cpp
	g++ -g $(FLAGS) -o list test_list.cpp List.o ForwardIterator.o Exception.o ReverseIterator.o

clean:
	rm -rf *.o list