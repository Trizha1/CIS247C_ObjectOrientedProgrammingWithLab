#include "Hourly.h"



Hourly::Hourly()
{
	hours = 0.0f;
	rate = 0.0f;
}
Hourly::Hourly(float hours, float rate)
{
	setHours(hours);
	setRate(rate);
}


Hourly::~Hourly(void)
{
	
}

//behaviors
float Hourly::calculatePay(void)
{
	float totalPay;

	float overTimePay;

	if (hours > 40)

	{

		overTimePay = 1.5 * rate * (hours - 40);

		totalPay = overTimePay + 40 * rate;

	}

	else

	{

		totalPay = rate * hours;

	}

	return totalPay;
	
}


//accessors and mutators
float Hourly::getHours(void)
{
	return hours;
}

void Hourly::setHours(float hours)
{
	this->hours = hours;
}


float Hourly::getRate(void)
{
	return rate;
}

void Hourly::setRate(float rate)
{
	this->rate = rate;
}
