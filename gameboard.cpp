#include <iostream>
#include <vector>
#include <map>
#include <memory>

#include "constants.hpp"
#include "card.hpp"
#include "gameboard.hpp"

void GameBoard::print_board() {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			board[i * BOARD_SIZE + j] -> print_card_up();
			std::cout << " ";
		}
		std::cout << std::endl;
		for (int j = 0; j < BOARD_SIZE; j++) {
			board[i * BOARD_SIZE + j] -> print_card_down();
			std::cout << " ";
		}
		std::cout << std::endl;
		if (i != BOARD_SIZE - 1) {
			for (int k = 0; k < BOARD_SIZE; k++) {
				std::cout << "------";
			}
			std::cout << std::endl;
		}
	}
}

void GameBoard::generate_board() {
	unsigned tmp_card;
	std::map<unsigned, int> left_cards = fill_cards_map();
	board.resize(BOARD_SIZE * BOARD_SIZE); 
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
	board[6] = std::make_shared<ShipCard>(PLC_RED, 0, 6);
	board[6 * BOARD_SIZE] = std::make_shared<ShipCard>(PLC_GREEN, 6, 0);
	board[(BOARD_SIZE - 1) * BOARD_SIZE + 6] = std::make_shared<ShipCard>(PLC_BLUE, BOARD_SIZE - 1, 6);
	board[6 * BOARD_SIZE + BOARD_SIZE - 1] = std::make_shared<ShipCard>(PLC_YELLOW, 6, BOARD_SIZE);
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
	if (row == 0 || row == BOARD_SIZE - 1 || col == 0 || col == BOARD_SIZE - 1) {
		return false;
	} else if (row == 1) {
		if (col == 1 || col == BOARD_SIZE - 2) {
			return false;
		}
	} else if (row == BOARD_SIZE - 2) {
		if (col == 1 || col == BOARD_SIZE - 2) {
			return false;
		}
	} 
	return true;
}

void GameBoard::swap_cards(std::pair<int, int> op1, std::pair<int, int> op2) {
	board[op1.first * BOARD_SIZE + op1.second].swap(board[op2.first * BOARD_SIZE + op2.second]);
}

void Player::print_info() {
	switch (player_color) {
		case PLC_RED:
			std::cout << "\033[0;31m" << player_name << "\033[0m";
			break;
		case PLC_YELLOW:
			std::cout << "\033[1;33m" << player_name << "\033[0m";
			break;
		case PLC_BLUE:
			std::cout << "\033[0;34m" << player_name << "\033[0m";
			break;
		case PLC_GREEN:
			std::cout << "\033[0;32m" << player_name << "\033[0m";
			break;
		case PLC_NOCOLOR:
		default:
			break;
	}
	std::cout << std::endl << pirates_cnt << " pirates" << std::endl;
	std::cout << coins_on_ship << " coins on ship" << std::endl;
}

bool Player::check_ship_move(MoveTypes type) {
	switch (type) {
		case MOVE_UP:
			if (ship_pos.second == 0 || ship_pos.second == BOARD_SIZE - 1) {
				if (ship_pos.first > 2 && ship_pos.first < BOARD_SIZE - 2) {
					return true;
				}
			}
		case MOVE_DOWN:
			if (ship_pos.second == 0 || ship_pos.second == BOARD_SIZE - 1) {
				if (ship_pos.first > 1 && ship_pos.first < BOARD_SIZE - 3) {
					return true;
				}
			}
		case MOVE_LEFT:
			if (ship_pos.first == 0 || ship_pos.first == BOARD_SIZE - 1) {
				if (ship_pos.second > 2 && ship_pos.second < BOARD_SIZE - 2) {
					return true;
				}
			}
		case MOVE_RIGHT:
			if (ship_pos.first == 0 || ship_pos.first == BOARD_SIZE - 1) {
				if (ship_pos.second > 1 && ship_pos.second < BOARD_SIZE - 3) {
					return true;
				}
			}
	}
	return false;
}

