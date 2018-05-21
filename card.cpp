#include "card.hpp"
#include "constants.hpp"

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

/*std::ostream& operator<<(std::ostream& os, const NoStandCard& card) {
	if (!card.is_opened()) {
		os << "|CLO|\033[5D\033[1E|SED|\033[1A";
		return os;
	} 
	switch(card.nscard_type) {
		case NSC_ARRUP:
			os << "|\u2191 \u2191|\033[5D\033[1E|\u2191 \u2191|\033[1A";
			break;
		case NSC_ARRDOWN:
			os << "|\u2193 \u2193|\033[5D\033[1E|\u2193 \u2193|\033[1A";
			break;
		case NSC_ARRRIGHT:
			os << "|\u2192 \u2192|\033[5D\033[1E|\u2192 \u2192|\033[1A";
			break;
		case NSC_ARRLEFT:
			os << "|\u2190 \u2190|\033[5D\033[1E|\u2190 \u2190|\033[1A";
			break;
		case NSC_MANEATER:
			os << "|MAN|\033[5D\033[1E|EAT|\033[1A";
			break;
		default:
			throw "BAD NSC_TYPE";
	}
	return os;
}*/

NoStandCard::NoStandCard(NoStandCardType type, int row, int col) {
	card_pos = std::make_pair(row, col);
	opened = true;
	nscard_type = type;
}

void NoStandCard::print_card() {
	if (opened) {
		switch(nscard_type) {
			case NSC_ARRUP:
			std::cout << "|\u2191 \u2191|\033[5D\033[1E|\u2191 \u2191|\033[1A";
			break;
		case NSC_ARRDOWN:
			std::cout << "|\u2193 \u2193|\033[5D\033[1E|\u2193 \u2193|\033[1A";
			break;
		case NSC_ARRRIGHT:
			std::cout << "|\u2192 \u2192|\033[5D\033[1E|\u2192 \u2192|\033[1A";
			break;
		case NSC_ARRLEFT:
			std::cout << "|\u2190 \u2190|\033[5D\033[1E|\u2190 \u2190|\033[1A";
			break;
		case NSC_MANEATER:
			std::cout << "|MAN|\033[5D\033[1E|EAT|\033[1A";
			break;
		default:
			throw "BAD NSC_TYPE";
		}
	} else {
		std::cout << "|CLO|\033[5D\033[1E|SED|\033[1A";
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

/*std::ostream& operator<<(std::ostream& os, const StandCard& card) {
	if (!card.is_opened()) {
		os << "|CLO|\033[5D\033[1E|SED|\033[1A";
		return os;
	}
	os << "|" << card.card_tag << "|\033[5D\033[1E|" << card.pirates_cnt;
	if (card.treasure) {
		if (card.coins_left > 0) {
			os << "*" << card.coins_left << "|\033[1A";
		} else {
			os << " *|\033[1A"; 
		}
	} else {
		if (card.coins_left > 0) {
			os << " " << card.coins_left << "|\033[1A";
		} else {
			os << "  |\033[1A";
		}
	} 
	return os;
}*/

void StandCard::print_card() {
	if (opened) {
		std::cout << "|" << card_tag << "|\033[5D\033[1E|" << pirates_cnt;
		if (treasure) {
			if (coins_left > 0) {
				std::cout << "*" << coins_left << "|\033[1A";
			} else {
				std::cout << " *|\033[1A"; 
			}
		} else {
			if (coins_left > 0) {
				std::cout << " " << coins_left << "|\033[1A";
			} else {
				std::cout << "  |\033[1A";
			}
		}
	} else {
		std::cout << "|CLO|\033[5D\033[1E|SED|\033[1A";
	}
}

/*std::ostream& operator<<(std::ostream& os, const ShipCard& card) {
	os << "|SHP|\033[5D\033[1E|" << card.pirates_cnt << "  |\033[1A";
	return os;
}*/

ShipCard::ShipCard(PlayerColor color, int row, int col) {
	card_pos = std::make_pair(row, col);
	ship_color = color;
	pirates_cnt = 3;
	opened = true;
}

 






