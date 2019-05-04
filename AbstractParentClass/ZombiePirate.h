#pragma once
#include <string>
#include "Pirate.h"
using namespace std;

class ZombiePirate : public Pirate
{
private:
	//attributes
	short brainHunger;
public:
	//constructor and destructor
	ZombiePirate(void);
	ZombiePirate(short brainHunger);
	~ZombiePirate(void);

	//behaviors
	string speak(void);
	string toString(void);



	//accessors and mutators
	short getBrainHunger(void);
	void setBrainHunger(short brainHunger);
	
};

