#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main (int argc, char ** argv)
{
  char * errstr = "I will not redirect my output!\n";
  if (!isatty(fileno(stdout))) {
    write(2, errstr, strlen(errstr));
    return EXIT_FAILURE;
  }
  printf ("Hello!\n");
  return EXIT_SUCCESS;
} 
