#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "gameboard.hpp"
#include "card.hpp"
#include "constants.hpp"

class Pirate {
public:
	bool is_alive() { return alive; }
	bool has_coin() { return carry_coin; }
	bool has_treasure() { return carry_treasure; }
	bool is_on_ship() { return on_ship; }
	void set_pos(int row, int col) { pos = std::make_pair(row, col); }
	void kill() { alive = false; }
	void take_coin() { carry_coin = true; }
	void take_treasure() { carry_treasure = true; }
	void go_on_ship() { on_ship = true; }
	void go_from_ship() { on_ship = false; }
private:
	std::pair<int, int> pos;
	bool alive = true;
	bool carry_coin = false;
	bool carry_treasure = false;
	bool on_ship = true;
};

class Player {
public:
	Player(const std::string& name, PlayerColor color);
	void print_info();
	void set_ship_pos(int row, int col) { ship_pos = std::make_pair(row, col); }
	void set_board(std::shared_ptr<GameBoard> board) { game_board = board; }
	bool move_ship(MoveTypes type);
private:
	std::string player_name;
	PlayerColor player_color;
	std::tuple<Pirate, Pirate, Pirate> pirates;
	std::pair<int, int> ship_pos;
	std::shared_ptr<GameBoard> game_board;
	int pirates_cnt = 3;
	int coins_on_ship = 0;
	bool check_ship_move(MoveTypes type);
};

#endif
