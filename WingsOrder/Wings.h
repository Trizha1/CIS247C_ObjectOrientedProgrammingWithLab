#pragma once
#include <string>
#include <iostream>
using namespace std;

class Wings
{

private:
	// attributes
	string flavor;
	short numPieces;

public:
	//constructors
	Wings(string flavor = "unknown:", short numberOfPieces = 0);

	~Wings(void);

	//behaviors
	Wings operator+(const Wings secondWings) const;	 // wings3 = wings1 + wings2;
	Wings operator-(const Wings secondWings) const;  // wings3 = wings1 - wings2
	Wings operator-(void);							// winngs2 = -wings1;
	Wings& operator++(void);						// ++wings;
	Wings operator++(int);							//wings++;
	Wings& operator=(const Wings& equalWings);		// Wings w2 = w1;

	//overload the input stream operator
	//cin >> wings;
	friend istream& operator>>(istream &is, Wings &obj);
	
	//overload the output stream operator
	//cout << wings << endl;
	friend ostream& operator<<(ostream &os, Wings &obj);

	//accessors and mutators
	string getFlavor(void);
	void setFlavor(string flavor);

	short getNumberOfPieces(void);
	void setNumberOfPieces(short numberOfPieces);

};

