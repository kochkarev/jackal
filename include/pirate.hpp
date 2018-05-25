#ifndef __PIRATE_HPP__
#define __PIRATE_HPP__

#include "constants.hpp"
#include <vector>
#include <map>
#include <memory>

class Player;

class Pirate {
public:
	Pirate(std::pair<int, int> new_pos, PlayerColor color, int num_) : pos(new_pos), pirate_color(color), num(num_) {} // UNIT TESTED
	bool is_alive() { return alive; } // TRIVIAL
	bool has_coin() { return carry_coin; } // TRIVIAL
	bool has_treasure() { return carry_treasure; } // TRIVIAL
	bool is_on_ship() { return on_ship; } // TRIVIAL
	int get_num() { return num; } // TRIVIAL
	std::pair<int, int> get_pos() { return pos; } // TRIVIAL
	PlayerColor get_color() { return pirate_color; } // TRIVIAL
	void set_pos(int row, int col) { pos = std::make_pair(row, col); } // TRIVIAL
	void kill() { alive = false; } // TRIVIAL
	void take_coin() { carry_coin = true; } // TRIVIAL
	void throw_coin() { carry_coin = false; } // TRIVIAL
	void take_treasure() { carry_treasure = true; } // TRIVIAL
	void throw_treasure() { carry_treasure = false; } // TRIVIAL
	void go_on_ship() { on_ship = true; } // TRIVIAL
	void go_from_ship() { on_ship = false; } // TRIVIAL
	void put_coin_on_ship(); // INTEGRATE TESTED
	void put_treasure_on_ship(); // INTEGRATE TESTED
	void set_player_ptr(Player *ptr) { player_ptr = ptr; } // TRIVIAL
	bool check_move(MoveTypes type); // UNIT TESTED
	bool move(MoveTypes type); // UNIT TESTED
	Player *get_player_ptr() { return player_ptr; } // TRIVIAL
private:
	std::pair<int, int> pos;
	PlayerColor pirate_color;
	int num;
	Player *player_ptr;
	bool alive = true;
	bool carry_coin = false;
	bool carry_treasure = false;
	bool on_ship = true;
	std::pair<int, int> new_pos(std::pair<int, int> pos, MoveTypes type); // THE SAME WAS TESTED IN TEST_PLAYER

	friend class TestPlayer; // TESTING CLASS FOR CPPUNIT
	friend class TestPirate; // TESTING CLASS FOR CPPUNIT
	friend class TestCard; // TESTING CLASS FOR CPPUNIT
};

#endif