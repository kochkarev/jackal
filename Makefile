CC = g++-7
CFLAGS = -I include -Wall -Werror -pedantic-errors -Wextra -std=c++14 -ftrapv -fsanitize=undefined -O2

all : build_obj
	$(CC) src/tmp.cpp obj/gameboard.o obj/game_session.o obj/player.o obj/card.o $(CFLAGS) -o a.out

build_obj : gameboard.o game_session.o player.o card.o

gameboard.o : src/gameboard.cpp include/gameboard.hpp
	$(CC) src/gameboard.cpp -c $(CFLAGS) -o obj/gameboard.o

game_session.o : src/game_session.cpp include/game_session.hpp
	$(CC) src/game_session.cpp -c $(CFLAGS) -o obj/game_session.o 

player.o : src/player.cpp include/player.hpp
	$(CC) src/player.cpp -c $(CFLAGS) -o obj/player.o

card.o : src/card.cpp include/card.hpp
	$(CC) src/card.cpp -c $(CFLAGS) -o obj/card.o

test_all : build_obj player_test

player_test :
	$(CC) test/src/TestPlayer.cpp test/src/main_test.cpp obj/*.o -L lib -lcppunit -i Include -o player_test
clean :
	rm obj/*.o