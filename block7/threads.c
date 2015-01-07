#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <pthread.h>

void inline swap(int *i, int *j)
{
    int t;
    t = *i;
    *i = *j;
    *j = t;
}

void reverse(int * v, int n)
{
   int i;
   for (i = 0; i < (n/2); i++)
     swap(&v[i], &v[n-1-i]);
}

int next_permutation(int * v, int n)
{
   int i, j;
   i = n - 1;
   while ((i > 1) && (v[i] < v[i-1])) i--;
   if (v[i] > v[i-1]) {
     j = n - 1;
     while (v[j] < v[i-1]) j--;
     swap(&v[j], &v[i-1]);
     reverse(&v[i], n-i);
     return 1;
   }
   return 0;
}

void print_vect(int * v, int n)
{
   int i;
   for (i = 0; i < n - 1; i++)
     printf("%i ", v[i]);
   printf("%i\n", v[n-1]);
}

void * thread_func(void *arg)
{
   int i;
   int * v;
   int size = * (int *) arg;
   v = malloc(sizeof(int)*size);
   for(i = 0; i < size; i++) v[i] = i+1;
   print_vect(v, size);
   while(next_permutation(v, size)) {
     print_vect(v, size);
     sync();
   }
   free(v);
}

int main(int argc, char * argv[])
{
   int size1, size2, result;
   pthread_t thread1, thread2;
   size1 = 4;
   result = pthread_create(&thread1, NULL, thread_func, &size1);
   if (result != 0) {
     perror("Creating the first thread");
     return EXIT_FAILURE;
   }
   size2 = 3;
   result = pthread_create(&thread2, NULL, thread_func, &size2);
   if (result != 0) {
     perror("Creating the second thread");
     return EXIT_FAILURE;
   }
   result = pthread_join(thread1, NULL);
   if (result != 0) {
     perror("Joining the first thread");
     return EXIT_FAILURE;
   }
   result = pthread_join(thread2, NULL);
   if (result != 0) {
     perror("Joining the second thread");
     return EXIT_FAILURE;
   }
   printf("Done\n");
   return EXIT_SUCCESS;
}
