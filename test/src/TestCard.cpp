#include "../include/TestCard.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(TestCard);

void TestCard::setUp() {
	nocard = new NoCard(2,3);
	standcard1 = new StandCard(SC_EMPTY, 2, 3);
	standcard2 = new StandCard(SC_CHEST1, 2, 3);
	standcard3 = new StandCard(SC_CHEST2, 2, 3);
	standcard4 = new StandCard(SC_CHEST3, 2, 3);
	standcard5 = new StandCard(SC_TREASURE, 2, 3);
	nostandcard1 = new NoStandCard(SC_ARRUP, 6, 6);
	nostandcard2 = new NoStandCard(SC_ARRDOWN, 6, 6);
	nostandcard3 = new NoStandCard(SC_ARRLEFT, 6, 6);
	nostandcard4 = new NoStandCard(SC_ARRRIGHT, 6, 6);
	nostandcard5 = new NoStandCard(SC_MANEATER, 6, 6);
	shipcard1 = new ShipCard(PLC_RED, 5, 5);
	shipcard2 = new ShipCard(PLC_YELLOW, 5, 5);
	shipcard3 = new ShipCard(PLC_BLUE, 5, 5);
	shipcard4 = new ShipCard(PLC_GREEN, 5, 5);
}

void TestCard::tearDown() {
	delete nocard;
	delete standcard1;
	delete standcard2;
	delete standcard3;
	delete standcard4;
	delete standcard5;
	delete nostandcard1;
	delete nostandcard2;
	delete nostandcard3;
	delete nostandcard4;
	delete nostandcard5;
	delete shipcard;
}

void TestCard::test_NoCard_constr() {
	CPPUNIT_ASSERT(nocard.card_pos.first == 2 && nocard.card_pos.second == 3);
}

void TestCard::test_StandCard_constr() {
	CPPUNIT_ASSERT(standcard1.scard_type == SC_EMPTY && standcard1.card_pos == std::make_pair(2,3) &&
					standcard1.opened == true && standcard1.pirates_cnt == 0 && standcard1.coins == 0 &&
					standcard1.treasure == false && standcard1.pirtaes_color == PLC_NOCOLOR && standcard1.tag == "EMP");

	CPPUNIT_ASSERT(standcard2.scard_type == SC_CHEST1 && standcard2.card_pos == std::make_pair(2,3) &&
					standcard2.opened == true && standcard2.pirates_cnt == 0 && standcard1.coins == 1 &&
					standcard2.treasure == false && standcard2.pirtaes_color == PLC_NOCOLOR && standcard2.tag == "CH1");

	CPPUNIT_ASSERT(standcard3.scard_type == SC_CHEST2 && standcard3.card_pos == std::make_pair(2,3) &&
					standcard3.opened == true && standcard3.pirates_cnt == 0 && standcard1.coins == 2 &&
					standcard3.treasure == false && standcard3.pirtaes_color == PLC_NOCOLOR && standcard3.tag == "CH2");

	CPPUNIT_ASSERT(standcard4.scard_type == SC_CHEST3 && standcard4.card_pos == std::make_pair(2,3) &&
					standcard4.opened == true && standcard4.pirates_cnt == 0 && standcard4.coins == 3 &&
					standcard4.treasure == false && standcard4.pirtaes_color == PLC_NOCOLOR && standcard4.tag == "CH3");

	CPPUNIT_ASSERT(standcard5.scard_type == SC_TREASURE && standcard5.card_pos == std::make_pair(2,3) &&
					standcard5.opened == true && standcard5.pirates_cnt == 0 && standcard5.coins == 0 &&
					standcard5.treasure == true && standcard5.pirtaes_color == PLC_NOCOLOR && standcard5.tag == "TRS");
}

void TestCard::test_NoStandCard_constr() {
	CPPUNIT_ASSERT(nostandcard1.nscard_type == SC_ARRUP && nostandcard1.card_pos == std::make_pair(6,6) &&
					nostandcard1.opened == true);
	CPPUNIT_ASSERT(nostandcard2.nscard_type == SC_ARRDOWN && nostandcard2.card_pos == std::make_pair(6,6) &&
					nostandcard2.opened == true);
	CPPUNIT_ASSERT(nostandcard3.nscard_type == SC_ARRLEFT && nostandcard3.card_pos == std::make_pair(6,6) &&
					nostandcard3.opened == true);
	CPPUNIT_ASSERT(nostandcard4.nscard_type == SC_ARRRIGHT && nostandcard4.card_pos == std::make_pair(6,6) &&
					nostandcard4.opened == true);
	CPPUNIT_ASSERT(nostandcard5.nscard_type == SC_MANEATER && nostandcard5.card_pos == std::make_pair(6,6) &&
					nostandcard5.opened == true);
}

void TestCard::test_ShipCard_constr() {
	CPPUNIT_ASSERT(shipcard1.ship_color == PLC_RED && shipcard1.ship_pos == std::make_pair(5,5) && shipcard1.pirates_cnt == 3
					&& shipcard1.opened == true);
	CPPUNIT_ASSERT(shipcard2.ship_color == PLC_YELLOW && shipcard2.ship_pos == std::make_pair(5,5) && shipcard2.pirates_cnt == 3
					&& shipcard2.opened == true);
	CPPUNIT_ASSERT(shipcard3.ship_color == PLC_BLUE && shipcard3.ship_pos == std::make_pair(5,5) && shipcard3.pirates_cnt == 3
					&& shipcard1.opened == true);
	CPPUNIT_ASSERT(shipcard4.ship_color == PLC_GREEN && shipcard4.ship_pos == std::make_pair(5,5) && shipcard4.pirates_cnt == 3
					&& shipcard4.opened == true);
}

void TestCard::test_NoCard_action() {
	Player player("AAA", PLC_RED);
	player.fix_pirates(&player);
	nocard->action(*(player.pirates[0]));
	CPPUNIT_ASSERT(player.pirates[0]->alive == false && player.pirates[0]->carry_coin == false && player.pirates[0]->carry_treasure == false
					&& player.pirates[0]->on_ship == false && player.pirates_cnt == 2);
	nocard->action(*(player.pirates[1]));
	CPPUNIT_ASSERT(player.pirates[1]->alive == false && player.pirates[1]->carry_coin == false && player.pirates[1]->carry_treasure == false
					&& player.pirates[1]->on_ship == false && player.pirates_cnt == 1);
	nocard->action(*(player.pirates[2]));
	CPPUNIT_ASSERT(player.pirates[2]->alive == false && player.pirates[2]->carry_coin == false && player.pirates[2]->carry_treasure == false
					&& player.pirates[2]->on_ship == false && player.pirates_cnt == 0);
}




