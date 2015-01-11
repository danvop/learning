#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <termios.h>

#define BUF_SIZE 15

int main (int argc, char ** argv)
{
  struct termios oldsettings, newsettings;
  char password[BUF_SIZE+1];
  int len;
  sigset_t newsigset, oldsigset;
  sigemptyset(&newsigset);
  sigaddset(&newsigset, SIGINT);
  sigaddset(&newsigset, SIGTSTP);
  sigprocmask(SIG_BLOCK, &newsigset, &oldsigset);
  tcgetattr(fileno(stdin), &oldsettings);
  newsettings = oldsettings;
  newsettings.c_lflag &= ~ECHO;
  tcsetattr(fileno(stdin), TCSAFLUSH, &newsettings);
  printf("Enter password and press [Enter]\n");
  len = read(fileno(stdin), password, BUF_SIZE);
  password[len] = 0;
  tcsetattr(fileno(stdin), TCSANOW, &oldsettings);
  sigprocmask(SIG_SETMASK, &oldsigset, NULL);
  printf("Your password is %s\n", password);
  return EXIT_SUCCESS;
} 
