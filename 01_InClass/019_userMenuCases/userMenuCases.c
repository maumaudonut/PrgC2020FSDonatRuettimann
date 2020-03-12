#include <stdio.h>
#include <stdlib.h>



typedef enum{
	INVALID =0,
	PRINTCODERNAME =1,
	CALCONEPLUSONE, //2 da nicht also nächst höhere zahl
	EXIT //3 da nichs agnegeben
} MenuSelection; //gibt variable zurück vom typ MenuSelection typ=ist wie ein int 

MenuSelection PrintUserMenu( void );


int main( int argc, char *argv[])
{
	int runMenuPrompt=1;
	MenuSelection menuSelection=EXIT;

	while(runMenuPrompt)
	{
		menuSelection = PrintUserMenu();



		switch(menuSelection)
		{
		case PRINTCODERNAME:
			printf("Ako!\n");
			break;
		case CALCONEPLUSONE:
			printf("1+1=2.5\n");
			break;
		case EXIT:
			printf("Exiting Goodbye\n");
			runMenuPrompt=0;
			break;
		default:
			printf("Invalid menus selection\n");
			break;


		} //switch menu Selcetion
	}//while(runMenuPromt)

	return EXIT_SUCCESS;
}




/*	prints the user menu and returns the selected item
 * 	Inputs: None.
 * 	Outputs: int selectedMenuItem
 *  Error behavior: returns zero for all invalid menu item selections
 */	
MenuSelection PrintUserMenu( void ) { //Int wird durch MenuSelection ersetzt wegen enum
	int selectedMenuItem = 0;
	printf("\n------------------------------------\n");
	printf("* * * * Welcome to CoolCode! * * * *\n");
	printf("------------------------------------\n");
	printf("Select from the following options:\n");
	printf("1: Print Coder Name\n");
	printf("2: Calculate 1+1\n");
	printf("3: exit\n");
	printf("-> ");
	scanf("%d", &selectedMenuItem );

	if( selectedMenuItem != PRINTCODERNAME && selectedMenuItem != CALCONEPLUSONE && selectedMenuItem != EXIT)
	{
		selectedMenuItem= INVALID;
	}
	return selectedMenuItem;
}	
