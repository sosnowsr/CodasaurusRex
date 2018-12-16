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

int main()
{
    // create a Murder class object 
    Murder game;

	// begin game by printing introduction paragraph
	game.storyMove("INTRODUCTION");                                                                         

    // play game until player decides to be finished 
	game.playGame();

	return 0;
}