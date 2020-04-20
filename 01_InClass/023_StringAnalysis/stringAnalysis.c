#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // damit buchstaben alle in gross buchstaben verwandelt werden

#define MAX_INPUT_LENGTH 50

int main( int argc, char *argv[])

{

	char inputString[MAX_INPUT_LENGTH];
	char *pCurrentChar=NULL;
	int countVowels =0, countConsonants=0;

	printf("\n\nCount the number of vowels and consontants: \n");
	printf(      "------------------------------------------\n");
	printf("Input a string (max. %d):", MAX_INPUT_LENGTH);

	fgets(inputString, MAX_INPUT_LENGTH, stdin);   //kein &inputString weil Arrayname schon Adresse ist es werden nur 49(+0) bei der eingabe mitgegeben


	pCurrentChar= inputString; //set pointe to first element

	while(*pCurrentChar !='\0') // solang er nicht am ende ist macht er etwas
	{
	printf("Ox%x\n", *pCurrentChar);



	char temp = toupper(*pCurrentChar);
	if( temp == 'A' || temp == 'E' || temp == 'I' || temp == 'O' || temp == 'U') //'A' für singel characters
	{
		countVowels++;
	}

	else
	{
		// ignore white space

		if( !isspace(temp) ){  //leerschläge werden nichtbeachtet
			countConsonants++;
		}
	}
	pCurrentChar++;  // increase pointer to advance to next element in array

	}

	
	printf("Number of vowels: %d, Number of consonants: %d\n", countVowels, countConsonants);



	return EXIT_SUCCESS;
}
