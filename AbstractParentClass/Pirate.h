#pragma once
#include <string>
using namespace std;

class Pirate
{
protected:
	//attributes
	string name;

public:
	//constructor and destructor
	Pirate(void);
	Pirate(string name);
	~Pirate(void);

	//behaviors
	virtual string speak() = 0;
	virtual string toString();

	//accessors and mutators
	string getName(void);
	void setName(string name);
};

