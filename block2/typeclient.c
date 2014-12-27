#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

#define FIFO_NAME_1 "./fifofile1" //for server write
#define FIFO_NAME_2 "./fifofile2" //for client write

int main ()
{
FILE * fd1;
FILE * fd2;
int lf;
char ch;
pid_t pid;
char buf[1024];
int i;
i = 0;
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
			ch = getchar();
			buf[i++]=ch;
			fputc(ch, fd2);
			if (ch == 10) {
				lf = open("logfile.txt", O_WRONLY | O_CREAT| O_APPEND, 0600);
				fflush(fd2);
				write(lf,"client: ", 8 );	
				write(lf,buf,i); 
				close(lf);
				memset(buf,'\0',i+1);
			}
	
	  	}while (ch != 'q');
	}


	fclose(fd1);
	fclose(fd2);
  	unlink(FIFO_NAME_1);
	unlink(FIFO_NAME_2);
  return 0;
}
