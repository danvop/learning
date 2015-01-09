#include <stdio.h>


#define MAXLEN 10



int main(){

	int array1[MAXLEN]={1,2,3,4,5,6,7,8,9,10};
	int array2[MAXLEN]={0};
	int i = 0;
	int * p;
	
	for (i = 0; i < (MAXLEN/2); i++)
		array2[i]=array1[MAXLEN-1-i];
	
	p = array2;
	while(*p) printf("%d ", *p++);
	
	printf("\n");
}
