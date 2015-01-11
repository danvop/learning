#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#define FILE_LENGTH 0x100
int main (int argc, char* const argv[])
{
 int fd;
 void* file_memory;
 /* Открываем(создаем) файл, достаточно  большой, чтобы хранить нашу строку */          
 fd = open (argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
 lseek (fd, FILE_LENGTH+1, SEEK_SET);
 write (fd, "", 1);
 lseek (fd, 0, SEEK_SET);
 /* Создаем отображение в памяти. */          
 file_memory = mmap (0, FILE_LENGTH, PROT_WRITE, MAP_SHARED, fd, 0);
 /* Пишем строку в отображенную память. */     
 sprintf((char*) file_memory, "%s\n", "Hello from mmap!");
 /* Освобождаем память. */ 
 munmap (file_memory, FILE_LENGTH);
 close (fd);
 return 0;
}

