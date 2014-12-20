#include <stdio.h>
#include <errno.h>

#define BUF_SIZE 0x100

int main(int argc, char * argv[])
{
  FILE * f;
  FILE * o;
  int len;
  char buf[BUF_SIZE];
  if (argc != 2)
  {
     printf("использование: makelog \"<command>\"\n");
     return -1;
  }
  f = popen(argv[1], "r");
  if (f == NULL)
  {
    perror("ошибка:\n");
    return -1;
  }
  o = fopen("log.txt", "w");
  while ((len = fread(buf, 1, BUF_SIZE, f)) != 0)
  {
     write(1, buf, len);
     fwrite(buf, 1, len, o);
  }
  pclose(f);
  fclose(o);
  return 0;
} 
