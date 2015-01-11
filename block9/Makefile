all: aahzd  
aahzd:
	gcc aahzd.c -D_REENTERANT -o aahzd
	strip aahzd
install:
	cp aahzd ~/bin
clean:
	 rm -f *.o   
	 rm -f aahzd
	 rm -f *~
