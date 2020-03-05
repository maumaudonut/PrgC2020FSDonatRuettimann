#include <stdio.h>
/*
* our first c program! Yeah....
*/


// function prototype
int TestFunction(void);

// global function
int TestValueReturn=0;

// main function
int main(void){

	
	TestValueReturn = TestFunction();
	printf("Hello World! \n TestValue: %d", TestValueReturn);
	return 0; 
}


// implementation of TestFunction
int TestFunction(void)
{

	int retVal = 99;
	return retVal;

}
