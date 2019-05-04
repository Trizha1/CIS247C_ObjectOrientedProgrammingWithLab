/*
Patrizha Cruz
CIS247C
*/

#include <iostream>
#include <string>
#include <conio.h>
#include "ArrayList.h"
using namespace std;

/// Entry point to the application
int main(void)
{
	//check for memory leaks
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	//create an int ArrayList
	ArrayList<int> intList;
	intList.add(27);
	intList.add(13);
	intList.add(42);
	intList.add(31);
	intList.add(22);
	intList.add(19);
	
	for (int i = 0; i < intList.getCount(); i++)
	{
		cout << intList.get(i) << ", ";
	}

	cout << "\n" << endl;
	cout << "Count: " << intList.getCount() << endl;
	cout << "Capacity: " << intList.getCapacity() << endl;

	cout << "\n\n" << endl;

	//create a string ArrayList
	ArrayList<string> strList;
	strList.add("Brendan");
	strList.add("Maria");
	strList.add("Ivan");
	strList.add("Nathan");

	//display list data
	for (int i = 0; i < strList.getCount(); i++)
	{
		cout << strList.get(i) << ", ";
	}

	cout << "\n" << endl;
	cout << "Count: " << strList.getCount() << endl;
	cout << "Capacity: " << strList.getCapacity() << endl;
//pause
	cout << "\nPress any key to continue...";
	_getch();

	return 0;

}
