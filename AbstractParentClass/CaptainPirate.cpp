#include "CaptainPirate.h"



CaptainPirate::CaptainPirate()
{
	pet = "";
}

CaptainPirate::CaptainPirate(string pet)
{
	setPet(pet);
}
CaptainPirate::~CaptainPirate(void)
{

}

//behaviors
string CaptainPirate::speak(void)
{
	return "Yaaarrr! It be a " + pet + "! \nYaarrr Scallywags! Swab that poop deck!";
}
string CaptainPirate::toString(void)
{
	return Pirate::toString() + ", pet: " + pet;
}

//accessors and mutators
string CaptainPirate::getPet(void)
{
	return pet;
}
void CaptainPirate::setPet(string pet)
{
	if (pet.length() > 0)
		this->pet = pet;
	else
		this->pet = "unknown";
}