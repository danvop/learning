#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define BUF_SIZE 0x100

int main (int argc, char * argv[])
{
  int pipedes[2];
  pid_t pid;
  pipe(pipedes);
  pid = fork();
  if ( pid > 0 )
  {
    char buf[BUF_SIZE];
    int len;
    close(pipedes[1]);
    while ((len = read(pipedes[0], buf, BUF_SIZE)) > 0)
      write(1, buf, len); 
    close(pipedes[0]);
  }
  else
  {
    close(pipedes[0]); 
    dup2(pipedes[1], 1);
    execve("/bin/netstat", NULL, NULL);
  } 
  return 0;
}				
