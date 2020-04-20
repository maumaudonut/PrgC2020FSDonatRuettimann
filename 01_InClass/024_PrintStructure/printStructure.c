#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50

struct Student
{
	char name[MAX_NAME_LENGTH];
	int age;

};


//function prototypes
void printStudentPassByValue(struct Student inputStudent); //mit werd
void printStudentPassByReference(struct Student *inputStudent); //mit adresse

int main(int argc, char *argv[])
{

	struct Student student1; //instantiat a Student

	printf("Enter name:" );
	fgets(student1.name, MAX_NAME_LENGTH, stdin);

	printf("Enter age: ");
	scanf("%d", &student1.age);

	printStudentPassByValue(student1); //pass by value (kopie) programm von unten wird ausgeführt. Änderung an Kopie wird durchgeführt

	printStudentPassByReference(&student1); //pass by reference ( keine kopie->Adresse) programm von unten wird ausgeführt



	return EXIT_SUCCESS;
}



void printStudentPassByValue(struct Student inputStudent)
{

	printf("\nStudent information (by value):\n");
	printf(" --------------------------------\n");
	printf("Name: %s", inputStudent.name);
	printf("\nAge: %d\n", inputStudent.age);
	
}

void printStudentPassByReference(struct Student *inputStudent)

{
	printf("\nStudent information (by reference):\n");
	printf(" --------------------------------\n");
	printf("Name: %s", inputStudent->name); // (->pointer auf feld zeigen und gibt wert direkt zurück) ) -> ==(*inputStudent).name (dasselbe)
	printf("\nAge: %d\n", (*inputStudent).age); //andere möglichkeit selbes wie inputStudent->name
	



}
