all: mysort

mysort: my_lib.a
	gcc -g -o mysort mysort.c my_lib.a

ptr_task: 
	gcc -lm -g -o ptr_task ptr_task.c

main: my_lib.a
	gcc -g -o main test_all.c my_lib.a

sort_test: my_lib.a
	gcc -g -o sort_test sort_test.c my_lib.a

my_lib.a: str_lib.o bit_lib.o sort_lib.o
	ar rcs my_lib.a str_lib.o bit_lib.o sort_lib.o
	rm -rf *.o

str_lib.o:  Sources/str_lib.c
	gcc -c  Sources/str_lib.c

bit_lib.o:  Sources/bit_lib.c
	gcc -c  Sources/bit_lib.c

sort_lib.o: Sources/sort_lib.c
	gcc -c  Sources/sort_lib.c

clean:
	rm my_lib.a main sort_test ptr_task mysort
