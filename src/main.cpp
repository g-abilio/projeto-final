#include "menu.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>

int main() {
    //Abrir o arquivo
    std::ifstream arquivo("jogadores.txt");

    //Verifica se o arquivo existe e se ele abre
    if (arquivo && !arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo.\n";
        return 1;
    }

    std::map<string,Jogador> jogadores_a;
    std::map<string,Jogador> jogadores_n;

    //L� as linhas do arquivo e registra as informa��es dos jogadores em maps
    std::string linha;

    while (std::getline(arquivo, linha)) {
        Jogador Jogador1 = lerLinha(linha);

        jogadores_a.insert(std::pair<std::string, Jogador>(Jogador1.getApelido(),Jogador1));
        jogadores_n.insert(std::pair<std::string, Jogador>(Jogador1.getNome(),Jogador1));
    }

    arquivo.close();

    auto novo_jogadores_a = menuJogos(jogadores_a, jogadores_n);

    //Abrindo o arquivo para grava��o
    std::ofstream historico("jogadores.txt");

    if (!historico.is_open()) {
        std::cerr << "Erro ao abrir o arquivo para escrita.\n";
        return 1;
    }

    for (auto it = novo_jogadores_a.begin(); it != novo_jogadores_a.end(); it++) {
        int* vetor_reversi = it->second.getHistReversi();
        int* vetor_connect4 = it->second.getHistConnect4();
        int* vetor_tictactoe = it->second.getHistTicTacToe();

        historico << it->second.getApelido() << " " << it->second.getNome() << " " << vetor_reversi[0] << " " << vetor_reversi[1]
        << " " << vetor_connect4[0] << " " << vetor_connect4[1] << " " << vetor_tictactoe[0] << " " << vetor_tictactoe[1] << "\n";
    }

    historico.close();

    return 0;
}