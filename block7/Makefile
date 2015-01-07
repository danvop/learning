all: canceltest canceltest2 threads 
canceltest:
	gcc canceltest.c -D_REENTERANT -o canceltest  -lpthread
	strip canceltest
canceltest2:
	gcc canceltest2.c -D_REENTERANT-o canceltest2  -lpthread
	strip canceltest2
threads:
	gcc threads.c -D_REENTERANT -o threads  -lpthread
	strip threads
install:
	cp canceltest ~/bin
	cp canceltest2 ~/bin
	cp threads ~/bin
clean:
	 rm -f *.o   
	 rm -f canceltest canceltest2 threads
	 rm -f *~
