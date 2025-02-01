#include "Menu.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>

int main() {

/**
 * @file jogadores.txt
 * @brief Leitura do histórico dos jogadores gravados a cada execução.
 *
 * Este arquivo contém os atributos dos jogadores em ordem de leitura:
 * apelido, nome, e seis inteiros que são as vitórias e derrotas nos jogos.
 */

    //Abrir o arquivo
    std::ifstream arquivo("data/jogadores.txt");

    //Verifica se o arquivo existe e se ele abre
    if (arquivo && !arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo.\n";
        return 1;
    }

    std::map<string,Jogador> jogadores_a;
    std::map<string,Jogador> jogadores_n;

    //Le as linhas do arquivo e registra as informacoes dos jogadores em maps
    std::string linha;

    while (std::getline(arquivo, linha)) {
        Jogador Jogador1 = lerLinha(linha);

        jogadores_a.insert(std::pair<std::string, Jogador>(Jogador1.getApelido(),Jogador1));
        jogadores_n.insert(std::pair<std::string, Jogador>(Jogador1.getNome(),Jogador1));
    }

    arquivo.close();

    auto novo_jogadores_a = menuJogos(jogadores_a, jogadores_n);

    /**
    * @file jogadores.txt
    * @brief Gravação do histórico dos jogadores após execução do código.
    *
    * Este arquivo grava os atributos dos jogadores após execuções
    * de partidas e cadastro e remoção de jogadores.
    */

    //Abrindo o arquivo para gravacao
    std::ofstream historico("data/jogadores.txt");

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