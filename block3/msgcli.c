#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <strings.h>
#include "msgtypes.h"

int main(int argc, char * argv[])
{
  int msgid;
  int i;
  struct msg_t message;
  char buf[MAXLEN];
  msgid = msgget(KEY, 0666);  // получаем идентификатор очереди
  if (msgid == -1)  // Очереди не существует
  {
     printf("Server is not running!\n", msgid);
     return EXIT_FAILURE;
  }
  i = 0;
  while ( (i < (MAXLEN - 1)) && ((message.body[i++] = getchar()) !=  '\n') );
  message.body[i] = '\0';
  message.mtype = 2;
  message.snd_pid = getpid ();
  msgsnd(msgid, &message, sizeof(message) - sizeof(message.mtype), 0);  // посылаем сообщение
  msgrcv(msgid, &message, sizeof(message) - sizeof(message.mtype), 1, 0);  // ждем ответа
  printf("Server (pid= %i) responded: %s\n", message.snd_pid, message.body);
  message.mtype = 2;
  msgsnd(msgid, &message, sizeof(message), 0);  // посылаем подтверждение
  return EXIT_SUCCESS;
}
