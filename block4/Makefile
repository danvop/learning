all: fsdemo netdemo sockpairdemo
fsdemo:
	gcc fsserver.c -o fsserver -g
	gcc fsclient.c -o fsclient -g
netdemo:
	gcc netserver.c -o netserver
	gcc netclient.c -o netclient
sockpairdemo:
	gcc sockpair.c -o sockpair
install:
	cp fsserver ~/bin
	cp fsclient ~/bin
	cp netserver ~/bin
	cp netclient ~/bin
	cp sockpair ~/bin
clean:
	 rm -f *.o   
	 rm -f *server *client sockpair
	 rm -f *~
