#pragma once
#include <string>
using namespace std;
#include "Employee.h"

class Salary:public Employee
{
private:
	//attributes
	double annualSalary;
public:
	//constructor and destructor
	Salary(void);
	Salary(double annualSalary);

	~Salary(void);

	//behaviors
    float calculatePay(void);
	

	//accessors and mutators
	double getAnnualSalary(void);
	void setAnnualSalary(double annualSalary);
};

