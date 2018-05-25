#include "../include/TestPirate.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(TestPirate);

void TestPirate::setUp() {
	p1 = new Pirate(std::make_pair(6,0), PLC_GREEN, 0);
	p2 = new Pirate(std::make_pair(0,6), PLC_RED, 2);
}

void TestPirate::tearDown() {
	delete p1;
	delete p2;
}

void TestPirate::test_constr() {
	CPPUNIT_ASSERT(p1->get_pos() == std::make_pair(1,2) && p1->get_color() == PLC_GREEN && p1->get_num() == 0);
	CPPUNIT_ASSERT(p2->get_pos() == std::make_pair(3,0) && p2->get_color() == PLC_RED && p2->get_num() == 2);
}

void TestPirate::test_put_coin_on_ship() {
	Player player("AAA", PLC_RED);
	player.fix_pirates(&player);
	player.pirates[0].take_coin();
	player.pirates[1].take_coin();
	player.pirates[2].take_coin();

	player.pirates[0].put_coin_on_ship();
	CPPUNIT_ASSERT(player.coins_on_ship == 1);
	CPPUNIT_ASSERT(player.pirates[0].has_coin() == false);

	player.pirates[1].put_coin_on_ship();
	CPPUNIT_ASSERT(player.coins_on_ship == 2);
	CPPUNIT_ASSERT(player.pirates[1].has_coin() == false);

	player.pirates[2].put_coin_on_ship();
	CPPUNIT_ASSERT(player.coins_on_ship == 3);
	CPPUNIT_ASSERT(player.pirates[2].has_coin() == false);
}

void TestPirate::test_put_treasure_on_ship() {
	Player player("AAA", PLC_RED);
	player.fix_pirates(&player);
	player.pirates[0].take_treasure();
	player.pirates[1].take_treasure();
	player.pirates[2].take_treasure();

	player.pirates[0].put_treasure_on_ship();
	CPPUNIT_ASSERT(player.coins_on_ship == 5);
	CPPUNIT_ASSERT(player.pirates[0].has_treasure() == false);

	player.pirates[1].put_treasure_on_ship();
	CPPUNIT_ASSERT(player.coins_on_ship == 10);
	CPPUNIT_ASSERT(player.pirates[1].has_treasure() == false);

	player.pirates[2].put_treasure_on_ship();
	CPPUNIT_ASSERT(player.coins_on_ship == 15);
	CPPUNIT_ASSERT(player.pirates[2].has_treasure() == false);
}

void TestPirate::test_move() {
	p1->test_move(MOVE_UP);
	CPPUNIT_ASSERT(p1->get_pos() == std::make_pair(5,0));
	p1->test_move(MOVE_DOWN);
	CPPUNIT_ASSERT(p1->get_pos() == std::make_pair(7,0));
	p1->test_move(MOVE_LEFT);
	CPPUNIT_ASSERT(p1->get_pos() == std::make_pair(6,0));
	p1->test_move(MOVE_RIGHT);
	CPPUNIT_ASSERT(p1->get_pos() == std::make_pair(6,1));

	p2->test_move(MOVE_UP);
	CPPUNIT_ASSERT(p2->get_pos() == std::make_pair(0,6));
	p2->test_move(MOVE_DOWN);
	CPPUNIT_ASSERT(p2->get_pos() == std::make_pair(1,6));
	p2->test_move(MOVE_LEFT);
	CPPUNIT_ASSERT(p2->get_pos() == std::make_pair(0,5));
	p2->test_move(MOVE_RIGHT);
	CPPUNIT_ASSERT(p2->get_pos() == std::make_pair(0,7));
}

void TestPirate::test_check_move() {
	CPPUNIT_ASSERT(p1->check_move(MOVE_UP) == true);
	CPPUNIT_ASSERT(p1->check_move(MOVE_DOWN) == true);
	CPPUNIT_ASSERT(p1->check_move(MOVE_LEFT) == false);
	CPPUNIT_ASSERT(p1->check_move(MOVE_RIGHT) == true);

	CPPUNIT_ASSERT(p2->check_move(MOVE_UP) == false);
	CPPUNIT_ASSERT(p2->check_move(MOVE_DOWN) == true);
	CPPUNIT_ASSERT(p2->check_move(MOVE_LEFT) == true);
	CPPUNIT_ASSERT(p2->check_move(MOVE_RIGHT) == true);
}