#ifndef __GAMEBOARD_HPP__
#define __GAMEBOARD_HPP__

#include <iostream>
#include <vector>
#include <map>
#include <memory>

class GameBoard;

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
	Player(const std::string& name, PlayerColor color) : player_name(name), player_color(color) {}
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

class GameBoard {
public:
	GameBoard(int players = 4) : players_cnt(players) { generate_board(); }
	void print_board();
	void swap_cards(std::pair<int, int> op1, std::pair<int, int> op2);
private:
	std::vector<std::shared_ptr<Card>> board;
	int players_cnt;
	void generate_board(); 
	std::map<unsigned, int> fill_cards_map();
	bool card_allowed_pos(int row, int col);
};

class GameSession {
public:
	void start(); // TODO
private:
	int players_num;
	bool finished = false;
	std::string win_player;
	std::vector<Player> players;
	std::shared_ptr<GameBoard> board_ptr;
	void register_players();
};

#endif






