#include "Wings.h"

//constructors
Wings::Wings(string flavor, short numberOfPieces)
{
	setFlavor(flavor);
	setNumberOfPieces(numberOfPieces);

}

Wings::~Wings(void)
{
	//no dynamic objects to destroy
}

//behaviors
Wings Wings::operator+(const Wings secondWings) const
{
	//create the wings objects to return
	Wings thirdWings;

	//tell C++ how to combine the wings attributes
	thirdWings.numPieces = this->numPieces + secondWings.numPieces;
	if (this->flavor != secondWings.flavor)
		thirdWings.flavor = this->flavor + "and" + secondWings.flavor;
	else
		thirdWings.flavor = this->flavor;

	//return the new, combined wings
	return thirdWings;

}

Wings Wings::operator-(const Wings secondWings) const
{
	Wings thirdWings;

	//tell C++ how to combine the wings attributes
	thirdWings.numPieces = this->numPieces - secondWings.numPieces;
	string full = this->flavor;  //current flavor

	short position = full.find("and", 0);
	if (position > 0)
		thirdWings.flavor = full.substr(0, position - 1);
	else
		thirdWings.flavor = this->flavor;

	//return the new, changed wings object
	return thirdWings;
}


Wings Wings::operator-(void)
{
	numPieces = -1 * numPieces;		// numPieces = -numPieces
	//flavor = ??					// we typically do not negate strings

	return *this;
}

Wings& Wings::operator++(void)
{
	++numPieces;

	//return the incremented wings object
	return *this;
}

Wings Wings::operator++(int)
{
	//save the old state (old values)
	Wings temp = *this;  //save the old state

	//tell C++ how to post increment the current state
	++(*this);

	//return the old state
	return temp;

}

Wings& Wings::operator=(const Wings& equalWings)
{
	if (this != &equalWings)  //confirm that this is NOT the same object
	{
		this->flavor = equalWings.flavor;
		this->numPieces = equalWings.numPieces;
	}

	//return the new object
	return *this;
}

istream& operator>>(istream &is, Wings &obj)
{
	//append to the input stream
	cout << "Enter the wings flavor: ";
	getline(is, obj.flavor);
	cout << "Enter the number of wings: ";
	is >> obj.numPieces;

	//return the input stream so more stuff can be appended
	return is;
}

ostream& operator<<(ostream &os, Wings &obj)
{
	//append our information to the current output stream
	os << "Wings Flavor: " << obj.flavor << ", Number of Wings: " << obj.numPieces;
	
	//return the input stream so more stuff can be appended
	return os;
}

//accessors and mutators
string Wings::getFlavor(void)
{
	return flavor;
}
void Wings::setFlavor(string flavor)
{
	if (flavor.length() > 0)
		this->flavor = flavor;
	else
		this->flavor = "unknown";
}

short Wings::getNumberOfPieces(void)
{
	return  numPieces;
}
void Wings::setNumberOfPieces(short numberOfPieces)
{
	if (numberOfPieces > 0)
		numPieces = numberOfPieces;
	else
		numPieces = 0;
}
