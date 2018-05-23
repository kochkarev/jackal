#ifndef __GAME_SESSION_HPP
#define __GAME_SESSION_HPP

#include <vector>
#include <memory>

#include "player.hpp"
#include "gameboard.hpp"

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