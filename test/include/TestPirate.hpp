#ifndef __TEST_PIRATE_HPP__
#define __TEST_PIRATE_HPP__

#include <cppunit/extensions/HelperMacros.h>

#include "../../include/pirate.hpp"
#include "../../include/player.hpp"

class TestPirate : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(TestPirate);
	CPPUNIT_TEST(test_constr);
	CPPUNIT_TEST(test_move);
	CPPUNIT_TEST(test_check_move);
	CPPUNIT_TEST(test_put_coin_on_ship);
	CPPUNIT_TEST(test_put_treasure_on_ship);
	CPPUNIT_TEST_SUITE_END();
public:
	void setUp();
	void tearDown();
protected:
	void test_constr();
	void test_move();
	void test_check_move();
	void test_put_coin_on_ship();
	void test_put_treasure_on_ship();
private:
	Pirate *p1, *p2;
};

#endif