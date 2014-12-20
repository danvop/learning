#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define FIFO_NAME_1 "./fifofile1" //for server write 
#define FIFO_NAME_2 "./fifofile2" //for client write


int main(int argc, char * argv[])
{
  FILE * fd1;
	FILE * fd2;
  char ch;
	pid_t pid; //pid for forking
	char buf[1024];
	int lf = open("logfile.txt", O_WRONLY | O_CREAT| O_TRUNC, 0600);

	
	mkfifo(FIFO_NAME_1, 0600);
	mkfifo(FIFO_NAME_2, 0600);
  
	fd1 = fopen(FIFO_NAME_1, "w");
	fd2 = fopen(FIFO_NAME_2, "r");
	

  if (fd1 == NULL) 
  { 
    printf("Не удалось открыть файл fifo1 \n");
    return -1;
  }

  if (fd2 == NULL) 
  { 
    printf("Не удалось открыть файл fifo2 \n");
    return -1;
  }

	pid = fork(); //start forking
//pid > 0 for write
//child pid for read
	if (pid > 0){
	  do
  	{
		//write 
    ch = getchar();
    fputc(ch, fd1);
    if (ch == 10) fflush(fd1);
		}while (ch != 'q');
	}
	else{
		
		do{
			//read
			ch = fgetc(fd2);
			putchar(ch);
  	} while (ch != 'q');
	}

  fclose(fd1);
	fclose(fd2);
  unlink(FIFO_NAME_1);
	unlink(FIFO_NAME_2);
  return 0;
}
