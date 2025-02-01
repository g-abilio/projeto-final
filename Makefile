all: obj jogo

jogo: obj/ConnectFour.o obj/Jogador.o obj/main.o obj/Menu.o obj/Partida.o obj/Reversi.o obj/TicTacToe.o
	g++ --std=c++11 -Iinclude obj/ConnectFour.o obj/Jogador.o obj/main.o obj/Menu.o obj/Partida.o obj/Reversi.o obj/TicTacToe.o -o jogo

obj/ConnectFour.o: src/ConnectFour.cpp include/ConnectFour.hpp
	g++ --std=c++11 -Iinclude -c src/ConnectFour.cpp -o obj/ConnectFour.o

obj/Jogador.o: src/Jogador.cpp include/Jogador.hpp
	g++ --std=c++11 -Iinclude -c src/Jogador.cpp -o obj/Jogador.o

obj/main.o: src/main.cpp
	g++ --std=c++11 -Iinclude -c src/main.cpp -o obj/main.o

obj/Menu.o: src/Menu.cpp include/Menu.hpp
	g++ --std=c++11 -Iinclude -c src/Menu.cpp -o obj/Menu.o

obj/Partida.o: src/Partida.cpp include/Partida.hpp
	g++ --std=c++11 -Iinclude -c src/Partida.cpp -o obj/Partida.o

obj/Reversi.o: src/Reversi.cpp include/Reversi.hpp
	g++ --std=c++11 -Iinclude -c src/Reversi.cpp -o obj/Reversi.o

obj/TicTacToe.o: src/TicTacToe.cpp include/TicTacToe.hpp
	g++ --std=c++11 -Iinclude -c src/TicTacToe.cpp -o obj/TicTacToe.o

obj:
	mkdir -p obj

clean:
	rm -rf obj jogo testes
