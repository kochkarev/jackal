#ifndef __CARD_HPP_
#define __CARD_HPP_

#include <iostream>
#include "constants.hpp"

class Card {
public:
	void open_card();
	bool is_opened() const { return opened; }
	virtual void print_card() = 0;
protected:
	std::pair<int, int> card_pos;
	bool opened;
};

class NoStandCard : public Card {
public:
	NoStandCard(NoStandCardType type, int row = -1, int col = -1);
	virtual void print_card();
private:
	NoStandCardType nscard_type;
};

class StandCard : public Card {
public:
	StandCard(StandCardType type, int row = -1, int col = -1);
	virtual void print_card();
private:
	StandCardType scard_type;
	std::string card_tag;
	int pirates_cnt;
	int coins_left;
	bool treasure;
	PlayerColor pirates_color;
	void set_tag();
};

class ShipCard : public Card {
public:
	ShipCard(PlayerColor color, int row = -1, int col = -1);
	virtual void print_card();
private:
	PlayerColor ship_color;
	int pirates_cnt;
};

#endif