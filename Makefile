all:
	g++ src/teste_01.cpp -Iinclude -o connect_four

run: all
	./connect_four