#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#define FILE_LENGTH 0x100
int main (int argc, char* const argv[])
{
	int fd;
	void* file_memory;
	/* Открыть файл. */
	fd = open (argv[1], O_RDWR, S_IRUSR | S_IWUSR);
	/* Отобразить файл в память.  */
	file_memory = mmap (0, FILE_LENGTH, PROT_READ | PROT_WRITE,MAP_SHARED, fd, 0);
	printf ("%s\n", (char*) file_memory);
	/* Освобождение памяти. */ 
	munmap (file_memory, FILE_LENGTH);
        close (fd);
	return 0;
}

