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
    
    public:
      Murder(); 
      void storyMove(std::string);
      void gameEnd();
      void playGame();
};

#endif
