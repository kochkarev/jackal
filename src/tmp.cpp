#include <iostream>
#include <ctime>

#include "card.hpp"
#include "constants.hpp"
#include "gameboard.hpp"
#include "game_session.hpp"

int main() {

	srand(time(0));
	GameSession game;
	game.start();

	return 0; 
}
