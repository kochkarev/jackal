#include <iostream>

#include <memory>
#include <array>

#include "pirate.hpp"
#include "player.hpp"


std::ostream& operator<<(std::ostream &os, const std::pair<int, int> op);

Player::Player(const std::string& name, PlayerColor color) {
	player_name = name;
	player_color = color;
	switch (color) {
		case PLC_RED:
			ship_pos = std::make_pair(0, 6);
			break;
		case PLC_YELLOW:
			ship_pos = std::make_pair(6, BOARD_SIZE - 1);
			break;
		case PLC_BLUE:
			ship_pos = std::make_pair(BOARD_SIZE - 1, 6);
			break;
		case PLC_GREEN:
			ship_pos = std::make_pair(6, 0);
			break;
		case PLC_NOCOLOR:
		default:
			break;
	}
	for (int i = 0; i < 3; i++) {
		pirates[i] = std::make_unique<Pirate>(ship_pos, color, this);
	}
}

void Player::print_general_info() {
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
	std::cout << std::endl << "Pirates: " << pirates_cnt << std::endl;
	std::cout << "Coins on ship: " << coins_on_ship << std::endl;
}

void Player::print_pirates_info() {
	for (int i = 0; i < 3; i++) {
		if (pirates[i]->is_alive()) {
			std::cout << "  " << i + 1 << ". " << pirates[i]->get_pos();
			if (pirates[i]->has_coin()) {
				std::cout << " carrying 1 coin" << std::endl;
			} else if (pirates[i]->has_treasure()) {
				std::cout << " carrying treasure" << std::endl;
			} else {
				std::cout << std::endl;
			}
		}
	}
}

bool Player::check_ship_move(MoveTypes type) {
	switch (type) {
		case MOVE_UP:
			if (ship_pos.second == 0 || ship_pos.second == BOARD_SIZE - 1) {
				if (ship_pos.first > 2 && ship_pos.first < BOARD_SIZE - 2) {
					return true;
				}
			} 
			return false;
		case MOVE_DOWN:
			if (ship_pos.second == 0 || ship_pos.second == BOARD_SIZE - 1) {
				if (ship_pos.first > 1 && ship_pos.first < BOARD_SIZE - 3) {
					return true;
				}
			}
			return false;
		case MOVE_LEFT:
			if (ship_pos.first == 0 || ship_pos.first == BOARD_SIZE - 1) {
				if (ship_pos.second > 2 && ship_pos.second < BOARD_SIZE - 2) {
					return true;
				}
			}
			return false;
		case MOVE_RIGHT:
			if (ship_pos.first == 0 || ship_pos.first == BOARD_SIZE - 1) {
				if (ship_pos.second > 1 && ship_pos.second < BOARD_SIZE - 3) {
					return true;
				}
			}
			return false;
	}
	return false;
}

bool Player::check_pirate_move(MoveTypes type, int num) {
	auto tmp = new_pos(pirates[num]->get_pos(), type);
	if (tmp.first < 0 || tmp.first > BOARD_SIZE - 1 || tmp.second < 0 || tmp.second > BOARD_SIZE - 1) {
		return false;
	}
	return true;
}

std::pair<int, int> Player::new_pos(std::pair<int, int> pos, MoveTypes type) {
	switch (type) {
		case MOVE_UP:
			return std::make_pair(pos.first - 1, pos.second);
		case MOVE_DOWN:
			return std::make_pair(pos.first + 1, pos.second);
		case MOVE_LEFT:
			return std::make_pair(pos.first, pos.second - 1);
		case MOVE_RIGHT:
			return std::make_pair(pos.first, pos.second + 1);
		default:
			throw "err";
	}
}

std::pair<int, int> Pirate::new_pos(std::pair<int, int> pos, MoveTypes type) {
	switch (type) {
		case MOVE_UP:
			return std::make_pair(pos.first - 1, pos.second);
		case MOVE_DOWN:
			return std::make_pair(pos.first + 1, pos.second);
		case MOVE_LEFT:
			return std::make_pair(pos.first, pos.second - 1);
		case MOVE_RIGHT:
			return std::make_pair(pos.first, pos.second + 1);
		default:
			throw "err";
	}
}

bool Player::move_ship(MoveTypes type) {
	if (!check_ship_move(type)) {
		return false;
	}
	std::pair<int, int> tmp = new_pos(ship_pos, type);
	game_board->swap_cards(ship_pos, tmp);
	set_ship_pos(tmp.first, tmp.second);
	for (int i = 0; i < 3; i++) {
		if (pirates[i]->is_on_ship()) {
			pirates[i]->set_pos(tmp.first, tmp.second);
		}
	}
	return true;
}

bool Player::move_pirate(MoveTypes type, int num) {  
	std::cout << "going to move the pirate" << std::endl;
	game_board->get_card(pirates[num]->get_pos().first, pirates[num]->get_pos().second)->remove_pirate();
	std::cout << "pirate removed\n";
	if (!pirates[num]->move(type)) {
		return false;
	}
	std::cout << "Player::move_pirate() going to make action\n";
	game_board->get_card(pirates[num]->get_pos().first, pirates[num]->get_pos().second)->action(*pirates[num]);
	return true;
}

bool Player::alive_pirate(int num) {
	return pirates[num]->is_alive();
}

std::ostream& operator<<(std::ostream &os, const std::pair<int, int> op) {
	os << "(" << op.first << " ; " << op.second << ")";
	return os;
}

bool Pirate::check_move(MoveTypes type) {
	auto tmp = new_pos(pos, type);
	if (tmp.first < 0 || tmp.first > BOARD_SIZE - 1 || tmp.second < 0 || tmp.second > BOARD_SIZE - 1) {
		return false;
	}
	return true;
}

bool Pirate::move(MoveTypes type) {
	if (!check_move(type)) {
		return false;
	}
	pos = new_pos(pos, type);
	//std::cout << "Pirate::move -> position set to " << pos <<" , going to move" << std::endl;
	return true;
}

void Pirate::put_coin_on_ship() {
	player_ptr->inc_coins(); 
	carry_coin = false;
}

void Pirate::put_treasure_on_ship() {
	player_ptr->inc_coins();
	player_ptr->inc_coins();
	player_ptr->inc_coins();
	player_ptr->inc_coins();
	player_ptr->inc_coins();
	carry_treasure = false;
}











