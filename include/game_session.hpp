#ifndef __GAME_SESSION_HPP
#define __GAME_SESSION_HPP

#include <vector>
#include <memory>

#include "player.hpp"
#include "pirate.hpp"
#include "gameboard.hpp"

class GameSession {
public:
	void start(); 
private:
	int players_num;
	bool finished = false;
	std::string win_player;
	std::vector<Player> players;
	std::shared_ptr<GameBoard> board_ptr;
	std::array<std::pair<std::string, PlayerColor>, 4> colors_arr = { 
		std::make_pair("RED", PLC_RED), 
		std::make_pair("YELLOW", PLC_YELLOW), 
		std::make_pair("BLUE", PLC_BLUE), 
		std::make_pair("GREEN", PLC_GREEN) 
	};
	void register_players();
	int check_if_finished();
	void set_win_name_p();
	void set_win_name_c();
	friend class TestGameSession;
};

#endif