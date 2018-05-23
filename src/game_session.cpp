#include <iostream>

#include "game_session.hpp"
#include "gameboard.hpp"
#include "constants.hpp"

void GameSession::register_players() {
	std::string name;
	std::cout << "Enter the number of players (2 to 4): ";
	while (!(std::cin >> players_num) || (std::cin.peek() != '\n') || (players_num != 2 && players_num != 3 && players_num != 4)) {
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "Reenter the number of players (2 to 4): ";
	}
	for (int i = 0; i < players_num; i++) {
		std::cout << "Enter the name of player #" << i + 1 << ": ";
		std::cin >> name;
		switch (i) {
			case 0:
				std::cout << "The colour of player " << name << " is RED" << std::endl;
				players.push_back(Player(name, PLC_RED));
				break;
			case 1:
				std::cout << "The colour of player " << name << " is YELLOW" << std::endl;
				players.push_back(Player(name, PLC_YELLOW));
				break;
			case 2:
				std::cout << "The colour of player " << name << " is BLUE" << std::endl;
				players.push_back(Player(name, PLC_BLUE));
				break;
			case 3:
				std::cout << "The colour of player " << name << " is GREEN" << std::endl;
				players.push_back(Player(name, PLC_GREEN));
				break;
		}
	}
	std::cout << "Registration finished" << std::endl;
}

void GameSession::start() { // TODO
	int turn = 0;
	int act = 0;
	std::string move;
	bool move_poss;
	MoveTypes move_type;
	register_players();
	board_ptr = std::make_shared<GameBoard>(players_num);
	for (int i = 0; i < players_num; i++) {
		players[i].set_board(board_ptr);
	}
	while(true) {
		board_ptr->print_board();
		players[turn].print_info();
		std::cout << "Choose action: " << std::endl;
		std::cout << "  1. Move pirate" << std::endl;
		std::cout << "  2. Move ship" << std::endl;
		std::cout << "  3. Finish game" << std::endl;
		do {
			std::cout << "Enter your action (1 to 3): ";
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> act;
		} while (act != ACT_MOVE_PIRATE && act != ACT_MOVE_SHIP && act != ACT_FIN_GAME);
		switch (act) {
			case ACT_MOVE_PIRATE:
					// choosing the pirate
					do {
						std::cout << "Use W A S D to move the pirate: ";
						std::cin >> move;
					} while (move != "w" && move != "a" && move != "s" && move != "d");
					// performing action
				break;
			case ACT_MOVE_SHIP:
					do {
						std::cout << "Use W A S D to move the ship: ";
						std::cin >> move;
						switch (move[0]) {
							case 'w':
								std::cout << "YOU ASKED FOR MOVING UP" << std::endl;
								move_type = MOVE_UP;
								break;
							case 'a':
								move_type = MOVE_LEFT;
								std::cout << "YOU ASKED FOR MOVING LEFT" << std::endl;
								break;
							case 's':
								move_type = MOVE_DOWN;
								std::cout << "YOU ASKED FOR MOVING DOWN" << std::endl;
								break;
							case 'd':
								move_type = MOVE_RIGHT;
								std::cout << "YOU ASKED FOR MOVING RIGHT" << std::endl;
								break;
							default:
								std::cout << "Wrong command. Repeat" << std::endl;
						}
						if (!(move_poss = players[turn].move_ship(move_type))) {
							std::cout << "You can not move your ship in that direction. Repeat" << std::endl;
						}
					} while (!move_poss);
				break;
			case ACT_FIN_GAME: 
				std::cout << "The game is finished emergently" << std::endl;
				return;
		}

		std::cout << "The turn is finished" << std::endl;
		turn = (turn + 1) % players_num;
	}
	std::cout << "The game is finished. Winner is " << win_player << std::endl;
}