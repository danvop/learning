#include <stdio.h>

#define FIFO_NAME "./fifofile"

int main ()
{
  FILE * f;
  char ch;
  f = fopen(FIFO_NAME, "r");
  do
  {
    ch = fgetc(f);
    putchar(ch);
  } while (ch != 'q');
  fclose(f);
  unlink(FIFO_NAME);
  return 0;
}
