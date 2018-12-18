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
        void beginGame();
        void endGame();
        void storyMove(std::string);

    public:
        Murder(); 
        void playGame();
};

#endif
