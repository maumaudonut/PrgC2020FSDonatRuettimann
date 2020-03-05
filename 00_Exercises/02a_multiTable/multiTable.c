#include <stdio.h>
#include <stdlib.h>


void PrintUsageMessage(void); //warnt compiler dass unten eine funktion komt
void PrintMultiTable (int tableLimit);


int main(int argc, char* argv[])

{
	int inputValue = 0;

	if (argc !=2) { //2 argumente da das erste der kommand zum ausfüheren ist
	
	PrintUsageMessage();
	return 0;

	}
	else
	{
		inputValue = atoi(argv[1]); // 1 wegen array 0=1 und 1=2ter input
		if(inputValue >= 1 && inputValue <=10)
		{
			PrintMultiTable (inputValue); // for loop von unten wird eingesetzt
		}
		else
		{

			//no valid input
			PrintUsageMessage();
			return 0;

		}

	}




	return 0; 

}



void PrintUsageMessage(void)

{

	printf( " Usage: multiTable wholeNumber\n\t \
		wholeNumber: integer on the interval [1,10]\n");

}


void PrintMultiTable (int tableLimit){
	for(int i=1; i<= tableLimit; i++)
	{
		for(int j=1; j<= tableLimit; j++)
		{
			printf("%d\t", i*j);
		}
		printf("\n");

		




	}







}

