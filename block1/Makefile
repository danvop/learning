all: makehole printdir1 printdir2 printenv testlocks
makehole:
	gcc makehole.c -o makehole
printdir1:
	gcc printdir1.c -o printdir1
printdir2:
	gcc printdir2.c -o printdir2
printenv:
	gcc printenv.c -o printenv
testlocks:
	gcc testlocks.c -o testlocks
install:
	cp makehole ~/bin
	cp printdir1 ~/bin
	cp printdir2 ~/bin
	cp printenv ~/bin
	cp testlocks ~/bin
clean:
	 rm -f *.o   
	 rm -f makehole printdir1 printdir2 printenv testlocks
	 rm -f *~
