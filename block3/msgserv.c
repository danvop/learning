#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include "msgtypes.h"

struct msg_t message;
int msgid;

void send_message(char * s){
	size_t len=strlen(s);
	if (len>MAXLEN) len=MAXLEN-1;
	message.mtype = 1;
	message.snd_pid = getpid();
	memset(message.body,0,MAXLEN);
	strncpy(message.body, s, len);
	msgsnd(msgid, &message, sizeof(message) - sizeof(message.mtype), 0); // посылаем ответ
}


int main(int argc, char * argv[])
{
	char * hello_client = "Hello, client!\n";
	char * i_m_ok = "I am OK. Thanks!\n";
	char * request = "And how are you?\n";
	char * bye_client = "Bye, client!\n";

  msgid = msgget(KEY, 0666 | IPC_CREAT);  // создаем очередь сообщений
	
	msgrcv(msgid, &message, sizeof(message) - sizeof(message.mtype), 2, 0);  // ждем сообщение
	printf("Client (pid = %i) sent: %s", message.snd_pid, message.body);
	send_message(hello_client);

	msgrcv(msgid, &message, sizeof(message) - sizeof(message.mtype), 2, 0);  // ждем сообщение
	printf("Client (pid = %i) sent: %s", message.snd_pid, message.body);
	send_message(request);
	
	msgrcv(msgid, &message, sizeof(message) - sizeof(message.mtype), 2, 0);  // ждем сообщение
	printf("Client (pid = %i) sent: %s", message.snd_pid, message.body);
	send_message(i_m_ok);
  
	msgrcv(msgid, &message, sizeof(message) - sizeof(message.mtype), 2, 0);  // ждем сообщение
	printf("Client (pid = %i) sent: %s", message.snd_pid, message.body);
	send_message(bye_client);
	
	msgctl(msgid, IPC_RMID, 0);  // удаляем очередь
  return EXIT_SUCCESS;
}
