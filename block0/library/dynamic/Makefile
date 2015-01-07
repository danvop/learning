# Makefile for World project

binary: main.o libworld.so
	gcc -o binary main.o -L. -lworld -Wl,-rpath,.

main.o: main.c
	gcc -c main.c

libworld.so: h_world.o g_world.o
	gcc -shared -o libworld.so h_world.o g_world.o

h_world.o: h_world.c
	gcc -c -fPIC h_world.c

g_world.o: g_world.c
	gcc -c -fPIC g_world.c

clean:
	rm -f *.o *.so binary
