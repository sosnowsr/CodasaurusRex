/**************************************************************************
Authors: Patricia Booth, Kirsten Corrao, Bryce Hickson, and Robert Sosnowski
Date: 12/16/2018
Description: C++ project for Oregon State University winter hackathon 2018. 
This is a text-based game, similar to those popular in the 1990s. It is a 
murder mystery with a twist--the player is trying to solve their own murder.
****************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::endl;

int main()
{
    void storyMove (string enteredInput);                                                                       // function prototype
	bool gameState = true;                                                                                      // false means game over
	string userChoice;                                                                                          // string that user enters

	// Print room intro from text file
	storyMove("INTRODUCTION");
	    
	/*	bool roomChange = false;

		// While roomChange == false && gameState == true
		
		*/
		while (gameState == true)
		{
				getline(cin, userChoice);
				storyMove(userChoice);
		}
		return 0;
}

/* Search story text file for user input and determines validity. If the input
is valid, it prints out the next set of instructions. If the input is invalid,
it prompts the user to input an alternate value. */

void storyMove (string enteredInput)
{
    string testInput = enteredInput;
    
    // Transform input to uppercase so that user input and text file headings can be compared and 
    // add bracket before and after user input so that headings and input will match
    transform(testInput.begin(), testInput.end(), testInput.begin(), ::toupper);
    testInput.insert(0,"[");
    testInput.append("]");
    
    // Search text file and compare text file headings to user input
    // if they are a match, then print paragraph from text file that tells the story 
    string storyLine;                                                                                       
    bool foundText = false;                                                                                 // true if user input equals some text in file
    ifstream myFile ("gameText.txt");
    if (myFile.is_open())
    {
        while (!foundText && getline (myFile,storyLine))
        {
            if (storyLine.find(testInput) != string::npos)
            {
                foundText = true;
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
    }
    // if text file cannot be opened, program terminates 
    else    
        exit(1);    
}