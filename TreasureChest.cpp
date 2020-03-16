// Ryan Hutton
// Module Three - Search for Treasure Game
// SNHU IT 312 - Software Development with C++
// 1/22/2020

// Summary: This game simulates the player discovering five treasure chests on a map.
// You want to track which chest the player has found and opened.  Create a boolean
// array that stores five pointers to update the array to true for the chest just found.
// Then print out to the player if he or she levels up based on the Boolean of the fifth.
// chest.  This program attempts to assign a random index in the array to true and checks
// if it matches with the user's input.  An additional requirement was to use pointers
// to access elements in the array.

#include <iostream>
#include <stdlib.h>
#include <ctime>;

// Function prototypes.  Theirs names describe themselves.
void displayInventory(bool[]);
void addTreasureChest(bool[], int);

using namespace std;

int main() 
{ 
	int choice = 0; // user input choice
	bool treasureArray[5] = { false };  // Assign all elements in the boolean array to false.
	bool levelUpToken = false;

	// Seed randonm number set up.
	srand(time(0));

	cout << "Ryan Hutton" << endl;
	cout << "Module 3 Activity - Treasure Chest" << endl;
	cout << "SNHU IT 312 - Software Development w/ C++" << endl;
	cout << endl;

	while (!levelUpToken)  // while levelUpToken is false
	{
		cout << "Which chest did you find (1-5)? ";
		cin >> choice;

		// This test to see if the value of the user's choice matches a random value in the treasureArray.
		// It matched the user's 'choice' element to a random element in the treasureArray (0 to 5).
		// NOTE: Lower random numbers seem to be selected at higher rates than higher number, so it may
		//  be a good idea to begin with elements 5, 4, 3, etc. to see the full gameplay.
		if (treasureArray[choice] == treasureArray[rand() % 5]) // OR use a hard-coded conditional of if(choice == 5)
		{
			cout << "\nToken Found! You Level Up!" << endl;
			levelUpToken = true;
			addTreasureChest(treasureArray, choice);
			displayInventory(treasureArray);
		}
		else
		{
			addTreasureChest(treasureArray, choice);
			cout << "\n***Treasure inventory updated***" << endl;
			displayInventory(treasureArray);
		}
	}
	
	return 0;
}

// This simply displayes the values of the boolean array.  
// This is more for debugging purposes, but can inform the player.
void displayInventory(bool inventory[])
{
	cout << "Your current inventory is:\n\n";
	cout << "Treasure Slot 1: [" << boolalpha << *inventory << "]" << endl;
	cout << "Treasure Slot 2: [" << boolalpha << *(inventory + 1) << "]" << endl;
	cout << "Treasure Slot 3: [" << boolalpha << *(inventory + 2) << "]" << endl;
	cout << "Treasure Slot 4: [" << boolalpha << *(inventory + 3) << "]" << endl;
	cout << "Treasure Slot 5: [" << boolalpha << *(inventory + 4) << "]" <<endl;
	cout << endl;
}

// Uses pointers to update the array.
void addTreasureChest(bool chest[], int userChoice)
{
	*(chest + (--userChoice)) = true; // userChoice is decremented to account for zero indexing of the treasureArray (or chest).
}