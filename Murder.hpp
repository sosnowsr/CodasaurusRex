#ifndef MURDER_HPP
#define MURDER_HPP

class Murder
{
    private: 
        enum gameLocate {BATH, BED, LIVING, KITCHEN, FINISH};
        gameLocate currentRoom;
	    std::string userChoice;
	    std::string playAgain;
        bool gameState;
    
    public:
        Murder(); 
        void storyMove(std::string);
        void gameEnd();
        void playGame();
};

#endif