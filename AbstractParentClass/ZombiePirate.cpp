#include "ZombiePirate.h"

ZombiePirate::ZombiePirate(void)
{
	brainHunger = 3;
}


ZombiePirate::ZombiePirate(short brainHunger)
{
	this->brainHunger = brainHunger;
}
ZombiePirate::~ZombiePirate(void)
{

}

//behaviors
string ZombiePirate::speak(void)
{
	// say something based on the hunger level
	switch (brainHunger)
	{
	case 0:
		return "Yum. I just ate a brain!";
		break;
	case 1:
		return "I'm getting a little hungry... Are there any brains out there?";
		break;
	case 2:
		return "I'm getting very hungry!! I need a brain to eat!!";
		break;
	case 3:
		return "BRAINS!!!! GIVE ME BRAINS NOW!!! I NEED TO EAT BRAINS NOW!!!";
		break;
	default:
		return "Error. Something went wrong.";
		break;
	}
}

string ZombiePirate::toString(void)
{
	return toString();
}


short ZombiePirate::getBrainHunger(void)
{
	return brainHunger;
}
void ZombiePirate::setBrainHunger(short brainHunger)
{
	if (brainHunger > 0)
		this->brainHunger = brainHunger;
	else
		this->brainHunger = 0;
}
