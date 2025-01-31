#include "Jogador.hpp"
#include <string>
#include <vector>
#include <map> 

// Struct auxiliar para ler as linhas do arquivo e gravar na classe jogador
struct Data {
    std::string apelido;
    std::string nome;
    std::vector<int> numeros;
};

bool isNumber(const std::string& str); 

// Função para ler a linha do arquivo e guardar as informa��es na classe jogador
Jogador lerLinha(const std::string& linha);

bool compararRankingGeral(Jogador& a, Jogador& b);

bool compararRankingReversi(Jogador& a, Jogador& b);

bool compararRankingConnect4(Jogador& a,Jogador& b);

bool compararRankingTicTacToe(Jogador& a,Jogador& b);

std::map<string,Jogador> menuJogos(std::map<string,Jogador>& jogadores_a, std::map<string,Jogador>& jogadores_n);