#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_NAME_1 "./fifofile1" //for server write
#define FIFO_NAME_2 "./fifofile2" //for client write

int main ()
{
  FILE * fd1;
	FILE * fd2;
  char ch;
	pid_t pid;

  fd1 = fopen(FIFO_NAME_1, "r");
	fd2	= fopen(FIFO_NAME_2, "w");
	
	pid = fork();
	if (pid > 0){
		do{
			//read
    	ch = fgetc(fd1);
    	putchar(ch);
		} while (ch != 'q');
	}else{
		do{
			//write
			ch = getchar();
			fputc(ch, fd2);
			if (ch == 10) fflush(fd2);
	  	}while (ch != 'q');
		}


	fclose(fd1);
	fclose(fd2);
  unlink(FIFO_NAME_1);
	unlink(FIFO_NAME_2);
  return 0;
}
