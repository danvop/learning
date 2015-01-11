#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main (int argc, char ** argv)
{
  int fd_in, fd_out;
  char * nr_message = "Enter your name, please\n";
  char buf[255];
  fd_in = open("/dev/tty", O_RDONLY);
  fd_out = open("/dev/tty", O_WRONLY);
  write(fd_out, nr_message, strlen(nr_message));
  read(fd_in, buf, 255);
  printf("Your name is %s\n", buf);
  return EXIT_SUCCESS;
} 
