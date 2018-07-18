shape_source = Sources/Rectangle.cpp Sources/Line.cpp Sources/Ellipse.cpp Sources/Circle.cpp
shape = Rectangle.o Line.o Ellipse.o Circle.o

all: shapes

shapes: lib_shapes.a
	g++ -g -o shapes test_shapes.cpp lib_shapes.a

lib_shapes.a:
	g++ -c $(shape_source)
	ar rcs lib_shapes.a $(shape)
	rm -rf *.o

clean:
	rm -rf *.a shapes