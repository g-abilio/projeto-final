#include "Jogador.hpp"

#include <iostream>
#include <string>

using namespace std;

/**
 * @class Jogador
 * @brief Classe que armazena informações dos jogadores.
 */


 /**
  * @brief Construtor padrão da classe com dois parâmetros.
  * @param apelido - apelido do jogador sendo apenas uma palavra.
  * @param nome - nome do jogador, podendo ser composto.
  */

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

/**
* @brief Retorna o nome do jogador acessado.
* @return Nome do jogador.
*/

string Jogador::getNome(){
    return(_nome);
}

/**
* @brief Retorna o apelido do jogador acessado.
* @return Nome do apelido.
*/

string Jogador::getApelido(){
    return(_apelido);
}

/**
* @brief Retorna os resultados do jogador acessado no jogo Reversi.
* @return vetor com vitórias e derrotas no Reversi.
*/

int* Jogador::getHistReversi(){
    return(reversi);
}

/**
* @brief Retorna os resultados do jogador acessado no jogo Connect4.
* @return vetor com vitórias e derrotas no Connect4.
*/

int* Jogador::getHistConnect4(){
    return(connect4);
}

/**
* @brief Retorna os resultados do jogador acessado no jogo da Velha.
* @return vetor com vitórias e derrotas no jogo da velha.
*/

int* Jogador::getHistTicTacToe(){
    return(tictactoe);
}

/**
* @brief Adiciona vitórias ou derrotas ao histórico do jogador no jogo Reversi
* @param vitorias - caso tenha vencido a partida.
* @param derrotas - caso tenha pertido a partida.
*/

void Jogador::addHistReversi(int vitorias, int derrotas){
    reversi[0]+=vitorias;
    reversi[1]+=derrotas;
}

/**
* @brief Adiciona vitórias ou derrotas ao histórico do jogador no jogo Connect4
* @param vitorias - caso tenha vencido a partida.
* @param derrotas - caso tenha pertido a partida.
*/

void Jogador::addHistConnect4(int vitorias, int derrotas){
    connect4[0]+=vitorias;
    connect4[1]+=derrotas;
    return;
}

/**
* @brief Adiciona vitórias ou derrotas ao histórico do jogador no jogo da Velha
* @param vitorias - caso tenha vencido a partida.
* @param derrotas - caso tenha pertido a partida.
*/

void Jogador::addHistTicTacToe(int vitorias, int derrotas){
    tictactoe[0]+=vitorias;
    tictactoe[1]+=derrotas;
    return;
}

/**
* @brief Retorna o total de vitórias do jogador considerando todos os jogos.
* @return Soma das vitórias.
*/

int Jogador::getTotalVitorias(){
    return reversi[0] + connect4[0] + tictactoe[0];
}

/**
* @brief Retorna o total de derrotas do jogador considerando todos os jogos.
* @return Soma das derrotas.
*/

int Jogador::getTotalDerrotas(){
    return reversi[1] + connect4[1] + tictactoe[1];
}
