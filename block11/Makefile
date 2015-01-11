all: mmap-write mmap-read 
mmap-write:
	gcc mmap-write.c -o mmap-write
mmap-read:
	gcc mmap-read.c -o mmap-read
install:
	cp mmap-write ~/bin
	cp mmap-read ~/bin
clean:
	 rm -f *.o   
	 rm -f mmap-write mmap-read
	 rm -f *~

