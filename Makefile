all: test 
test:
	gcc test.c -o test -g
clean:
	 rm -f *.o   
	 rm -f test 
	 rm -f *~

