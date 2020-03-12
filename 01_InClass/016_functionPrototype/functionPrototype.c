#include <stdio.h>
#include <stdlib.h>

/*	prints the user menu and returns the selected item
 * 	Inputs: None.
 * 	Outputs: int selectedMenuItem
 *  Error behavior: returns zero for all invalid menu item selections
 */	
int PrintUserMenu( void ) {
	int selectedMenuItem = 0;
	printf("\n------------------------------------\n");
	printf("* * * * Welcome to CoolCode! * * * *\n");
	printf("------------------------------------\n");
	printf("Select from the following options:\n");
	printf("1: exit\n");
	printf("-> ");
	scanf("%d", &selectedMenuItem );
	return selectedMenuItem;
}	

/********************************************************
 * main
 ********************************************************/
int main (int argc, char *argv[] )
{
	int menuSelection = PrintUserMenu();
	if( menuSelection == 0 )
	{
		printf("Invalid menu selection. Aborting.\n");
		return 0;
	} 
	else if( menuSelection == 1 ) 
	{
		printf("Exiting... Goodbye.\n");
		return 0;
	}
}


