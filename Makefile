CC = g++
CFLAGS = -I include -Wall -pedantic-errors -Wextra -std=c++14 -g --coverage

all : 
	$(CC) src/tmp.cpp src/gameboard.cpp src/game_session.cpp src/player.cpp src/card.cpp $(CFLAGS) -o a.out

cover : lcov
	lcov/bin/lcov --capture --directory . --rc lcov_branch_coverage=1 --output-file coverage.info
	lcov/bin/genhtml coverage.info --branch-coverage

lcov :
	git clone https://github.com/linux-test-project/lcov.git

build_obj : gameboard.o game_session.o player.o card.o

gameboard.o : src/gameboard.cpp include/gameboard.hpp
	$(CC) src/gameboard.cpp -c $(CFLAGS) -o obj/gameboard.o

game_session.o : src/game_session.cpp include/game_session.hpp
	$(CC) src/game_session.cpp -c $(CFLAGS) -o obj/game_session.o 

player.o : src/player.cpp include/player.hpp
	$(CC) src/player.cpp -c $(CFLAGS) -o obj/player.o

card.o : src/card.cpp include/card.hpp
	$(CC) src/card.cpp -c $(CFLAGS) -o obj/card.o

test_all : player_test pirate_test

player_test : test/src/TestPlayer.cpp
	$(CC) test/src/TestPlayer.cpp test/src/main_test.cpp src/player.cpp src/gameboard.cpp src/card.cpp -L lib -lcppunit -I include -o player_test
	./player_test

pirate_test : test/src/TestPirate.cpp
	$(CC) test/src/TestPirate.cpp test/src/main_test.cpp src/gameboard.cpp src/card.cpp src/pirate.cpp src/player.cpp -L lib -lcppunit -I include -o pirate_test
	./pirate_test
clean :
	rm obj/*.o
	rm *_test
