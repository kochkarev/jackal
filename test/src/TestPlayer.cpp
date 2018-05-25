#include "../include/TestPlayer.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(TestPlayer);

void TestPlayer::setUp() {
	pl1 = new Player("PLAYER_1", PLC_RED);
	pl2 = new Player("PLAYER_2", PLC_YELLOW);
	pl3 = new Player("PLAYER_3", PLC_BLUE);
	pl4 = new Player("PLAYER_4", PLC_GREEN);
}

void TestPlayer::tearDown() {
	delete pl1;
	delete pl2;
	delete pl3;
	delete pl4;
}

void TestPlayer::test_check_ship_move() {
	CPPUNIT_ASSERT(pl1->check_ship_move(MOVE_UP) == false);
	CPPUNIT_ASSERT(pl1->check_ship_move(MOVE_DOWN) == false);
	CPPUNIT_ASSERT(pl1->check_ship_move(MOVE_LEFT) == true);
	CPPUNIT_ASSERT(pl1->check_ship_move(MOVE_RIGHT) == true);

	CPPUNIT_ASSERT(pl2->check_ship_move(MOVE_UP) == true);
	CPPUNIT_ASSERT(pl2->check_ship_move(MOVE_DOWN) == true);
	CPPUNIT_ASSERT(pl2->check_ship_move(MOVE_LEFT) == false);
	CPPUNIT_ASSERT(pl2->check_ship_move(MOVE_RIGHT) == false);

	CPPUNIT_ASSERT(pl3->check_ship_move(MOVE_UP) == false);
	CPPUNIT_ASSERT(pl3->check_ship_move(MOVE_DOWN) == false);
	CPPUNIT_ASSERT(pl3->check_ship_move(MOVE_LEFT) == true);
	CPPUNIT_ASSERT(pl3->check_ship_move(MOVE_RIGHT) == true);

	CPPUNIT_ASSERT(pl4->check_ship_move(MOVE_UP) == true);
	CPPUNIT_ASSERT(pl4->check_ship_move(MOVE_DOWN) == true);
	CPPUNIT_ASSERT(pl4->check_ship_move(MOVE_LEFT) == false);
	CPPUNIT_ASSERT(pl4->check_ship_move(MOVE_RIGHT) == false);

}

