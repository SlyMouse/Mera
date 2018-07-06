all: hello

hello: main.o test_prog.o
	g++ main.o test_prog.o -o hello

main.o: hello_w_lib.cpp
	g++ -c hello_w_lib.cpp -o main.o

test_prog.o: test_prog.cpp
	g++ -c test_prog.cpp

clean:
	rm -rf *.o hello
