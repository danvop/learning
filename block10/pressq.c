#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

int main (int argc, char ** argv)
{
  struct termios oldsettings, newsettings;
  tcgetattr(fileno(stdin), &oldsettings);
  newsettings = oldsettings;
  newsettings.c_lflag &= ~(ECHO|ICANON|ISIG);
  newsettings.c_cc[VMIN] = 0;
  newsettings.c_cc[VTIME] = 0;
  tcsetattr(fileno(stdin), TCSANOW, &newsettings);
  while(getchar() != 'q') {
    sleep(1);
    printf("press [q] to quit\n");
  }
  tcsetattr(fileno(stdin), TCSANOW, &oldsettings);
  return EXIT_SUCCESS;
} 
