#include <iostream>
#include <ctime>

#include "game_session.hpp"

int main() {

	srand(time(0));
	GameSession game;
	game.start();

	//GameBoard a;
	//a.get_card(0,0)->print_card_up();

	return 0; 
}
