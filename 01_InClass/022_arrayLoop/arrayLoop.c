#include <stdio.h>
#include <stdlib.h>

#define LOOP_ARRAY_LENGTH 6 //konstante gross schreiben

// function prototype
void printIntArray( int inputArray [], int arrayLength); // array wird mitgegeben mit länge und adresse zu erstem array

int main(int argc, char * argv[]) 
{

	int loopArray[LOOP_ARRAY_LENGTH]={0};

	//check if they are reall all zero:

	printf("Check if all array element are zero: \n");

	//print all array element to console
	printIntArray(loopArray, LOOP_ARRAY_LENGTH);
	printf("\n");


	// save array index as array value
	for(int j=0; j< LOOP_ARRAY_LENGTH; j++)
	{
		loopArray[j] = j;
	}
	

	// print all array elements to console
	printf("Modified array: \n");
	printIntArray(loopArray, LOOP_ARRAY_LENGTH);
	printf("\n");




	return EXIT_SUCCESS;

}


// function implementation

void printIntArray( int inputArray [], int arrayLength)

{



	for(int i=0; i< arrayLength; i++)
	{

		printf("%d\n", inputArray[i]);
	}

}
