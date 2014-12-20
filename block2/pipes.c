#include <stdio.h>
#include <string.h>
#include <sys/types.h>

int main (int argc, char * argv[])
{
  int pipedes[2];
  pid_t pid;
  pipe(pipedes);
  pid = fork();
  if ( pid > 0 )  
  {  
    char  *str = "String passed via pipe\n";
    close(pipedes[0]);
    write(pipedes[1], (void *) str, strlen(str) + 1); 
    close(pipedes[1]);
  }  
  else
  {
    char buf[1024];
    int len;
    close(pipedes[1]);
    while ((len = read(pipedes[0], buf, 1024)) != 0)
    write(2, buf, len); 
    close(pipedes[0]);	
  }
  return 0;
}
