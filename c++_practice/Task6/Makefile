FLAGS = -L/opt/gtest/lib -lgtest -lgtest_main -lpthread -I/opt/gtest/include

all: virtual

virtual:
	g++ -g -c Sources/Base.cpp
	g++ -g $(FLAGS) -o virtual test_virtual.cpp Base.o

clean:
	rm -rf *.o virtual