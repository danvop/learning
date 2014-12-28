#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include "msgtypes.h"

int main(int argc, char * argv[])
{
  struct msg_t message;
  int msgid;
  char * response = "Ok!";
  msgid = msgget(KEY, 0666 | IPC_CREAT);  // создаем очередь сообщений
  msgrcv(msgid, &message, sizeof(message) - sizeof(message.mtype), 2, 0);  // ждем сообщение
  printf("Client (pid = %i) sent: %s", message.snd_pid, message.body);
  message.mtype = 1;
  message.snd_pid = getpid();
  strcpy(message.body, response);
  msgsnd(msgid, &message, sizeof(message) - sizeof(message.mtype), 0); // посылаем ответ
  msgrcv(msgid, &message, sizeof(message) - sizeof(message.mtype), 2, 0);  // ждем подтверждения
  msgctl(msgid, IPC_RMID, 0);  // удаляем очередь
  return EXIT_SUCCESS;
}
