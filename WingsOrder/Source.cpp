/*
Patrizha Cruz
CIS247C
CIS247C
Week 3 iLab
*/

#include <iostream>
#include <string>
#include <conio.h>
#include "Wings.h"
using namespace std;

/// Entry point to the application
int main()
{
	//create two wings objects
 	Wings w1("Honey Hot ", 6);
	Wings w2(" BBQ", 6);

	Wings w3 = w1 + w2;

	cout << "Combined wings: " << w3.getFlavor() << ", " << w3.getNumberOfPieces() << endl;
	
	Wings w4 = w3 - w2;

	cout << "Smaller wings: " << w4.getFlavor() << ", " << w4.getNumberOfPieces() << endl;

	Wings w5 = -w4;

	cout << "Negated wings: " << w4.getFlavor() << ", " << w4.getNumberOfPieces() << endl;

	w5 = -w5;
	++w5;

	cout << "Pre-incremented wings: " << w5.getFlavor() << ", " << w5.getNumberOfPieces() << endl;

	w5++;

	cout << "Post-incremented wings: " << w5.getFlavor() << ", " << w5.getNumberOfPieces() << endl;

	Wings w6 = w5;

	cout << "Equal wings: " << w6.getFlavor() << ", " << w6.getNumberOfPieces() << endl;

	Wings w7;
	cin >> w7;

	cout << "Input stream wings: " << w7.getFlavor() << ", " << w7.getNumberOfPieces() << endl;

	cout << "Output stream wings: " << w7 << endl;


	//pause
	cout << "\nPress any key to continue...";
	_getch();

	return 0;

}
