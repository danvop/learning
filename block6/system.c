#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[])
{
   int result;
   if (argc != 2) {
     printf("Usage: %s command\n", argv[0]);
     return EXIT_FAILURE;
   }
   printf("Starting %s...\n", argv[1]);
   result = system(argv[1]);
   switch (result) {
   case 127 :
     printf("Failed to start a shell\n");
     return EXIT_FAILURE;
   case -1 :
     printf("Unknown failure\n");
     return EXIT_FAILURE;
   default :
     printf ("Done\n");
   }
   return EXIT_SUCCESS;
}
