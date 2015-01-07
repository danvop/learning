#include <stdio.h>

#define BUF_SIZE 0x100

int main(int argc, char * argv[])
{
  char buf[BUF_SIZE];
  int len, i;
  FILE * f; 
  f = fopen("/proc/self/environ", "r");
  while((len = fread(buf, 1, BUF_SIZE-1, f)) > 0)
  {
    for (i = 0; i < len; i++) if (buf[i]==0) buf[i] = 10;
    buf[len] = 0;
    printf("%s", buf);
  }
  fclose(f);
  return 0;
}

