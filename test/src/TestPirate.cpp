#include "../include/TestPirate.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(TestPirate);

void TestPirate::setUp() {
	p1 = new Pirate(std::make_pair(1,2), PLC_GREEN, 0);
	p2 = new Pirate(std::make_pair(3,0), PLC_RED, 2);
}

void TestPirate::tearDown() {
	delete p1;
	delete p2;
}

void TestPirate::test_constr() {
	CPPUNIT_ASSERT(p1->get_pos() == std::make_pair(1,2) && p1->get_color() == PLC_GREEN && p1->get_num() == 0);
	CPPUNIT_ASSERT(p2->get_pos() == std::make_pair(3,0) && p2->get_color() == PLC_RED && p2->get_num() == 2);
}