void TestPlayer::test_pirate_move() {
	CPPUNIT_ASSERT(pl1->check_pirate_move(MOVE_UP, 0) == false);
	CPPUNIT_ASSERT(pl1->check_pirate_move(MOVE_UP, 1) == false);
	CPPUNIT_ASSERT(pl1->check_pirate_move(MOVE_UP, 2) == false);
	CPPUNIT_ASSERT(pl1->check_pirate_move(MOVE_DOWN, 0) == true);
	CPPUNIT_ASSERT(pl1->check_pirate_move(MOVE_DOWN, 1) == true);
	CPPUNIT_ASSERT(pl1->check_pirate_move(MOVE_DOWN, 2) == true);
	CPPUNIT_ASSERT(pl1->check_pirate_move(MOVE_LEFT, 0) == true);
	CPPUNIT_ASSERT(pl1->check_pirate_move(MOVE_LEFT, 1) == true);
	CPPUNIT_ASSERT(pl1->check_pirate_move(MOVE_LEFT, 2) == true);
	CPPUNIT_ASSERT(pl1->check_pirate_move(MOVE_RIGHT, 0) == true);
	CPPUNIT_ASSERT(pl1->check_pirate_move(MOVE_RIGHT, 1) == true);
	CPPUNIT_ASSERT(pl1->check_pirate_move(MOVE_RIGHT, 2) == true);

	CPPUNIT_ASSERT(pl2->check_pirate_move(MOVE_UP, 0) == true);
	CPPUNIT_ASSERT(pl2->check_pirate_move(MOVE_UP, 1) == true);
	CPPUNIT_ASSERT(pl2->check_pirate_move(MOVE_UP, 2) == true);
	CPPUNIT_ASSERT(pl2->check_pirate_move(MOVE_DOWN, 0) == true);
	CPPUNIT_ASSERT(pl2->check_pirate_move(MOVE_DOWN, 1) == true);
	CPPUNIT_ASSERT(pl2->check_pirate_move(MOVE_DOWN, 2) == true);
	CPPUNIT_ASSERT(pl2->check_pirate_move(MOVE_LEFT, 0) == true);
	CPPUNIT_ASSERT(pl2->check_pirate_move(MOVE_LEFT, 1) == true);
	CPPUNIT_ASSERT(pl2->check_pirate_move(MOVE_LEFT, 2) == true);
	CPPUNIT_ASSERT(pl2->check_pirate_move(MOVE_RIGHT, 0) == false);
	CPPUNIT_ASSERT(pl2->check_pirate_move(MOVE_RIGHT, 1) == false);
	CPPUNIT_ASSERT(pl2->check_pirate_move(MOVE_RIGHT, 2) == false);

	CPPUNIT_ASSERT(pl3->check_pirate_move(MOVE_UP, 0) == true);
	CPPUNIT_ASSERT(pl3->check_pirate_move(MOVE_UP, 1) == true);
	CPPUNIT_ASSERT(pl3->check_pirate_move(MOVE_UP, 2) == true);
	CPPUNIT_ASSERT(pl3->check_pirate_move(MOVE_DOWN, 0) == false);
	CPPUNIT_ASSERT(pl3->check_pirate_move(MOVE_DOWN, 1) == false);
	CPPUNIT_ASSERT(pl3->check_pirate_move(MOVE_DOWN, 2) == false);
	CPPUNIT_ASSERT(pl3->check_pirate_move(MOVE_LEFT, 0) == true);
	CPPUNIT_ASSERT(pl3->check_pirate_move(MOVE_LEFT, 1) == true);
	CPPUNIT_ASSERT(pl3->check_pirate_move(MOVE_LEFT, 2) == true);
	CPPUNIT_ASSERT(pl3->check_pirate_move(MOVE_RIGHT, 0) == true);
	CPPUNIT_ASSERT(pl3->check_pirate_move(MOVE_RIGHT, 1) == true);
	CPPUNIT_ASSERT(pl3->check_pirate_move(MOVE_RIGHT, 2) == true);

	CPPUNIT_ASSERT(pl4->check_pirate_move(MOVE_UP, 0) == true);
	CPPUNIT_ASSERT(pl4->check_pirate_move(MOVE_UP, 1) == true);
	CPPUNIT_ASSERT(pl4->check_pirate_move(MOVE_UP, 2) == true);
	CPPUNIT_ASSERT(pl4->check_pirate_move(MOVE_DOWN, 0) == true);
	CPPUNIT_ASSERT(pl4->check_pirate_move(MOVE_DOWN, 1) == true);
	CPPUNIT_ASSERT(pl4->check_pirate_move(MOVE_DOWN, 2) == true);
	CPPUNIT_ASSERT(pl4->check_pirate_move(MOVE_LEFT, 0) == false);
	CPPUNIT_ASSERT(pl4->check_pirate_move(MOVE_LEFT, 1) == false);
	CPPUNIT_ASSERT(pl4->check_pirate_move(MOVE_LEFT, 2) == false);
	CPPUNIT_ASSERT(pl4->check_pirate_move(MOVE_RIGHT, 0) == true);
	CPPUNIT_ASSERT(pl4->check_pirate_move(MOVE_RIGHT, 1) == true);
	CPPUNIT_ASSERT(pl4->check_pirate_move(MOVE_RIGHT, 2) == true);
}

void TestPlayer::test_new_pos() {
	CPPUNIT_ASSERT(pl1->new_pos(std::make_pair(12, 3), MOVE_UP) == std::make_pair(11, 3));
	CPPUNIT_ASSERT(pl1->new_pos(std::make_pair(12, 3), MOVE_DOWN) == std::make_pair(13, 3));
	CPPUNIT_ASSERT(pl1->new_pos(std::make_pair(12, 3), MOVE_LEFT) == std::make_pair(12, 2));
	CPPUNIT_ASSERT(pl1->new_pos(std::make_pair(12, 3), MOVE_RIGHT) == std::make_pair(12, 4));
}

void TestPlayer::test_constr() {
	CPPUNIT_ASSERT(pl1->player_name == "PLAYER_1");
	CPPUNIT_ASSERT(pl1->player_color == PLC_RED);
	CPPUNIT_ASSERT(pl2->player_name == "PLAYER_2");
	CPPUNIT_ASSERT(pl2->player_color == PLC_YELLOW);
	CPPUNIT_ASSERT(pl3->player_name == "PLAYER_3");
	CPPUNIT_ASSERT(pl3->player_color == PLC_BLUE);
	CPPUNIT_ASSERT(pl4->player_name == "PLAYER_4");
	CPPUNIT_ASSERT(pl4->player_color == PLC_GREEN);
}
