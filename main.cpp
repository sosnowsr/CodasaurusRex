/**************************************************************************
Authors: Patricia Booth, Kirsten Corrao, Bryce Hickson, and Robert Sosnowski
Date: 12/16/2018
Description: C++ project for Oregon State University winter hackathon 2018. 
This is a text-based game, similar to those popular in the 1990s. It is a 
murder mystery with a twist--the player is trying to solve their own murder.
****************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> // Needed for transform function


using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::endl;

enum gameLocate {BATH, BED, LIVING, KITCHEN, FINISH};
gameLocate currentRoom = BATH;

int main()
{
    void storyMove (string enteredInput, bool dataValid);
   
	bool gameState = true;
	bool validInput = false;
	string userChoice;
	string playAgain;

	// Print room intro from text file
	storyMove("INTRODUCTION", validInput);
	    
	while (gameState == true)
	{
		getline(cin, userChoice);
		storyMove(userChoice, validInput);
	    
	    // Replay
	    if (currentRoom == FINISH)
		{
		    cout << "Would you like to play again? (Y/N)" << endl;
		    cin >> playAgain;
		    transform(playAgain.begin(), playAgain.end(), playAgain.begin(), ::toupper);
		    
		    if (playAgain == "Y")
		    {
		        storyMove("INTRODUCTION", validInput);
		        currentRoom = BATH;
		        getline(cin, userChoice);
		    }
		    else if (playAgain == "N")
		    {
		        cout << "Thank you for playing!" << endl;
		        gameState = false;
		    }
		    else 
		    {
		        cout << "Please type Y or N." << endl;
		    }
            
		}
	}
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
    
    // Changes room state 
    
    if (testInput == "[GO BEDROOM]")
    {
        currentRoom = BED;
    }
    
    if (testInput == "[GO LIVING ROOM]")
    {
        currentRoom = LIVING;
    }
    
    if (testInput == "[GO BATHROOM]")
    {
        currentRoom = BATH;
    }
    
    if (testInput == "[GO KITCHEN]")
    {
        currentRoom = KITCHEN;
    }
    
    // Special case : Multiple cat encounters
    
    if (testInput == "[LOOK CAT]")
    {
        if (currentRoom == BED)
        {
            testInput.append("1");
        }
        
        if (currentRoom == LIVING)
        {
            testInput.append("2");
        }
        
        if (currentRoom == BATH)
        {
            testInput.append("2");
        }
        
        if (currentRoom == KITCHEN)
        {
            testInput.append("3");
        }
    }
    
    // Finishing the game
    
     if ((testInput == "[HAUNT MOM]") || (testInput == "[HAUNT JIMMY]") || (testInput == "[HAUNT CAT]"))
     {
         currentRoom = FINISH;
     }
    
    // Searches text file
    
    string storyLine;
    bool foundText = false;
    ifstream myFile ("gameText.txt");
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
            cout << "--x--\n";
            
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
                
                cout << storyLine << "\n";
                
            }
        }
        else
        {
            dataValid = false;
            if (currentRoom != FINISH)
            {
                cout << "Please enter a different value. Confused? Type HELP for assistance." << endl;
            }
        }
    }
    
}
