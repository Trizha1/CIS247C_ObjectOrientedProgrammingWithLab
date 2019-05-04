#include "Manager.h"

Manager::Manager()
{
	bonus = 0.0;
}

Manager::Manager(double bonus)
{
	setBonus(bonus);
}


Manager::~Manager(void)
{
}

//behaviors
float Manager::calculatePay(double annualSalary, double bonus)
{
	
	return (annualSalary / 52.0f) + bonus / 52.0f;

}

//accessors and mutators
double Manager::getBonus(void)
{
	return bonus;
}

void Manager::setBonus(double bonus) 
{
	this->bonus = bonus;
}
