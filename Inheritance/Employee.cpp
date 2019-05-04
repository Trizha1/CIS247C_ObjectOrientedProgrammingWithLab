#include "Employee.h"



Employee::Employee()
{
	fName = "Pat";
	lName = "Cruz";
	ssn = "123-12-1234";
	phone = "818-888-8888";
	
}


Employee::Employee(string fName, string lName, string ssn, string phone)
{
	setFName(fName);
	setLName(lName);
	setSSN(ssn);
	setPhone(phone);
}

Employee::~Employee(void)
{

}

//behaviors
float Employee::calculatePay(void)
{
	return 0.0f;
}
string Employee::toString(void)
{
	return "Name: " + fName + " " + lName + ", SSN: " + ssn + ", Phone: " + phone;
}

//accessors and mutators
string Employee::getFName(void)
{
	return fName;
}
void Employee::setFName(string fName)
{
	this->fName = fName;
}

string Employee::getLName(void)
{
	return lName;
}
void Employee::setLName(string lName)
{
	this->lName = lName;
}

string Employee::getSSN(void)
{
	return ssn;
}
void Employee::setSSN(string ssn)
{
	this->ssn = ssn;
}

string Employee::getPhone(void)
{
	return phone;
}
void Employee::setPhone(string phone)
{
	this->phone = phone;
}