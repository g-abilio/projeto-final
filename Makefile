all:
	g++ --std=c++11 src/Jogador.cpp src/Reversi.cpp src/ConnectFour.cpp src/TicTacToe.cpp src/Partida.cpp src/Menu.cpp src/main.cpp -Iinclude -o main_partida

run: all
	./main_partida