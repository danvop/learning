#ifndef MSG_TYPES
#define MSG_TYPES

#define KEY 1174     // "магическое" число 
#define MAXLEN 512

struct msg_t  
{
   long mtype;
   int snd_pid;
   char body[MAXLEN];
};

#endif
