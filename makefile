default:
	gcc -o Q1 Q1.c
	./Q1

preprocessing:
	gcc -E Q1.c -o Q1.i
	code Q1.i

compilation:
	gcc -S Q1.i -o Q1.s	
	code Q1.s 

assemble:
	gcc -c Q1.c -o Q1.o
	hexdump Q1.o

linking:
	gcc Q1.c -o Q1
	./Q1