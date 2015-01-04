#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include "msgtypes.h"

int msgid;
int i;
struct msg_t message;
char buf[MAXLEN];

void send_message(char * s){
	size_t len=strlen(s);
	if (len>MAXLEN) len=MAXLEN-1;
	message.mtype = 2;
	message.snd_pid = getpid();
	memset(message.body,0,MAXLEN);
	strncpy(message.body, s, len);
	msgsnd(msgid, &message, sizeof(message) - sizeof(message.mtype), 0); // посылаем ответ
}

int main(int argc, char * argv[])
{
	char * hello_server = "Hello, server!\n";
	char * i_m_ok = "I am OK. Thanks!\n";
	char * request = "How are you?\n";
	char * bye_server = "Bye, server!\n";
  msgid = msgget(KEY, 0666);  // получаем идентификатор очереди
  if (msgid == -1)  // Очереди не существует
  {
     printf("Server is not running!\n", msgid);
     return EXIT_FAILURE;
  }
  i = 0;
  send_message(hello_server);
  msgrcv(msgid, &message, sizeof(message) - sizeof(message.mtype), 1, 0);  // ждем ответа
  printf("Server (pid= %i) responded: %s\n", message.snd_pid, message.body);
  
  send_message(i_m_ok);
  msgrcv(msgid, &message, sizeof(message) - sizeof(message.mtype), 1, 0);  // ждем ответа
  printf("Server (pid= %i) responded: %s\n", message.snd_pid, message.body);

  send_message(request);
  msgrcv(msgid, &message, sizeof(message) - sizeof(message.mtype), 1, 0);  // ждем ответа
  printf("Server (pid= %i) responded: %s\n", message.snd_pid, message.body);
  
	send_message(bye_server);
  msgrcv(msgid, &message, sizeof(message) - sizeof(message.mtype), 1, 0);  // ждем ответа
  printf("Server (pid= %i) responded: %s\n", message.snd_pid, message.body);
  
	msgsnd(msgid, &message, sizeof(message), 0);  // посылаем подтверждение
  return EXIT_SUCCESS;
}
