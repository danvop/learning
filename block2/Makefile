all: makelog pipes printns typeclient typeserver
makelog:
	gcc makelog.c -o makelog
pipes:
	gcc pipes.c -o pipes 
printns:
	gcc printns.c -o printns
typeclient:
	gcc typeclient.c -o typeclient 
typeserver:
	gcc typeserver.c -o typeserver
install:
	cp makelog ~/bin
	cp pipes ~/bin
	cp printns ~/bin
	cp typeclient ~/bin
	cp typeserver ~/bin
clean:
	 rm -f *.o   
	 rm -f makelog pipes printns typeclient typeserver fifofile1 fifofile2
	 rm -f *~
