#include <iostream>
#include <vector>
#include <map>
#include <memory>

#include "constants.hpp"
#include "card.hpp"

class Player {
public:

private:
	std::string player_name;
	PlayerColor player_color;
	int pirates_cnt;
	int coins_on_ship;
};

class GameBoard {
public:
	GameBoard() { generate_board(); }
private:
	std::vector<std::shared_ptr<Card>> board;
	int players_cnt;
	void generate_board(); 
	std::map<unsigned, int> fill_cards_map();
	bool card_allowed_pos(int row, int col);
};