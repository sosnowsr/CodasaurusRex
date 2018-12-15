// why did i die

#include <iostream>
#include <string>

using std::cout
using std::cin

int main()
{
	/* 
	STILL NEED TO DO:
 	- Implement printing from text files
	- Create function that checks for general valid inputs, so we don't clutter the code with a giant if statement
	- Get rid of all the lazy psuedocode comments for if statements and whatnot
	*/

	bool gameState = true;
	string input;
	string currentRoom = "bath";

	// While gameState == true

		// Print room intro from text file
	
		bool roomChange = false;

		// While roomChange == false && gameState == true
			// Do while validInput == false
				bool validInput = true;
				cout << "What do you do? \n";
				cin >> input;
				// Change input to all lower case
				// If input is a bad input
					validInput = false;

			// If room action input
 				// Print action text from file

			// If switch room input
				currentRoom = input;
				roomChange = true;
						
			// If final guess input && currentRoom == finalRoom
				// If guess is correct
					// Print text from file saying winner
				// If guess is wrong
					// Print text from file saying loser

				cout << "Play again? \n"
				cin >> input;

				// If input == yes
					gameState = true;
					currentRoom = "bath";

				// If input == no
					gameState = false;
					// Maybe print a thank you?

			// If none of the above, maybe print a "nothing happened" message

	return 0;
}
