#include <iostream>

#include <memory>

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
	pirates = std::make_tuple(std::make_unique<Pirate>(ship_pos), std::make_unique<Pirate>(ship_pos), std::make_unique<Pirate>(ship_pos));
	//std::get<0>(pirates)->set_player_ptr(this);
	//std::get<1>(pirates)->set_player_ptr(this);
	//std::get<2>(pirates)->set_player_ptr(this);
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
	int i = 1;
	if (std::get<0>(pirates)->is_alive()) {
		std::cout << "  " << i << ". " << std::get<0>(pirates)->get_pos() << std::endl;
		i++;
	}
	if (std::get<1>(pirates)->is_alive()) {
		std::cout << "  " << i << ". " << std::get<1>(pirates)->get_pos() << std::endl;
		i++;
	}
	if (std::get<2>(pirates)->is_alive()) {
		std::cout << "  " << i++ << ". " << std::get<2>(pirates)->get_pos() << std::endl;
		i++;
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

bool Player::move_ship(MoveTypes type) {
	if (!check_ship_move(type)) {
		return false;
	}
	switch (type) {
		case MOVE_UP:
			game_board->swap_cards(ship_pos, std::make_pair(ship_pos.first - 1, ship_pos.second));
			set_ship_pos(ship_pos.first - 1, ship_pos.second);
			break;
		case MOVE_DOWN:
			game_board->swap_cards(ship_pos, std::make_pair(ship_pos.first + 1, ship_pos.second));
			set_ship_pos(ship_pos.first + 1, ship_pos.second);
			break;
		case MOVE_LEFT:
			game_board->swap_cards(ship_pos, std::make_pair(ship_pos.first, ship_pos.second - 1));
			set_ship_pos(ship_pos.first, ship_pos.second - 1);
			break;
		case MOVE_RIGHT:
			game_board->swap_cards(ship_pos, std::make_pair(ship_pos.first, ship_pos.second + 1));
			set_ship_pos(ship_pos.first, ship_pos.second + 1);
			break;
	}
	return true;
}

bool Player::move_pirate(MoveTypes type, int num) { // true == alive
	
	return true;
}

bool Player::alive_pirate(int num) {
	switch (num) {
		case 0:
			return std::get<0>(pirates)->is_alive();
		case 1:
			return std::get<1>(pirates)->is_alive();
		case 2:
			return std::get<2>(pirates)->is_alive();
		default:
			return false;
	}
}

std::ostream& operator<<(std::ostream &os, const std::pair<int, int> op) {
	os << "(" << op.first << " ; " << op.second << ")";
	return os;
}











