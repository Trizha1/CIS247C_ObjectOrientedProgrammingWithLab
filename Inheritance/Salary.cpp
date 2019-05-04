#include "Salary.h"



Salary::Salary()
{
	annualSalary = 0.0;
}



Salary::Salary(double annualSalary)
{
	setAnnualSalary(annualSalary);
}


Salary::~Salary(void)
{
}

//behaviors
float Salary::calculatePay(void)
{
	return annualSalary / 52.0f;
}


//accessors and mutators
double Salary::getAnnualSalary(void)
{
	return annualSalary;
}
void Salary::setAnnualSalary(double annualSalary)
{
	this->annualSalary = annualSalary;
}