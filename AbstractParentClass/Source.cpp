/*
Patrizha Cruz
CIS247C
*/

#include <iostream>
#include <string>
#include <conio.h>
#include "Pirate.h"
#include "CaptainPirate.h"
#include "ZombiePirate.h"
using namespace std;

void displayPirates(Pirate* ptrPirate);

/// Entry point to the application
int main()
{
	// check for memory leaks
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	Pirate* pirates[2];
	pirates[0] = new CaptainPirate("Jack Parrot");
	pirates[1] = new ZombiePirate();

	for (int i = 0; i < 2; i++)
	{
		cout << pirates[i]->speak() << endl;
	}


	string pet = "Jack Parrot";
	CaptainPirate cp(pet);
	displayPirates(&cp);

	short brainHunger = 3;
	ZombiePirate zp(brainHunger);
	displayPirates(&zp);

	for (int i = 0; i < 2; i++)
	{
		delete pirates;
	}

	//pause
	
	cout << "\nPress any key to continue...";
	_getch();
	system("pause");
	return 0;

}

void displayPirates(Pirate* ptrPirate)
{
	CaptainPirate* cp = dynamic_cast<CaptainPirate*>(ptrPirate);     // NULL if it does not work
	if (cp != NULL)
	{
		cout << "Pet: " << cp->getPet() << endl;
	}
	ZombiePirate* zp = dynamic_cast<ZombiePirate*>(ptrPirate);     // NULL if it does not work
	if (zp != NULL)
	{
		cout << "Brain Hunger: " << zp->getBrainHunger() << endl;
	}


}
