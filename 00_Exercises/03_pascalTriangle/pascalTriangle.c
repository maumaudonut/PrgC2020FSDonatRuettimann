//Team:
//Donat Ruettimann
// Adrian Bodenstein

#include <stdio.h>
#include <stdlib.h>

void PrintUsageMessage(void);
void PrintPascalTriangle( int triangleRows );

int main( int argc, char* argv[] )
{
	int inputValue = 0;
	if ( argc != 2)
	{
		PrintUsageMessage();
		return 0;
	}
	else
	{
		inputValue = atoi(argv[1]);
		if( inputValue >= 1 && inputValue <= 20 )
		{
			//input is valid
			PrintPascalTriangle( inputValue );
		}
		else
		{
			//input is unvalid
			PrintUsageMessage();
			return 0;
		}
	}
	return 0;
}

void PrintUsageMessage(void)
{
	printf("Usage: pascalTriangle wholeNumber\n\t \
			wholeNumber: integer on the interval [1,20]\n");
}

void PrintPascalTriangle( int triangleRows )
{
	int coef = 1, space, i, j; //coef=1 andere var= int
	for (i = 0; i < triangleRows; i++) //anzahl reihen 
	{
        for (space = 1; space <= triangleRows - i; space++)
		{
			//space from left side
            printf("  ");
		}
        for (j = 0; j <= i; j++)
		{
            if (j == 0 || i == 0)
			{
                coef = 1;
			}
            else
			{
				//calculation of coefficients
                coef = coef*(i-j+1)/j;
			}
            printf("%4d", coef);
        }
        printf("\n");
    }
}



	








