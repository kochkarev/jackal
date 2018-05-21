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

	~GameBoard(); 
private:
	std::vector<std::shared_ptr<Card>> board;
	int players_cnt;
	void generate_board(); 
	std::map<CardType, int> fill_cards_map();
	bool card_allowed_pos(int row, int col);
};

void GameBoard::~GameBoard() {
	for (const auto ptr: board) {
		delete ptr;
	}
}

void GameBoard::generate_board() {
	std::map<CardType, int> left_cards = fill_cards_map();
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (card_allowed_pos(i ,j)) {
				do {
					int tmp_card = rand() % CARD_TYPES;
				} while left_cards[tmp_card] <= 0;
				left_cards[tmp_card]--;
				switch (tmp_card) {
					case EMPTY:
					case FORTRESS: 
					case CHEST1: 
					case CHEST2: 
					case CHEST3: 
					case TREASURE:
						board[i * BOARD_SIZE + j] = std::shared_ptr<Card>(new StandCard(tmp_card, i, j));
						break;
					case ARRUP: 
					case ARRDOWN: 
					case ARRRIGHT: 
					case ARRLEFT:  
					case MANEATER: 
						board[i * BOARD_SIZE + j] = std::shared_ptr<Card>(new NoStandCard(tmp_card, i, j));
						break;
					default:
						throw "BAD GENERATED NUMBER";
				}
			} else {
				board[i * BOARD_SIZE + j] = std::shared_ptr<Card>(new NoCard(i, j));
			}
		}
	}
	board[BOARD_SIZE / 2] = std::shared_ptr<Card>(new ShipCard(PLC_RED, 0, BOARD_SIZE / 2));
	board[BOARD_SIZE * BOARD_SIZE] = std::shared_ptr<Card>(new ShipCard(PLC_GREEN, BOARD_SIZE / 2, 0));
	board[BOARD_SIZE * BOARD_SIZE + BOARD_SIZE / 2] = std::shared_ptr<Card>(new ShipCard(PLC_BLUE, BOARD_SIZE, BOARD_SIZE / 2));
	board[BOARD_SIZE * BOARD_SIZE / 2 + BOARD_SIZE] = std::shared_ptr<Card>(new ShipCard(PLC_YELLOW, BOARD_SIZE, BOARD_SIZE / 2));
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
