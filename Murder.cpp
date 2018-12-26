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
    // introduce game and ask user if they want to play
    beginGame();

    // loop that takes user input and displays the game story until they choose to exit
    while (gameState == true)
	    {
		    std::getline(cin, userChoice);
		    storyMove(userChoice);
	    
	        // check to see if player is finished and if they want to play again
	        endGame();  
    }
}

/********************** beginGame ***********************************************
 * This is a private member function includes in playGame. It begins the game by 
 * displaying the TITLE text, then asks the user if they would like to play or not. 
 * If yes, the game begins. If not, the program exits.
 * *******************************************************************************/
void Murder::beginGame()
{
    // display TITLE text, which ends in a Y/N question 
    storyMove("TITLE");
    // get user input (Y or N)
    std::getline(cin, userChoice);

     if (userChoice == "Y" || userChoice == "y")
        {
            storyMove("INTRODUCTION");
        }
        else if (playAgain == "N" || userChoice == "n")
        {
            gameState = false;
            cout << "Until next time!" << endl;
        }
        else 
        {
            cout << "Please type Y or N." << endl;
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
    
    // Changes room state if player is going to another room or if player is finished and wants to haunt
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

    if ((testInput == "[HAUNT MOM]") || (testInput == "[HAUNT JIMMY]") || (testInput == "[HAUNT CAT]"))
    {
        currentRoom = FINISH;
    }
     
    // Special case : Multiple cat encounters
    // needed because there are multiple LOOK CAT story options
    
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
   
    /***** search text files for match to user input *******/
    // if there is a match, print story text. otherwise, tell user to type 
    // something else or to type HELP
    
    string storyLine;                                                               // variable to hold relevant part of story text file
    bool foundText = false;                                                         // true if there is a match
    ifstream myFile ("gameText.txt");                                               // open text file that contains story

    // if text file opens successfully, find match and print text 
    if (myFile.is_open())
    {
        while (!foundText && getline (myFile,storyLine))                             // searches until it finds text or until end of file
        {
            if (storyLine.find(testInput) != string::npos)                           // if string is found, set foundText to true
            {
                foundText = true;
            }
        }

        // if the user's input was found in the text file 
        if (foundText)
        {
            cout << "\n-------------------------------------\n";                     // line added to delineate between sections of story

            // go line by line until another bracket is found, which 
            // indicates another part of the story 
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

                // print relevant part of the story 
                cout << storyLine << "\n";
                
            }
        }
        
        // if user's input is not found in text file, tell them to type something else
        else
        {
                cout << "Type something else, human. Confused? Type HELP for assistance." << endl;
        }
    }

    // if text file cannot be opened, program terminates 
    else    
        exit(1);    
}


/*************** endGame ********************************************************
 * This function tests if the user wants to play the game again. It takes the 
 * current room as input. If the room is FINISH, then the function asks the user
 * if they want to play again. If yes, the game starts again from the beginning.
 * If no, the game ends.
 * *****************************************************************************/
void Murder::endGame()
{
     // see if player is ready to haunt someone and end game 
     if (currentRoom == FINISH)
     {   
        // get user input for whom they want to haunt
        storyMove(userChoice);

        // ask user if they want to play again 
        cout << "\nWould you like to play again? (Y/N)" << endl;
        cin >> playAgain;
        transform(playAgain.begin(), playAgain.end(), playAgain.begin(), ::toupper);
        
        if (playAgain == "Y")
        {
            storyMove("INTRO");
            currentRoom = BATH;
            getline(cin, userChoice);
        }
        else if (playAgain == "N")
        {
            cout << "Thank you for playing MURDER HE WROTE!" << endl;
            gameState = false;
        }
        else 
        {
            cout << "Please type Y or N." << endl;
        }
     }
}
