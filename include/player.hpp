#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <array>

#include "gameboard.hpp"
#include "constants.hpp"

class Pirate;

class Player {
public:
	Player(const std::string& name, PlayerColor color);
	void print_general_info();
	void print_pirates_info();
	void set_ship_pos(int row, int col) { ship_pos = std::make_pair(row, col); }
	void set_board(std::shared_ptr<GameBoard> board) { game_board = board; }
	void inc_coins() { coins_on_ship++; }
	void dec_pirates() { pirates_cnt--;	}
	void fix_pirates(Player *ptr);
	bool move_pirate(MoveTypes type, int num);
	bool move_ship(MoveTypes type);
	bool alive_pirate(int num);
	int get_pirates() { return pirates_cnt; }
	int get_coins() { return coins_on_ship; }
	std::string get_name() { return player_name; }
	std::shared_ptr<GameBoard> get_board() { return game_board; }
private:
	std::string player_name;
	PlayerColor player_color;
	std::array<std::unique_ptr<Pirate>, 3> pirates;
	std::pair<int, int> ship_pos;
	std::shared_ptr<GameBoard> game_board;
	int pirates_cnt = 3;
	int coins_on_ship = 0;
	bool check_ship_move(MoveTypes type);
	bool check_pirate_move(MoveTypes type, int num);
	std::pair<int, int> new_pos(std::pair<int, int> pos, MoveTypes type);
	friend class TestPlayer;
};

#endif
