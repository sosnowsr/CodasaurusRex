/******************************************************************************
** Authors: Codasaurus Rex - 2018 OSU Winter Hackathon
** Description: Header file for the Bathroom class.
******************************************************************************/

#ifndef BATHROOM_HPP
#define BATHROOM_HPP

//Enum variables for different actions and objects.
enum playerActions {LOOK, FLUSH, MOVE, CLEAN};
enum bathObjects {BATHROOM, BODY, GASH, MIRROR, SINK, TUB, TOILET};

class Bathroom
{
	private:
		//Store the player's chosen action.
		playerActions action;
		//Store the player's chosen object.
		bathObjects object;
	public:
		//Default constructor to start the game.
		Bathroom();
		//Return player's chosen action.
		playerActions getAction();
		//Return player's chosen object.
		bathObjects getObject();
}