#include "Jogador.hpp"

#include <iostream>
#include <string>

using namespace std;

Jogador::Jogador(string apelido, string nome){
    _apelido = apelido;
    _nome = nome;
    for (int i=0; i<2; i++){
        reversi[i]=0;
        connect4[i]=0;
        tictactoe[i]=0;
    }
}

/*Jogador::~Jogador(){
    delete[] reversi;
    delete[] connect;
    delete[] tictactoe;
}*/


string Jogador::getNome(){
    return(_nome);
}

string Jogador::getApelido(){
    return(_apelido);
}

int* Jogador::getHistReversi(){
    return(reversi);
}

int* Jogador::getHistConnect4(){
    return(connect4);
}

int* Jogador::getHistTicTacToe(){
    return(tictactoe);
}
void Jogador::addHistReversi(int vitorias, int derrotas){
    reversi[0]+=vitorias;
    reversi[1]+=derrotas;
}

void Jogador::addHistConnect4(int vitorias, int derrotas){
    connect4[0]+=vitorias;
    connect4[1]+=derrotas;
    return;
}

void Jogador::addHistTicTacToe(int vitorias, int derrotas){
    tictactoe[0]+=vitorias;
    tictactoe[1]+=derrotas;
    return;
}

int Jogador::getTotalVitorias(){
    return reversi[0] + connect4[0] + tictactoe[0];
}

int Jogador::getTotalDerrotas(){
    return reversi[1] + connect4[1] + tictactoe[1];
}
