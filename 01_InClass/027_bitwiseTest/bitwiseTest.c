#include <stdio.h>
#include <stdlib.h>

void printBinary(int input);


int main(int argc, char *argv[])
{
	unsigned int a=12, b=25;
	
	// AND
	printf("***AND***\n");
	printBinary(a);
	printBinary(b);
	printBinary(a&b);


	//OR
	printf("***OR***\n");
	printBinary(a);
	printBinary(b);
	printBinary(a|b);


	//XOR
	printf("***XOR***\n");
	printBinary(a);
	printBinary(b);
	printBinary(a^b);

	//Complement
	printf("***complement***\n");
	printBinary(a);
	printBinary(~a);

	//shift left
	printf("***shift left***\n");
	printBinary(a);
	printBinary(a << 1);

	//shift right
	printf("***shift right***\n");
	printBinary(a);
	printBinary(a >> 1);

	//bit masking: Set bit 5
	unsigned char c      =0b00001100;
	unsigned char mask   =0b00100000; // set bit 5 nur bit 5 wird geändert!! --> mit OR!!
	printf("\n *** set bit 5 *** \n");
	printBinary(c);
	unsigned char d=c | mask;
	printBinary(c|mask);
	mask=1; //0b00000001
	printBinary(c|mask <<5); // bit 5 wird nach links verschoben
	// c=c | mask <<5; // register verändern


	// bit masking:Clear Bit 5 (auf 0 setzen) ---> mit AND!è
	mask= 0b11011111; // clear bit 5
	printf("\n *** clear bit 5 *** \n");
	printBinary(d);
	printBinary(d & mask);
	// ?? elegante Lösung printBinary(d | mask <<5);
	printBinary(d &~(1<<5)); // 5 für 5tes bit -> verkürzte form

	// check if bit 3 is set
	printf("\n*** Check bit3 ***\n"); //bit abfragen
	printBinary(d);
	mask=0b00001000;
	printBinary(d & mask);
	printBinary(d & (1<<3)); // 3 für 3tes bit -> verkürzte form


	//flip bits 4 and 0

	printf("\n *** flip bit 3 and bit 0 ***\n");
	printBinary(d);
	mask=0b00001001;
	printBinary(d^mask);
	printBinary(d^ ((1<<3) |1 )); 
	//              bit 3  bit0

	return EXIT_SUCCESS;
}

void printBinary(int input)
{
	unsigned int i=0;
	printf("%d=0b", input);

	for( i=(1 <<31) ;  i>0; i= (i>>1)) // i nach rechts schieben
	{
		
		if(input & i)
		{

			printf("1");
		}
		else
		{

			printf("0");
		}
	}
	printf("\n");
}

