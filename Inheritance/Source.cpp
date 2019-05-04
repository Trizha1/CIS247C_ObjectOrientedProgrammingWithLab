/*
Patrizha Cruz
CIS247C
Week 5 iLab
*/

#include <iostream>
#include <string>
#include <conio.h>
#include "Employee.h"
#include "Hourly.h"
#include "Salary.h"
#include "Manager.h"

using namespace std;


void displayEmployee(Employee* emp);

/// Entry point to the application
int main()
{
	
	
	float hours = 0.0f;
	cout << "Enter hours worked: ";
	cin >> hours;

	float rate = 0.0f;
	cout << "Enter rate: ";
	cin >> rate;

	double annualSalary;
	cout << "Enter Annual Salary: ";
	cin >> annualSalary;

	double bonus;
	cout << "Enter bonus: ";
	cin >> bonus;

	Hourly myHours(hours, rate);
	displayEmployee(&myHours);

	Salary tempSal(annualSalary);
	displayEmployee(&tempSal);

	Manager mgr(bonus);
	displayEmployee(&mgr);
	cout << "Your Bonus: " << mgr.calculatePay(annualSalary, bonus) << endl;

//pause
	cout << "\nPress any key to continue...";
	_getch();

	return 0;

}


void displayEmployee(Employee* emp)
{
	cout << "Name: " << emp->getFName() << " " << emp->getLName() << endl;
	cout << "SSN: " << emp->getSSN() << endl;
	cout << "Phone: " << emp->getPhone() << endl;

	Manager* mgr = dynamic_cast<Manager*>(emp);    // try to convert Employee parent object to a Manager child object
	if (mgr != NULL)                              // if the mgr is not NULL, then we have a Manager object!
	{
		cout << "Bonus: $" << mgr->getBonus() << endl;

	}

	Salary* tempSal = dynamic_cast<Salary*>(emp);
	if (tempSal != NULL)
	{
		cout << "Annual Salary: $" << tempSal->getAnnualSalary() << endl;
		cout << "Your Annual Salary: " << tempSal->calculatePay() << endl;
	}

	Hourly* myHours = dynamic_cast<Hourly*>(emp);
	if (myHours != NULL)
	{
		

		cout << "Total Hours: " << myHours->getHours() << endl;
		cout << "Hourly rate: " << myHours->getRate() << endl;
		cout << "Your Total Pay including your overtime: " << myHours->calculatePay() << endl;
	}

	
}
