#include <iostream>



class Player {
public:

private:
	std::string player_name;
	PlayerColor player_color;
	int pirates_cnt;
	int coins_on_ship;
}

class GameBoard {
public:

private:
	std::vector<std::shared_ptr<Card>> board;
	void generate_board();
	int players_cnt;
};

/*

  |EMP| |CST| | |-->| |^ ^| |
  |2 *| |0 3| | |-->| || || |
  -----------|-------
  |MEN| |CLO| | |SHP|
  |EAT| |SED| | |1  |          
  -----------|------- 


  */
