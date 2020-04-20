#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50

const double maxNorthCH= 47.808455;
const double minNorthCH= 45.817920; 
const double maxEastCH= 10.492035; 
const double minEastCH= 5.95591; 
const double gotthardNorth=46.559167;

//Aufgabe: Eine Stuktur in eine andere Struktur verschachteln

struct Geolocation
{
	double latitude;
	double longitude;

};

struct Student
{
	char name[MAX_NAME_LENGTH];
	int age;
	struct Geolocation currentLocation;

};





//function prototypes

void printStudentPassByReference(struct Student *inputStudent); //mit adresse

void clamp( double* inputValue, double minValue, double maxValue);

void checksStudentPosition(struct Student inputStudent);

int main(int argc, char *argv[])
{

	struct Student student1; //instantiat a Student

	printf("Enter name:" );
	fgets(student1.name, MAX_NAME_LENGTH, stdin);

	printf("Enter age: ");
	scanf("%d", &student1.age);


	printf("Enter current latitude: ");
	scanf("%lf", &student1.currentLocation.latitude); //&wegen scanf
	clamp(&student1.currentLocation.latitude, minNorthCH, maxNorthCH);

	printf("Enter current longitude: ");
	scanf("%lf", &student1.currentLocation.longitude);



	printStudentPassByReference(&student1); //pass by reference ( keine kopie->Adresse) programm von unten wird ausgeführt


	checksStudentPosition(student1);

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
	printf("\nAge: %d\n", (*inputStudent).age); //andere möglichkeit 
	
}

void clamp( double* inputValue, double minValue, double maxValue)
{
	if(*inputValue < minValue)
	{

		*inputValue=minValue;
	}

	if(*inputValue > maxValue)

	{

		*inputValue=maxValue;
	}
}


void checksStudentPosition(struct Student inputStudent)
{
	struct Geolocation *pStudentLocation = &inputStudent.currentLocation; // Haben baum und gehen auf ast

	printf("\n\n");
	printf("Student Location: \n");
	printf("-------------------\n");
	printf("Latitude: %f\n", pStudentLocation->latitude);
	printf("Latitude: %f\n", pStudentLocation->longitude);


	if( pStudentLocation->latitude < gotthardNorth)
	{
		printf("Student location south of Gotthard. Report to Berset. \n");
	}



}



