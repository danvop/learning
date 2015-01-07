all: sigdemo siglog swdemo 
sigdemo:
	gcc sigdemo.c -o sigdemo
siglog:
	gcc siglog.c -o siglog
swdemo:
	gcc swdemo.c -o swdemo
install:
	cp sigdemo ~/bin
	cp siglog ~/bin
	cp swdemo ~/bin
clean:
	 rm -f *.o   
	 rm -f sigdemo siglog swdemo
	 rm -f *~
