/*
Patrizha Cruz
CIS247C
*/

#include <iostream>
#include <string>
#include <conio.h>
#include "Card.h"
#include <vector>  //Standard Template Library (STL)
using namespace std;

//prototypes
string showCards(vector<Card> cards);
short sumCardValues(vector<Card> cards);
void playHand(short &cash); // & means address of -- variable sent "by reference"

/// Entry point to the application
int main()
{ 
	//set the starting cash and siplay it to the player
	short cash = 100;
	cout << "Welcome to BlackJack Extreme" << endl;
	cout << "\nYou are starting out with $" << cash << endl;

	//pause
	cout << "\nPress any key to continue...";
	_getch();

	//create the loop variable
	short choice = 0;

	//run the application loop
	do
	{
		//show the menu and get player's choice
		system("cls"); //clear the console
		cout << "Menu\n" << endl;
		cout << "1) Play a hand" << endl;
		cout << "2) Show current cash balance" << endl;
		cout << "3) Exit" << endl;

		cout << "\nEnter you choice: ";
		cin >> choice;

		//switch based on the choice
		switch (choice)
		{
		case 1:
			playHand(cash);
			break;
		case 2:
			cout << "\nYour current cash balance: $" << cash << endl;
			break;
		case 3:
			cout << "\nThank you for playing Extreme BlackJack!" << endl;
			cout << "\nYour final cash position: $" << cash << endl;
			break;
		default:
			cout << "\nError. Please select from the menu." << endl;
			break;
		}

		//pause
		cout << "\nPress any key to continue...";
		_getch();

	} while (choice != 3); // ! means NOT

	return 0;

}

/// Show the cards in the vector (resizable array)
string showCards(vector<Card> cards)
{
	string output = "";

	for (short i = 0; i < cards.size(); i++)
	{
		output += cards[i].toString() + " ";
	}

	return output;
}

/// Add up the total value of the cards
short sumCardValues(vector<Card> cards)
{
	short total = 0;

		for (short i = 0; i < cards.size(); i++)
	{
			total += cards[i].getValue();
	}

		return total;
}

///Play a single hand of BlackJack
void playHand(short &cash)
{
	// create two ArrayLists that can hold Card objects
	// an ArrayList is a resizable array 
	// in C++, the ArrayList is called a vector
	vector<Card> dealerCards;
	vector<Card> playerCards;
	short dealerCardsTotal = 0;
	short playerCardsTotal = 0;

	// get bet amount
	short bet = 0;
	cout << "\nEnter bet amount: ";
	cin >> bet;

	// create two cards for the dealer and show the first one
	int number;
	Card card1;
	Card card2;
	dealerCards.push_back(card1);  // push_back will add it to the vector and put it to the tail end
	dealerCards.push_back(card2);
	dealerCardsTotal = sumCardValues(dealerCards);

	cout << "\nDealer is showing: " << dealerCards[0].toString() << endl;

	// Create two cards for the player and show them both
	playerCards.push_back(Card());  //create the card and put it directly into the ArrayList(vector)
	playerCards.push_back(Card());
	playerCardsTotal = sumCardValues(playerCards);

	cout << "\nHere are you cards: " << showCards(playerCards) << endl;

	// Give cards to the player until they stand ('S')
	char answer = '?';

	do
	{
		cout << "\nDo you want to hit or stand (H/S)? ";
		cin.sync();  //flush the input stream (Keyboard buffer)  -- cin.ignore(100, '\n')
		cin >> answer;
		cin.sync();

		if (toupper(answer) == 'H')
		{
			//give a card to the player
			Card c;
			cout << "\nYou were dealt this card: " << c.toString() << endl;
			playerCards.push_back(c);  //add card to player's hand

			//sum up the card values
			playerCardsTotal = sumCardValues(playerCards);

			//did the player bust?
			if (playerCardsTotal > 21)
			{
				// Do you have an Ace that can be dropped to a 1 value? 

				for (Card c : playerCards)
				{
					if (c.getValue() == 11)
					{
						cout << "\nYour total is " << playerCardsTotal << endl;
						c.flapAceToOne();
						cout << "However, you have an Ace that was converted to '1' value" << endl;
						cout << "\nYour new total is " << playerCardsTotal << endl;

						// if we are good now, break out of the loop. Otherwise, keep looping and looking for Aces
						if (playerCardsTotal <= 21)
							break;
					}
				}
			}

			// show the cards and the total
			cout << "\nHere are your cards: " << showCards(playerCards) << endl;
			cout << "\nYour total is " << playerCardsTotal << endl;


			// if busted, stop the loop
			if (playerCardsTotal > 21)
				answer = 'S';
		}
	} while (toupper(answer) != 'S');

	//if player's cardTotal is more than 21, the player busted so take money away
	if (playerCardsTotal > 21)
	{
		cout << "\nYou busted!" << endl;
		cash = cash - bet;
	}
	else
	{
		//Player stands so the dealer hits until 17 or greater
		do
		{
			if (dealerCardsTotal < 17)
			{
				Card c;
				cout << "\nDealer was dealt: " << c.toString() << endl;
				dealerCards.push_back(c);	//add the card to the dealer's hand
				cout << "\nDealer cards: " << showCards(dealerCards) << endl;
				dealerCardsTotal = sumCardValues(dealerCards);
				cout << "Dealer total: " << dealerCardsTotal << endl;
			}
		} while (dealerCardsTotal < 17);

		// show the cards for the dealer and the player
		cout << "\nYour cards: " << showCards(playerCards) << "(" << playerCardsTotal << ")" << endl;
		cout << "\nDealer cards: " << showCards(dealerCards) << "(" << dealerCardsTotal << ")" << endl;

		//who wins?
		if (dealerCardsTotal > 21)
		{
			cout << "\nDealer busted!" << endl;
			cash = cash + bet;
		}
		else if (dealerCardsTotal > playerCardsTotal)
		{
			cout << "\nDealer wins." << endl;
			cash = cash - bet;
		}
		else if (playerCardsTotal > dealerCardsTotal)
		{
			cout << "\nYou win!" << endl;
			cash = cash + bet;
		}
		else
		{
			cout << "\nYou pushed the dealer (tie)." << endl;
		}
	}

	//show the current cash position
	cout << "\nYour current cash balance: $" << cash << endl;

}



