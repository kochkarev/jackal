#ifndef __CARD_HPP_
#define __CARD_HPP_

#include <iostream>
#include "constants.hpp"
#include "pirate.hpp"

class Pirate;
class Player;

class Card {
public:
	void open_card();
	bool is_opened() const { return opened; }
	virtual bool remove_pirate() { return true; }
	virtual void print_card_up() = 0;
	virtual void print_card_down() = 0;
	virtual void action(Pirate &pirate) = 0;
protected:
	std::pair<int, int> card_pos;
	bool opened = false;
};

class NoCard : public Card {
public:
	NoCard(int row, int col) { card_pos = std::make_pair(row, col); }
	virtual void print_card_up();
	virtual void print_card_down();
	virtual void action(Pirate &pirate); 
};

class NoStandCard : public Card {
public:
	NoStandCard(NoStandCardType type, int row, int col);
	virtual void print_card_up();
	virtual void print_card_down();
	virtual void action(Pirate &pirate); 
private:
	NoStandCardType nscard_type;
};

class StandCard : public Card {
public:
	StandCard(StandCardType type, int row, int col);
	virtual void print_card_up();
	virtual void print_card_down();
	virtual void action(Pirate &pirate); 
	virtual bool remove_pirate() override;
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
	virtual void action(Pirate& pirate);
	virtual bool remove_pirate() override;
private:
	PlayerColor ship_color;
	int pirates_cnt = 3;
};

#endif