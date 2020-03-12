#include <stdio.h>

int main(void) {


	int zahl1=0;
	int zahl2=0;
	int zahl3=0;

	printf("1. Zahl?");
	scanf("%d", &zahl1);
	printf("2. Zahl?");
	scanf("%d", &zahl2);
	printf("3. Zahl?");
	scanf("%d", &zahl3);

		if (zahl1>0 && zahl2>0 && zahl3>0)
		{
		
		

			if (zahl1>zahl2 && zahl1>zahl3)
			{
				printf("The largest of entered Values is %d\n",zahl1);
				
			}


			else if (zahl2>zahl1 && zahl2>zahl3)
			{
				printf("The largest of entered Values is %d\n",zahl2);	
			}

			
			else //else darf keine bedingung haben!!!!
			{
				printf("The largest of entered Values is %d\n",zahl3);	
			}
			


			if (zahl1<zahl2 && zahl1<zahl3)
			{
				printf("The smallest of entered Values is %d\n",zahl1);
				
			}


			else if (zahl2<zahl1 && zahl2<zahl3)
			{
				printf("The smallest of entered Values is %d\n",zahl2);	
			}

			
			else //else darf keine bedingung haben!!!!
			{
				printf("The smallest of entered Values is %d\n",zahl3);	
			}
			
		}

		else
		{

			printf("Programm Abbrechen, weil Zahlen nicht positiv\n");

 

		}






	return 0;



}
