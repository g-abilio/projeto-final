#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include <iostream>
#include <string>

using namespace std;

class Jogador{
protected:
    string _apelido;
    string _nome;
    int reversi[2];
    int connect4[2];
    int tictactoe[2];

public:

    Jogador(string apelido, string nome);

    //~Jogador();

    string getNome();
    string getApelido();

    int* getHistReversi ();
    int* getHistConnect4 ();
    int* getHistTicTacToe ();

    void addHistReversi(int vitorias, int derrotas);
    void addHistConnect4(int vitorias, int derrotas);
    void addHistTicTacToe(int vitorias, int derrotas);

    int getTotalVitorias();
    int getTotalDerrotas();
};

#endif
