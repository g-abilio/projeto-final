all:
	g++ --std=c++11 src/Jogador.cpp src/reversi.cpp src/connect_four.cpp src/tic_tac_toe.cpp src/partida.cpp src/menu.cpp src/main.cpp -Iinclude -o main_partida

run: all
	./main_partida