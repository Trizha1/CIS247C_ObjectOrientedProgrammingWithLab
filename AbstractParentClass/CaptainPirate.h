#pragma once
#include "Pirate.h"
#include <string>
using namespace std;

class CaptainPirate : public Pirate
{
private:
	//attributes
	string pet;
public:
	//contructor and destructor
	CaptainPirate(void);
	CaptainPirate(string pet);
	~CaptainPirate(void);

	//behaviors
	string speak(void);
	string toString(void);

	//accessors and mutators
	string getPet(void);
	void setPet(string pet);
};

