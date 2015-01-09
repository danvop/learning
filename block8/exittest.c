#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <pthread.h>

void exit_func(void * arg)
{
  free(arg);
  printf("Freed the allocated memory.\n");
}
void * thread_func(void * arg)
{
  int i;
  void * mem;
  pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL); 
  mem = malloc(1024);
  printf("Allocated some memory.\n");
  pthread_cleanup_push(exit_func, mem);
  pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
  for (i = 0; i < 4; i++) {
    sleep(1);
    printf("I'm still running!!!\n");
  }
  pthread_cleanup_pop(1);
}

int main(int argc, char * argv[])
{
  pthread_t thread;
  pthread_create(&thread, NULL, thread_func, NULL);
  pthread_cancel(thread);
  pthread_join(thread, NULL);
  printf("Done.\n");
  return EXIT_SUCCESS;
}
