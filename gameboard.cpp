#include <iostream>
#include <vector>
#include <map>
#include <memory>

#include "constants.hpp"
#include "card.hpp"

void GameBoard::generate_board() {
	unsigned tmp_card;
	std::map<unsigned, int> left_cards = fill_cards_map();
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (card_allowed_pos(i ,j)) {
				do {
					tmp_card = rand() % CARD_TYPES;
				} while (left_cards[tmp_card] <= 0);
				left_cards[tmp_card]--;
				switch (tmp_card) {
					case EMPTY:
						board[i * BOARD_SIZE + j] = std::make_shared<StandCard>(SC_EMPTY, i, j);
						break;
					case FORTRESS: 
						board[i * BOARD_SIZE + j] = std::make_shared<StandCard>(SC_FORTRESS, i, j);
						break;
					case CHEST1: 
						board[i * BOARD_SIZE + j] = std::make_shared<StandCard>(SC_CHEST1, i, j);
						break;
					case CHEST2:
						board[i * BOARD_SIZE + j] = std::make_shared<StandCard>(SC_CHEST2, i, j);
						break; 
					case CHEST3:
						board[i * BOARD_SIZE + j] = std::make_shared<StandCard>(SC_CHEST3, i, j);
						break; 
					case TREASURE:
						board[i * BOARD_SIZE + j] = std::make_shared<StandCard>(SC_TREASURE, i, j);
						break;
					case ARRUP: 
						board[i * BOARD_SIZE + j] = std::make_shared<NoStandCard>(NSC_ARRUP, i, j);
						break;
					case ARRDOWN: 
						board[i * BOARD_SIZE + j] = std::make_shared<NoStandCard>(NSC_ARRDOWN, i, j);
						break;
					case ARRRIGHT: 
						board[i * BOARD_SIZE + j] = std::make_shared<NoStandCard>(NSC_ARRRIGHT, i, j);
						break;
					case ARRLEFT:  
						board[i * BOARD_SIZE + j] = std::make_shared<NoStandCard>(NSC_ARRLEFT, i, j);
						break;
					case MANEATER: 
						board[i * BOARD_SIZE + j] = std::make_shared<NoStandCard>(NSC_MANEATER, i, j);
						break;
					default:
						throw "BAD GENERATED NUMBER";
				}
			} else {
				board[i * BOARD_SIZE + j] = std::make_shared<NoCard>(i, j);
			}
		}
	}
	board[BOARD_SIZE / 2] = std::make_shared<ShipCard>(PLC_RED, 0, BOARD_SIZE / 2);
	board[BOARD_SIZE * BOARD_SIZE] = std::make_shared<ShipCard>(PLC_GREEN, BOARD_SIZE / 2, 0);
	board[BOARD_SIZE * BOARD_SIZE + BOARD_SIZE / 2] = std::make_shared<ShipCard>(PLC_BLUE, BOARD_SIZE, BOARD_SIZE / 2);
	board[BOARD_SIZE * BOARD_SIZE / 2 + BOARD_SIZE] = std::make_shared<ShipCard>(PLC_YELLOW, BOARD_SIZE, BOARD_SIZE / 2);
}

std::map<unsigned, int> GameBoard::fill_cards_map() {
	std::map<unsigned, int> left_cards;
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
  ------------|-------
  |MEN| |   | | |SHP|
  |EAT| |   | | |1  |          
  ------------|------- 


  */
