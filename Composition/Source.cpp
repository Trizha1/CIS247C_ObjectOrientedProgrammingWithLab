/*
Patrizha Cruz
CIS247C
Week 4 Lab
*/

#include <iostream>
#include <string>
#include <conio.h>
#include "Person.h"
using namespace std;

/// Entry point to the application
int main()
{
	//create a default Person object
	Person p1;

	cout << p1.toString() << endl;

	//change the values by setting the name and ssn, and add a Glasses object
	p1.setName("Bob");
	p1.setSSN("222-22-2222");
	Glasses g1("Black", 1.75f);
	p1.setMyGlasses(g1);

	cout << p1.toString() << endl;

	//change the glasses using an anonymous Glasses object
	p1.setMyGlasses(Glasses("Brown", 2.25f));

	cout << "\n" << p1.toString() << endl;

	//show the color only
	cout << "\nColor: " << p1.getMyGlasses().getColor() << endl;

	//show the prescription only
	cout << "\nPrescription: " << p1.getMyGlasses().getPrescription() << endl;

	//write the Person objects's state to the file
	string result = p1.writeToFile();
	cout << "\n" << result << endl;

	//create a default object, change the name. and read the data into the new object
	Person newPerson;
	newPerson.setName("Bob");
	result = newPerson.readFromFile();
	cout << "\n" << result << endl;

	//display the data that was read from the file
	cout << "\n\nPerson object with data from the file:\n" << endl;
	cout << "\t" << newPerson.toString() << endl;

	//pause
	cout << "\nPress any key to continue...";
	_getch();

	return 0;

}