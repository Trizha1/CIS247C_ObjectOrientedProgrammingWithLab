#include "Pirate.h"



Pirate::Pirate()
{
	name = "unknown";
}

Pirate::Pirate(string name)
{
	setName(name);
}
Pirate::~Pirate(void)
{

}

//behaviors

string Pirate::speak()
{
	return speak();
}
string Pirate::toString()
{
	return toString();
}

//accessors and mutators
string Pirate::getName(void)
{
	return name;
}
void Pirate::setName(string name)
{
	if (name.length() > 0)
		this->name = name;
	else
		this->name = "unknown";
}