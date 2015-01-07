all: run nozombies system 
run:
	gcc run.c -o run
nozombies:
	gcc nozombies.c -o nozombies
system:
	gcc system.c -o system
install:
	cp run ~/bin
	cp nozombies ~/bin
	cp system ~/bin
clean:
	 rm -f *.o   
	 rm -f run nozombies system
	 rm -f *~
