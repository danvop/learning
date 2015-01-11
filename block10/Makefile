all: noredirect noredirect2 pressq psswdmode
noredirect:
	gcc noredirect.c -o noredirect
noredirect2:
	gcc noredirect2.c -o noredirect2
pressq:
	gcc pressq.c -o pressq
psswdmode:
	gcc psswdmode.c -o psswdmode
install:
	cp noredirect ~/bin
	cp noredirect2 ~/bin
	cp pressq ~/bin
	cp psswdmode ~/bin
clean:
	 rm -f *.o   
	 rm -f noredirect noredirect2 pressq psswdmode
	 rm -f *~
