#include <stdio.h>
#include <stdlib.h>

void PrintUsageMessage(void); //warnt compiler dass unten eine funktion komt
void PrintMultiTable (int tableLimit);

int fact(int);


const int lowerLimit=1;
const int upperLimit=20;


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
		if(inputValue >= lowerLimit && inputValue <= upperLimit) //liegt input im interval (1 und 20)
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

	printf( " Usage: pascalTriangle wholeNumber\n\t \
		wholeNumber: integer on the interval [%d,%d]\n", lowerLimit, upperLimit);

}


void PrintMultiTable (int tableLimit){

	
	for(int i=0; i< tableLimit; i++)
	{
		for(int j=0; j<= tableLimit; j++)
		{
			printf(" ");
		}
		for(int j=0;j<=i;j++)
		{
			printf("%d ",fact(i)/(fact(j)*fact(i-j))); //n=i=anzahl zeilen j=zahl in nächster zeile 

		}
		printf("\n");
	}
}

int fact(int tableLimit)
{

	int f=1; //1: 1*1=1 2: 2*1=2 3: 3*2=6 4:4*6=24 5:5*24=120
	int i; 
	for(i=1;i<=tableLimit;i++)
	{
		f=f*i;

	}
	return(f);


}

		
		




	








