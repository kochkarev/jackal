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

void GameBoard::generate_board() {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (card_allowed_pos(i ,j)) {
				// generate and put card
			}
		}
	}
	// put ships
}

bool GameBoard::card_allowed_pos(int row, int col) {
	if (row == 0 || row == BOARD_SIZE || col == 0 || col == BOARD_SIZE) {
		return false;
	} else if (row == 1) {
		if (col == 1 || col == BOARD_SIZE - 1) {
			return false;
		}
	} else if (row == BOARD_SIZE - 1) {
		if (col == 1 || col == BOARD_SIZE - 1) {
			return false;
		}
	} else {
		return true;
	}
}

/*

  |EMP| |CST| | |-->| |^ ^| |
  |2 *| |0 3| | |-->| || || |
  -----------|-------
  |MEN| |CLO| | |SHP|
  |EAT| |SED| | |1  |          
  -----------|------- 


  */
