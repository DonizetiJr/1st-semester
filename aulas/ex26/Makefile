all:
	gcc -o test01 ./src/test01.c ./src/vaargs.c -I./include
	gcc -o test02 ./src/test02.c ./src/vaargs.c -I./include

lib:
	# so - shared object	(Linux)
	# dll- Dynamic Linked Library (Windows)
	gcc -fPIC -shared -o libvaargs.so ./src/vaargs.c

test:
	gcc -o test03 ./src/test03.c -I./include -L. -lvaargs
	export LD_LIBRARY_PATH=.
	./test03
