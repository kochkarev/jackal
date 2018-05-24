#include "card.hpp"
#include "constants.hpp"
#include "player.hpp"

void StandCard::set_tag() {
	switch (scard_type) {
		case SC_EMPTY:
			card_tag = "EMP";
			break;
		case SC_FORTRESS:
			card_tag = "FRT";
			break;
		case SC_CHEST1:
		case SC_CHEST2:
		case SC_CHEST3:
			card_tag = "CST";
			break;
		case SC_TREASURE:
			card_tag = "TRS";
			break;
		default:
			throw "BAD CARD TYPE";
	}
}

void Card::open_card() {
	if (!opened) {
		opened = true;
	} else {
		throw "REOPENING CARD";
	}
}

NoStandCard::NoStandCard(NoStandCardType type, int row, int col) {
	card_pos = std::make_pair(row, col);
	opened = true;
	nscard_type = type;
}

void NoStandCard::print_card_up() {
	if (opened) {
		switch(nscard_type) {
			case NSC_ARRUP:
			std::cout << "|\u2191 \u2191|";
			break;
		case NSC_ARRDOWN:
			std::cout << "|\u2193 \u2193|";
			break;
		case NSC_ARRRIGHT:
			std::cout << "|\u2192 \u2192|";
			break;
		case NSC_ARRLEFT:
			std::cout << "|\u2190 \u2190|";
			break;
		case NSC_MANEATER:
			std::cout << "|MAN|";
			break;
		default:
			throw "BAD NSC_TYPE";
		}
	} else {
		std::cout << "|CLO|";
	}
}

void NoStandCard::print_card_down() {
	if (opened) {
		switch(nscard_type) {
			case NSC_ARRUP:
			std::cout << "|\u2191 \u2191|";
			break;
		case NSC_ARRDOWN:
			std::cout << "|\u2193 \u2193|";
			break;
		case NSC_ARRRIGHT:
			std::cout << "|\u2192 \u2192|";
			break;
		case NSC_ARRLEFT:
			std::cout << "|\u2190 \u2190|";
			break;
		case NSC_MANEATER:
			std::cout << "|EAT|";
			break;
		default:
			throw "BAD NSC_TYPE";
		}
	} else {
		std::cout << "|SED|";
	}
}

void NoStandCard::action(Pirate& pirate) {
	std::cout << "NoStandCard::action() " << std::endl;
	switch (nscard_type) {
		case NSC_ARRUP:
			break;
		case NSC_ARRDOWN:
			break;
		case NSC_ARRLEFT:
			break;
		case NSC_ARRRIGHT:
			break;
		case MANEATER:
			pirate.kill();
 			pirate.throw_coin();
 			pirate.throw_treasure();
 			pirate.go_from_ship();
			break;
	}
}

StandCard::StandCard(StandCardType type, int row, int col) {
	card_pos = std::make_pair(row, col);
	opened = true;
	scard_type = type;
	pirates_cnt = 0;
	switch(type) {
		case SC_CHEST1:
			coins_left = 1;
			treasure = false;
			break;
		case SC_CHEST2:
			coins_left = 2;
			treasure = false;
			break;
		case SC_CHEST3:
			coins_left = 3;
			treasure = false;
			break;
		case SC_TREASURE:
			coins_left = 0;
			treasure = true;
			break;
		case SC_EMPTY:
		case SC_FORTRESS:
			coins_left = 0;
			treasure = false;
			break;
		default:
			throw "BAD SC_TYPE";
	}
	pirates_color = PLC_NOCOLOR;
	set_tag();
}

void StandCard::print_card_up() {
	if (opened) {
		std::cout << "|" << card_tag << "|";
	} else {
		std::cout << "|CLO|";
	}
}

void StandCard::print_card_down() {
	if (opened) {
		std::cout << "|" << pirates_cnt;
		if (treasure) {
			if (coins_left > 0) {
				std::cout << "*" << coins_left << "|";
			} else {
				std::cout << " *|"; 
			}
		} else {
			if (coins_left > 0) {
				std::cout << " " << coins_left << "|";
			} else {
				std::cout << "  |";
			}
		}
	} else {
		std::cout << "|SED|";
	}
}

void StandCard::action(Pirate &pirate) { // TODO
	std::cout << "HAHA" << std::endl;
}

ShipCard::ShipCard(PlayerColor color, int row, int col) {
	card_pos = std::make_pair(row, col);
	ship_color = color;
	pirates_cnt = 3;
	opened = true;
}

void ShipCard::print_card_up() {
	switch (ship_color) {
		case PLC_RED:
			std::cout << "|\033[0;31mSHP\033[0m|";
			break;
		case PLC_YELLOW:
			std::cout << "|\033[1;33mSHP\033[0m|";
			break;
		case PLC_BLUE:
			std::cout << "|\033[0;34mSHP\033[0m|";
			break;
		case PLC_GREEN:
			std::cout << "|\033[0;32mSHP\033[0m|";
			break;
		case PLC_NOCOLOR:
			std::cout << "|SHP|";
			break;
	}
}

 void ShipCard::print_card_down() {
 	std::cout << "|" << pirates_cnt << "  |";
 }

 void ShipCard::action(Pirate& pirate) {
 	if (pirate.get_color() != ship_color) {
 		std::cout << "GOT ON WRONG SHIP" << std::endl;
 		pirate.kill();
 		pirate.throw_coin();
 		pirate.throw_treasure();
 	} else {
 		pirate.put_coin_on_ship();
 		std::cout << "GOT ON RIGHT SHIP" << std::endl;
 	}
 }

 void NoCard::action(Pirate& pirate) {
 	std::cout << "FALL IN WATER!" << std::endl;
 	pirate.kill();
 	pirate.throw_coin();
 	pirate.throw_treasure();
 	pirate.go_from_ship();
 }

 void NoCard::print_card_up() {
 	std::cout << "|   |";
 }

 void NoCard::print_card_down() {
 	std::cout << "|   |";
 }






