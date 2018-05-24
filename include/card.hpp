#ifndef __CARD_HPP_
#define __CARD_HPP_

#include <iostream>
#include "constants.hpp"
//#include "player.hpp"

class Card {
public:
	void open_card();
	bool is_opened() const { return opened; }
	virtual void print_card_up() = 0;
	virtual void print_card_down() = 0;
	//virtual void action() = 0;
protected:
	std::pair<int, int> card_pos;
	bool opened = false;
};

class NoCard : public Card {
public:
	NoCard(int row, int col) { card_pos = std::make_pair(row, col); }
	virtual void print_card_up();
	virtual void print_card_down();
	//virtual void action(const Pirate &pirate); // kill pirate
};

class NoStandCard : public Card {
public:
	NoStandCard(NoStandCardType type, int row, int col);
	virtual void print_card_up();
	virtual void print_card_down();
	//virtual void action(const Pirate &pirate); // kill or move pirate;
private:
	NoStandCardType nscard_type;
};

class StandCard : public Card {
public:
	StandCard(StandCardType type, int row, int col);
	virtual void print_card_up();
	virtual void print_card_down();
	//virtual void action(const Pirate &pirate); // nothing special
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
	ShipCard(PlayerColor color, int row, int col);
	virtual void print_card_up();
	virtual void print_card_down();
	//virtual void action(const Pirate& pirate);
private:
	PlayerColor ship_color;
	int pirates_cnt;
};

#endif