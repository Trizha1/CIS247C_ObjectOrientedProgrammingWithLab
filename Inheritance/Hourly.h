#pragma once
#include <string>
using namespace std;
#include "Employee.h"


class Hourly : public Employee
{
private:
	//attributes
	float hours;
	float rate;

public:
	//constructor and destructor
	Hourly(void);
	Hourly(float hours, float rate);

	~Hourly(void);

	//behaviors
	float calculatePay(void);
	

	//accessors and mutators
	float getHours(void);
	void setHours(float hours);

	float getRate(void);
	void setRate(float hours);

};

