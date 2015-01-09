all: exittest exittest2 threads2 mutex1 mutex2 mutex3 
exittest: 
	gcc exittest.c -D_REENTERANT -o exittest  -lpthread
	strip exittest
exittest2: 
	gcc exittest2.c -D_REENTERANT -o exittest2  -lpthread
	strip exittest2
threads2: 
	gcc threads2.c -D_REENTERANT -o threads2  -lpthread
	strip threads2
mutex1: 
	gcc mutex1.c -D_REENTERANT -o mutex1  -lpthread -lrt
	strip mutex1
mutex2: 
	gcc mutex2.c -D_REENTERANT -o mutex2  -lpthread -lrt
	strip mutex2
mutex3: 
	gcc mutex3.c -D_REENTERANT -o mutex3  -lpthread -lrt
	strip mutex3
install:
	cp exittest ~/bin
	cp exittest2 ~/bin
	cp threads2 ~/bin
	cp mutex1 ~/bin
	cp mutex2 ~/bin
	cp mutex3 ~/bin
clean:
	rm -f *.o   
	rm -f exittest exittest2 threads2 mutex1 mutex2 mutex3
	rm -f *~

