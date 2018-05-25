#ifndef __TEST_CARD_HPP__
#define __TEST_CARD_HPP__

#include <cppunit/extensions/HelperMacros.h>

#include "../../include/card.hpp"

class TestCard : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(TestPirate);
	CPPUNIT_TEST(test_NoCard_constr);
	CPPUNIT_TEST(test_StandCard_constr);
	CPPUNIT_TEST(test_ShipCard_constr);
	CPPUNIT_TEST_SUITE_END();
public:
	void setUp();
	void tearDown();
protected:
	void test_NoCard_constr();
	void test_StandCard_constr();
	void test_NoStandCard_constr();
	void test_ShipCard_constr();
	void test_NoCard_action();
private:
	NoCard *nocard;
	StandCard *standcard1, *standcard2, *standcard3, *standcard4, *standcard5;
	NoStandCard *nostandcard1, *nostandcard2, *nostandcard3, *nostandcard4, *nostandcard5;
	ShipCard *shipcard1, *shipcard2, *shipcard3, *shipcard4;
}


#endif