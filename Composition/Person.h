#pragma once
#include<string>
#include <fstream>
#include "Glasses.h"
using namespace std;

class Person
{
private:
	//attributes
	string name;
	string ssn;
	Glasses myGlasses;    //create default Glasses object


public:
	//constructor and destructor

	Person(void);
	Person(string name, string ssn, Glasses theGlasses);

	~Person(void);

	//behaviors
	string toString(void);
	string writeToFile(void);
	string readFromFile(void);

	//accessors and mutators
	string getName(void);
	void setName(string name);

	string getSSN(void);
	void setSSN(string ssn);

	Glasses getMyGlasses(void);
	void setMyGlasses(Glasses theGlasses);
};

