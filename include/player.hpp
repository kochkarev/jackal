#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <array>

#include "gameboard.hpp"
#include "constants.hpp"

class Pirate;

class Player {
public:
	Player(const std::string& name, PlayerColor color); // UNIT TESTED
	void print_general_info(); // TRIVIAL MANUAL TEST
	void print_pirates_info(); // TRIVIAL MANUAL TEST
	void set_ship_pos(int row, int col) { ship_pos = std::make_pair(row, col); } // TRIVIAL
	void set_board(std::shared_ptr<GameBoard> board) { game_board = board; } // TRIVIAL
	void inc_coins() { coins_on_ship++; } // TRIVIAL
	void dec_pirates() { pirates_cnt--;	} // TRIVIAL
	void fix_pirates(Player *ptr); // RATHER TRIVIAL
	bool move_pirate(MoveTypes type, int num);  // MANUAL TEST
	bool move_ship(MoveTypes type); // MANUAL TEST
	bool alive_pirate(int num); // TRIVIAL
	int get_pirates() { return pirates_cnt; } // TRIVIAL
	int get_coins() { return coins_on_ship; } // TRIVIAL
	std::string get_name() { return player_name; } // TRIVIAL
	std::shared_ptr<GameBoard> get_board() { return game_board; } // TRIVIAL
private:
	std::string player_name;
	PlayerColor player_color;
	std::array<std::unique_ptr<Pirate>, 3> pirates;
	std::pair<int, int> ship_pos;
	std::shared_ptr<GameBoard> game_board;
	int pirates_cnt = 3;
	int coins_on_ship = 0;
	bool check_ship_move(MoveTypes type); // UNIT TESTED
	bool check_pirate_move(MoveTypes type, int num); // UNIT TESTED
	std::pair<int, int> new_pos(std::pair<int, int> pos, MoveTypes type); // UNIT TESTED
	friend class TestPlayer;
};

#endif
