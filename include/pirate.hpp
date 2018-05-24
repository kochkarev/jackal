#ifndef __PIRATE_HPP__
#define __PIRATE_HPP__

#include "constants.hpp"
#include <vector>
#include <map>
#include <memory>

class Player;

class Pirate {
public:
	Pirate(std::pair<int, int> new_pos, PlayerColor color, int num_) : pos(new_pos), pirate_color(color), num(num_) {}
	bool is_alive() { return alive; }
	bool has_coin() { return carry_coin; }
	bool has_treasure() { return carry_treasure; }
	bool is_on_ship() { return on_ship; }
	int get_num() { return num; }
	std::pair<int, int> get_pos() { return pos; }
	PlayerColor get_color() { return pirate_color; }
	void set_pos(int row, int col) { pos = std::make_pair(row, col); }
	void kill() { alive = false; }
	void take_coin() { carry_coin = true; }
	void throw_coin() { carry_coin = false; }
	void take_treasure() { carry_treasure = true; }
	void throw_treasure() { carry_treasure = false; }
	void go_on_ship() { on_ship = true; }
	void go_from_ship() { on_ship = false; }
	void put_coin_on_ship();
	void put_treasure_on_ship();
	void set_player_ptr(Player *ptr) { player_ptr = ptr; }
	bool check_move(MoveTypes type);
	bool move(MoveTypes type);
	Player *get_player_ptr() { return player_ptr; }
private:
	std::pair<int, int> pos;
	PlayerColor pirate_color;
	int num;
	Player *player_ptr;
	bool alive = true;
	bool carry_coin = false;
	bool carry_treasure = false;
	bool on_ship = true;
	std::pair<int, int> new_pos(std::pair<int, int> pos, MoveTypes type);
	friend class TestPirate;
};

#endif