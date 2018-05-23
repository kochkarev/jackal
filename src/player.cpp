#include <iostream>

#include <memory>

#include "player.hpp"

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