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
	std::map<CardType, int> left_cards = fill_cards_map();
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (card_allowed_pos(i ,j)) {
				// generate and put card
			}
		}
	}
	// put ships
}

auto GameBoard::fill_cards_map() {
	std::map<CardType, int> left_cards;
	left_cards.insert(std::make_pair(EMPTY, CARDS_EMPT));
	left_cards.insert(std::make_pair(FORTRESS, CARDS_FRT));
	left_cards.insert(std::make_pair(CHEST1, CARDS_CH1));
	left_cards.insert(std::make_pair(CHEST2, CARDS_CH2));
	left_cards.insert(std::make_pair(CHEST3, CARDS_CH3));
	left_cards.insert(std::make_pair(TREASURE, CARDS_TRS));
	left_cards.insert(std::make_pair(ARRUP, CARDS_ARRUP));
	left_cards.insert(std::make_pair(ARRDOWN, CARDS_ARRDOWN));
	left_cards.insert(std::make_pair(ARRRIGHT, CARDS_ARRRIGHT));
	left_cards.insert(std::make_pair(ARRLEFT, CARDS_ARRLEFT));
	left_cards.insert(std::make_pair(MANEATER, CARDS_MEA));
	return left_cards;
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
