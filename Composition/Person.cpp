#include "Person.h"



Person::Person()
{
	name = "unknown";
	ssn = "unknown";
	//myGlasses object has already been created
}

Person::Person(string name, string ssn, Glasses theGlasses)
{
	setName(name);
	setSSN(ssn);
	setMyGlasses(theGlasses);
}

Person::~Person(void)
{

}

//behaviors
string Person::toString(void)
{
	return "Name: " + name + ", SSN: " + ssn + ", Glasses: [" + myGlasses.toString() + "]";
}

string Person::writeToFile(void)
{
	//write the state of the Person to the file using the person's name
	string fileName = name + ".txt";
	ofstream oFile(fileName);  //default to ios::out (destroys prior data) -- ios::app --> appends to the file

	oFile << name << endl;
	oFile << ssn << endl;
	oFile << myGlasses.getColor() << endl;
	oFile << myGlasses.getPrescription() << endl;

	oFile.close();

	//tell user that the data was written to the file

	return name + "'s data was written to the file.";
}
string Person::readFromFile(void)
{
	string fileName = name + ".txt";
	ifstream iFile(fileName);

	if (!iFile.is_open()) //! NOT open
	{
		return "Error. File cannot be opened. Does it exist?";
	}
	else
	{
		getline(iFile, name);  // read into this object's name attribute
		getline(iFile, ssn);   // read ubti this object's ssn attribute

		string color = "";
		getline(iFile, color);  // read the glasses' color
		float pers = 0.0f;
		iFile >> pers;          //reads the Glasses' prescription
		this->setMyGlasses(Glasses(color, pers));
		iFile.ignore(1);	   //ignore and use up the '\n' (newline)

		iFile.close();

		//tell the user that the data has been loaded
		return name + "'s data has been loaded from the file.";
	}
}

//accessors and mutators
string Person::getName(void)
{
	return name;
}
void Person::setName(string name)
{
	if (name.length() > 0)
		this->name = name;
	else
		this->name = "unknown";
}

string Person::getSSN(void)
{
	return ssn;
}
void Person::setSSN(string ssn)
{
	if (ssn.length() == 9 || ssn.length() == 11)
		this->ssn = ssn;
	else
		this->ssn = "unknown";
}

Glasses Person::getMyGlasses(void)
{
	return myGlasses;
}
void Person::setMyGlasses(Glasses theGlasses)
{
	this->myGlasses = theGlasses;
}