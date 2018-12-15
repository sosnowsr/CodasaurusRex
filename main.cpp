// why did i die

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
//#include "Bathroom.hpp"

using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::endl;

int main()
{
    void storyMove (string enteredInput, bool dataValid);
	/* 
	STILL NEED TO DO:
 	- Implement printing from text files
	- Create function that checks for general valid inputs, so we don't clutter the code with a giant if statement
	- Get rid of all the lazy psuedocode comments for if statements and whatnot
	*/

	bool gameState = true;
	bool validInput = false;
	string userChoice;
	string currentRoom = "bath";

	// Print room intro from text file
	storyMove("INTRODUCTION", validInput);
	    
	/*	bool roomChange = false;

		// While roomChange == false && gameState == true
		
		*/
		while (gameState == true)
		{
				cout << "What do you do? \n";
				getline(cin, userChoice);
				storyMove(userChoice, validInput);
				cout << "You entered " << userChoice << endl;
		}
				
        /*
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
*/
	return 0;
}

/* Search story text file for user input and determines validity. If the input
is valid, it prints out the next set of instructions. If the input is invalid,
it prompts the user to input an alternate value. */

void storyMove (string enteredInput, bool dataValid)
{
    string testInput = enteredInput;
    
    // Transform input to uppercase
    
    transform(testInput.begin(), testInput.end(), testInput.begin(), ::toupper);
    testInput.insert(0,"[");
    testInput.append("]");
    
    // Searches text file
    
    string storyLine;
    bool foundText = false;
    ifstream myFile ("textStory.txt");
    if (myFile.is_open())
    {
        while (!foundText && getline (myFile,storyLine))
        {
            if (storyLine.find(testInput) != string::npos)
            {
                foundText = true;
                dataValid = true;
            }
        }
        
        if (foundText)
        {
            cout << "\n";
            
            while (getline(myFile, storyLine))
            {
                /* I formatted each section of text to begin
                with a bracket. The idea behind this is that
                once it sees an opening bracket (the beginning
                of another section) to stop printing text.*/
                
                if (storyLine.find("[") != string::npos)
                {
                    break;
                }
                
                cout << storyLine << endl;
            }
        }
        else
        {
            dataValid = false;
            cout << "Please enter a different value." << endl;
        }
    }
    
}
