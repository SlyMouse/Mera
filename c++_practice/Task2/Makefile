all: symmatrix

symmatrix: symmatrix
	g++ -g -c Sources/SymmetricMatrix.cpp
	g++ -g -o symmatrix test_sym_matrix.cpp SymmetricMatrix.o

clean:
	rm -rf *.o symmatrix