bool Player::move_ship(MoveTypes type) {
	if (!check_ship_move(type)) {
		return false;
	}
	switch (type) {
		case MOVE_UP:
			game_board->swap_cards(ship_pos, std::make_pair(ship_pos.first - 1, ship_pos.second));
			break;
		case MOVE_DOWN:
			game_board->swap_cards(ship_pos, std::make_pair(ship_pos.first + 1, ship_pos.second));
			break;
		case MOVE_LEFT:
			game_board->swap_cards(ship_pos, std::make_pair(ship_pos.first, ship_pos.second - 1));
			break;
		case MOVE_RIGHT:
			game_board->swap_cards(ship_pos, std::make_pair(ship_pos.first, ship_pos.second + 1));
			break;
	}
	return true;
}

void GameSession::register_players() {
	std::string name;
	do {
		std::cout << "Enter the number of players (2 to 4): ";
		std::cin >> players_num;
	} while (players_num != 2 && players_num != 3 && players_num != 4);
	for (int i = 0; i < players_num; i++) {
		std::cout << "Enter the name of player #" << i + 1 << ": ";
		std::cin >> name;
		switch (i) {
			case 0:
				std::cout << "The colour of player " << name << " is RED" << std::endl;
				players.push_back(Player(name, PLC_RED));
				break;
			case 1:
				std::cout << "The colour of player " << name << " is YELLOW" << std::endl;
				players.push_back(Player(name, PLC_YELLOW));
				break;
			case 2:
				std::cout << "The colour of player " << name << " is BLUE" << std::endl;
				players.push_back(Player(name, PLC_BLUE));
				break;
			case 3:
				std::cout << "The colour of player " << name << " is GREEN" << std::endl;
				players.push_back(Player(name, PLC_GREEN));
				break;
		}
	}
	std::cout << "Registration finished" << std::endl;
}

void GameSession::start() { // TODO
	int turn = 0;
	int act;
	char move;
	bool move_poss;
	MoveTypes move_type;
	register_players();
	board_ptr = std::make_shared<GameBoard>(players_num);
	for (int i = 0; i < players_num; i++) {
		players[i].set_board(board_ptr);
	}
	while(true) {
		board_ptr->print_board();
		players[turn].print_info();
		std::cout << "Choose action: " << std::endl;
		std::cout << "  1. Move pirate" << std::endl;
		std::cout << "  2. Move ship" << std::endl;
		std::cout << "  3. Finish game" << std::endl;
		do {
			std::cout << "Enter your action (1 to 3): ";
			std::cin >> act;
		} while (act != ACT_MOVE_PIRATE && act != ACT_MOVE_SHIP && act != ACT_FIN_GAME);
		switch (act) {
			case ACT_MOVE_PIRATE:

					// choosing the pirate
					
					do {
						std::cout << "Use W A S D to move the pirate: ";
						std::cin >> move;
					} while (move != 'w' && move != 'a' && move != 's' && move != 'd');

					// performing action
				break;
			case ACT_MOVE_SHIP:
					do {
						std::cout << "Use W A S D to move the ship: ";
						std::cin >> move;
						switch (move) {
							case 'w':
								move_type = MOVE_UP;
								break;
							case 'a':
								move_type = MOVE_LEFT;
								break;
							case 's':
								move_type = MOVE_DOWN;
								break;
							case 'd':
								move_type = MOVE_RIGHT;
								break;
							default:
								std::cout << "Wrong command. Repeat" << std::endl;
						}
						if (!(move_poss = players[turn].move_ship(move_type))) {
							std::cout << "You can not move your ship in that direction. Repeat" << std::endl;
						}
					} while (!move_poss);
				break;
			case ACT_FIN_GAME: 
				std::cout << "The game is finished emergently" << std::endl;
				return;
		}

		std::cout << "The turn is finished" << std::endl;
		turn = (turn + 1) % players_num;
	}
	std::cout << "The game is finished. Winner is " << win_player << std::endl;
}

/*

  |EMP| |CST| | |-->| |^ ^| |
  |2 *| |0 3| | |-->| || || |
  ------------|-------
  |MEN| |   | | |SHP|
  |EAT| |   | | |1  |          
  ------------|------- 


  */
