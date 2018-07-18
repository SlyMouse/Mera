all: bitarr

bitarr:
	g++ -g -c Sources/BitArray.cpp
	g++ -g -o bitarr test_bitarray.cpp BitArray.o

clean:
	rm -rf *.o bitarr