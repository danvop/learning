#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semtypes.h"

int main(int argc, char * argv[])
{
  key_t key;
  int shmid;
  struct memory_block * mblock;
  int semid;
  struct sembuf buf[2];
  key = ftok(FTOK_FILE, 1); // генерация ключа
  if (key == -1)
  {
     printf("Failed to generate unique key. Server compiler with a wrong name?\n");
     return EXIT_FAILURE;
  }
  shmid = shmget(key, sizeof(struct memory_block), 0666);
  if (shmid == -1)
  {
     printf("Server is not running!\n");
     return EXIT_FAILURE;
  }
  semid = semget(key, 2, 0666);
  buf[0].sem_num = 0;
  buf[0].sem_flg = SEM_UNDO;
  buf[1].sem_num = 1;
  buf[1].sem_flg = SEM_UNDO;
  mblock = (struct memory_block *) shmat(shmid, 0, 0);
  buf[1].sem_op = -1;
  while (strcmp("q\n", mblock->string) != 0)
  {
    int i = 0;
    semop(semid, (struct sembuf*) &buf[1], 1);
    printf("Server sends %s\n", mblock->string);
    while ((i < (MAXLEN - 1)) && ((mblock->string[i++] = getchar()) !=  '\n') );
    mblock->string[i] = 0;
    buf[0].sem_op = 1;
    buf[1].sem_op = -1;
    semop(semid, (struct sembuf*) &buf, 1);
  }
  printf("Client exits\n");
  shmdt((void *) mblock);  // удаляем отображение
  return EXIT_SUCCESS;
}
