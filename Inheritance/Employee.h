#pragma once
#include <string>
using namespace std;


class Employee
{

protected:
	//attributes
	string fName;
	string lName;
	string ssn;
	string phone;

public: 
	//constructor and destructor
	Employee(void);
	Employee(string fName, string lName, string ssn, string phone);

	~Employee(void);

	//behaviors
	virtual float calculatePay(void);
	virtual string toString(void);

	//accessors and mutators
	string getFName(void);
	void setFName(string fName);

	string getLName(void);
	void setLName(string lName);

	string getSSN(void);
	void setSSN(string ssn);

	string getPhone(void);
	void setPhone(string phone);
};

