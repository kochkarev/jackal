#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <array>

#include "gameboard.hpp"
#include "card.hpp"
#include "constants.hpp"

class Player;

class Pirate {
public:
	Pirate(std::pair<int, int> new_pos) : pos(new_pos) {}
	bool is_alive() { return alive; }
	bool has_coin() { return carry_coin; }
	bool has_treasure() { return carry_treasure; }
	bool is_on_ship() { return on_ship; }
	std::pair<int, int> get_pos() { return pos; }
	void set_pos(int row, int col) { pos = std::make_pair(row, col); }
	void kill() { alive = false; }
	void take_coin() { carry_coin = true; }
	void throw_coin() { carry_coin = false; }
	void take_treasure() { carry_treasure = true; }
	void throw_treasure() { carry_treasure = false; }
	void go_on_ship() { on_ship = true; }
	void go_from_ship() { on_ship = false; }
	//void set_player_ptr(Player *ptr) { player_ptr.reset(ptr); }
private:
	std::pair<int, int> pos;
	//std::shared_ptr<Player> player_ptr;
	bool alive = true;
	bool carry_coin = false;
	bool carry_treasure = false;
	bool on_ship = true;
	friend class TestPirate;
};

class Player {
public:
	Player(const std::string& name, PlayerColor color);
	void print_general_info();
	void print_pirates_info();
	void set_ship_pos(int row, int col) { ship_pos = std::make_pair(row, col); }
	void set_board(std::shared_ptr<GameBoard> board) { game_board = board; }
	bool move_pirate(MoveTypes type, int num); // TODO
	bool move_ship(MoveTypes type);
	bool alive_pirate(int num);
private:
	std::string player_name;
	PlayerColor player_color;
	//std::tuple<std::unique_ptr<Pirate>, std::unique_ptr<Pirate>, std::unique_ptr<Pirate>> pirates;
	std::array<std::unique_ptr<Pirate>, 3> pirates;
	std::pair<int, int> ship_pos;
	std::shared_ptr<GameBoard> game_board;
	int pirates_cnt = 3;
	int coins_on_ship = 0;
	bool check_ship_move(MoveTypes type);
	std::pair<int, int> new_pos(std::pair<int, int> pos, MoveTypes type);
	friend class TestPlayer;
};

#endif
