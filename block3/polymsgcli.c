#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <strings.h>
#include "polymsgtypes.h"

int main(int argc, char * argv[])
{
  int msgid;
  int i;
  struct msg_1_t message1;
  struct msg_2_t message2;
  char buf[MAXLEN];
  msgid = msgget(KEY, 0666);  // получаем идентификатор очереди
  if (msgid == -1)  // Очереди не существует
  {
     printf("Server is not running!\n", msgid);
     return EXIT_FAILURE;
  }
  i = 0;
  while ( (i < (MAXLEN - 1)) && ((message1.body[i++] = getchar()) !=  '\n') );
  message1.body[i] = '\0';
  message1.mtype = 1;
  message1.snd_pid = getpid ();
  msgsnd(msgid, &message1, MSG_1_SIZE, 0);  // посылаем сообщение
  msgrcv(msgid, &message2, MSG_2_SIZE, 2, 0);  // ждем ответа
  printf("Server (pid= %i) responded: %s\n", message2.snd_pid, message2.body);
  message1.mtype = 1;
  msgsnd(msgid, &message1, MSG_1_SIZE, 0);  // посылаем подтверждение
  return EXIT_SUCCESS;
}
