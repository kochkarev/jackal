#ifndef __GAMEBOARD_HPP__
#define __GAMEBOARD_HPP__

#include <vector>
#include <map>
#include <memory>

#include "card.hpp"

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
	friend class TestGameBoard;
};

#endif
