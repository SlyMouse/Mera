FLAGS = -L/opt/gtest/lib -lgtest -lgtest_main -lpthread -I/opt/gtest/include

all: symmatrix

symmatrix: symmatrix
	g++ -g -c Sources/SymmetricMatrix.cpp
	g++ -g $(FLAGS) -o symmatrix test_sym_matrix.cpp SymmetricMatrix.o

clean:
	rm -rf *.o symmatrix