FLAGS = -L/opt/gtest/lib -lgtest -lgtest_main -lpthread -I/opt/gtest/include

all: bitarr

bitarr:
	g++ -g -c Sources/BitArray.cpp
	g++ -g $(FLAGS) -o bitarr test_bitarray.cpp BitArray.o

clean:
	rm -rf *.o bitarr