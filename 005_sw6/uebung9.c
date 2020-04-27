#include <stdio.h>

int main(void)
{
	int array[10]={0,1,2,3,4,5,6,7,8,9};
	int index,j;
	for(index=0;index<10;index++){
		printf("Array[%d]=%d\n", index, array[index]);
	}


	for(j=0; j<10; j++){

	array[j]+=10;
	printf("Array[%d]=%d\n", j, array[j]);

	}
	return 0;



}
