#pragma once

#include <string>
using namespace std;

class Glasses
{

private:
	//attributes
	string color;
	float prescription;

public:
	//constructor and destructor
	Glasses(void);
	Glasses(string color, float prescrition);

	~Glasses(void);

	//behaviors
	string toString(void);

	//accessors and mutators
	string getColor(void);
	void setColor(string color);

	float getPrescription(void);
	void setPrescription(float prescription);
};
