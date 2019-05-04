#pragma once
#include <string>
using namespace std;
#include "Salary.h"

class Manager : public Salary
{
private:
	//attributes
	double bonus;
public:
	//constructor and destructor
	Manager(void);
	Manager(double bonus);

	~Manager(void);
	
	//behaviors
	float calculatePay(double annualSalary, double bonus);
	

	//accessors and mutators
	double getBonus(void);
	void setBonus(double bonus);

};

