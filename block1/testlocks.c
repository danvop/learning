#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char * argv[])
{
  int fd; 
  char str[64];
  memset(str, 32, 64);
  struct flock fi;
  int off;
  sprintf(str, "Запись сделана процессом %i", getpid());
  fd = open("testlocks.txt", O_RDWR|O_CREAT);
  fi.l_type = F_WRLCK;
  fi.l_whence = SEEK_SET;
  fi.l_start = 0;
  fi.l_len = 64;
  	off = 0;
  while (fcntl(fd, F_SETLK, &fi) == -1)
  {
     fcntl(fd, F_GETLK, &fi);
     printf("байты %i - %i заблокированы процессом %i\n", off, off+64, fi.l_pid);
     off += 64;
     fi.l_start = off;
  }
  lseek(fd, off, SEEK_SET);
  write(fd, str, strlen(str));
  getchar();
  fi.l_type = F_UNLCK;
  if (fcntl(fd, F_SETLK, &fi) == -1)
    printf("Ошибка разблокирования\n");
  close(fd);
} 
