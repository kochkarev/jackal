#ifndef __TEST_PLAYER_HPP__
#define __TEST_PLAYER_HPP__

#include <cppunit/extensions/HelperMacros.h>

#include "player.hpp"

class TestPlayer : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(TestPlayer);
	CPPUNIT_TEST(test_check_ship_move);
	CPPUNIT_TEST_SUITE_END();
public:
	void setUp();
	void tearDown();
protected:
	void test_check_ship_move();
	void testInit();
private:
	Player *pl1, *pl2, *pl3, *pl4;
};

#endif