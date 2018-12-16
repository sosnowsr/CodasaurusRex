/**************************************************************************
Authors: Patricia Booth, Kirsten Corrao, Bryce Hickson, and Robert Sosnowski
Date: 12/16/2018
Description: C++ project for Oregon State University winter hackathon 2018. 
This is a text-based game, similar to those popular in the 1990s. It is a 
murder mystery with a twist--the player is trying to solve their own murder.
****************************************************************************/

// libraries
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>                                                                    // Needed for transform function

// Murder class header file
#include "Murder.hpp"

// standard library 
using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::endl;
using std::getline;

/*********************** Murder constructor ***********************************
 * The Murder class constructor sets the class' variables to the appropriate 
 * values for the beginning of the game.
 * ****************************************************************************/

Murder::Murder()
{
    currentRoom = BATH;
    gameState = true;
}

/*********************** playGame *********************************************
 * This function takes user input and checks if the game is over as long as the 
 * gameState variable is true. (The variable only becomes false if the user says
 * they are finished playing.)
 * ****************************************************************************/

void Murder::playGame()
{
    while (gameState == true)
	    {
		    std::getline(cin, userChoice);
		    storyMove(userChoice);
	    
	        // see if player is finished and if they want to play again
	        gameEnd();  
    }
}

/******************** storyMove ***********************************************
/* Search story text file for user input and determines validity. If the input
is valid, it prints out the next set of instructions. If the input is invalid,
it prompts the user to input an alternate value. 
*******************************************************************************/

void Murder::storyMove (string enteredInput)
{
    string testInput = enteredInput;
    
    // Transform input to uppercase so that user input and text file headings can be compared and 
    // add bracket before and after user input so that headings and input will match
    transform(testInput.begin(), testInput.end(), testInput.begin(), ::toupper);
    testInput.insert(0,"[");
    testInput.append("]");
    
    // if they are a match, then print paragraph from text file that tells the story 

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
            if (currentRoom != FINISH)
            {
                cout << "Please enter a different value. Confused? Type HELP for assistance." << endl;
            }
        }
    }
    // if text file cannot be opened, program terminates 
    else    
        exit(1);    
}


/*************** gameEnd ********************************************************
 * This function tests if the user wants to play the game again. It takes the 
 * current room as input. If the room is FINISH, then the function asks the user
 * if they want to play again. If yes, the game starts again from the beginning.
 * If no, the game ends.
 * *****************************************************************************/
void Murder::gameEnd()
{
     // see if player is ready to haunt someone and end game 
     if (currentRoom == FINISH)
     {   
        // get user input for whom they want to haunt
        getline(cin, userChoice);
        storyMove(userChoice);

        // ask user if they want to play again 
        cout << "Would you like to play again? (Y/N)" << endl;
        cin >> playAgain;
        transform(playAgain.begin(), playAgain.end(), playAgain.begin(), ::toupper);
        
        if (playAgain == "Y")
        {
            storyMove("INTRODUCTION");
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