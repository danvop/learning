all: msgdemo polymsgdemo shmemdemo semdemo
msgdemo:
	gcc msgserv.c -o msgserv
	gcc msgcli.c -o msgcli
polymsgdemo:
	gcc polymsgserv.c -o polymsgserv
	gcc polymsgcli.c -o polymsgcli
shmemdemo:
	gcc shmemserv.c -o shmemserv
	gcc shmemcli.c -o shmemcli
semdemo:
	gcc semserv.c -o semserv
	gcc semcli.c -o semcli
install:
	cp msgserv ~/bin
	cp msgcli ~/bin
	cp polymsgserv ~/bin
	cp polymsgcli ~/bin
	cp shmemserv ~/bin
	cp shmemcli ~/bin
	cp semserv ~/bin
	cp semcli ~/bin
clean:
	 rm -f *.o   
	 rm -f *serv *cli
	 rm -f *~