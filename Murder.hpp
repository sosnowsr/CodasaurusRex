#ifndef MURDER_HPP
#define MURDER_HPP

enum gameLocate {BATH, BED, LIVING, KITCHEN, FINISH};

class Murder
{
    private: 
        gameLocate currentRoom;
	std::string userChoice;
	std::string playAgain;
        bool gameState;
        void beginGame();
        void endGame();
        void storyMove(std::string);


    public:
        Murder(); 
        void playGame();
};

#endif
