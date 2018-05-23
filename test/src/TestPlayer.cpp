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

}

void TestPlayer::testInit() {
	CPPUNIT_ASSERT(pl1->player_name == "PLAYER_1");
	CPPUNIT_ASSERT(pl1->player_color == PLC_RED);
	CPPUNIT_ASSERT(pl2->player_name == "PLAYER_2");
	CPPUNIT_ASSERT(pl1->player_color == PLC_YELLOW);
	CPPUNIT_ASSERT(pl3->player_name == "PLAYER_3");
	CPPUNIT_ASSERT(pl1->player_color == PLC_BLUE);
	CPPUNIT_ASSERT(pl4->player_name == "PLAYER_4");
	CPPUNIT_ASSERT(pl1->player_color == PLC_GREEN);
}
