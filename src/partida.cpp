#include <iostream>
#include <limits>
#include <map>
#include "partida.hpp"

std::vector<int> Partida::ler_jogada(const JogoTabuleiro& jogo) {
    std::vector<int> posicao;

    if (typeid(jogo) == typeid(ConnectFour)) {
        int coluna;
        while (true) {
            std::cout << "Digite a coluna (0-" << jogo.get_colunas() - 1 << "): ";
            std::cin >> coluna;

            if (std::cin.fail()) {
                std::cout << "Entrada inválida. Digite um número inteiro entre 0 e " << jogo.get_colunas() - 1 << std::endl;
                std::cin.clear(); 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;

            } else {
                posicao.push_back(coluna);
                break;
            }
        }
    } else {
        int linha, coluna;

        while (true) {
            std::cout << "Digite a linha (0-" << jogo.get_linhas() - 1 << "): ";
            std::cin >> linha;

            if (std::cin.fail()) {
                std::cout << "Entrada inválida. Digite um número inteiro entre 0 e " << jogo.get_linhas() - 1 << std::endl;
                std::cin.clear(); 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;

            } else {
                posicao.push_back(linha);
                break;
            }
        }

        while (true) {
            std::cout << "Digite a coluna (0-" << jogo.get_colunas() - 1 << "): ";
            std::cin >> coluna;

            if (std::cin.fail()) {
                std::cout << "Entrada inválida. Digite um número inteiro entre 0 e " << jogo.get_colunas() - 1 << std::endl;
                std::cin.clear(); 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;

            } else {
                posicao.push_back(coluna);
                break;
            }
        }
    }

    return posicao;
}

std::string Partida::jogar_partida(JogoTabuleiro& jogo, std::string jogador_1, std::string jogador_2) {
    jogo.inicializar_tabuleiro();
    int jogador_atual = 1;
    std::map<int, std::string> num_jogador;  
    bool vitoria = false;
    int jogadas_realizadas = 0;

    num_jogador.insert(std::pair<int, std::string>(1, jogador_1));
    num_jogador.insert(std::pair<int, std::string>(2, jogador_2));

    while (!vitoria && jogadas_realizadas < jogo.get_linhas() * jogo.get_colunas()) {
        jogo.imprimir_tabuleiro();

        std::cout << "Jogador " << num_jogador.at(jogador_atual) << ":" << std::endl;
        bool jogada_valida = false;

        while (!jogada_valida) {
            try {
                std::vector<int> jogada = ler_jogada(jogo);
                jogo.realizar_jogada(jogador_atual, jogada);
                jogada_valida = true;
                jogadas_realizadas++;
            }
            catch (const std::invalid_argument& e) {
                std::cerr << "Erro: " << e.what() << std::endl;
            }
            catch (const std::runtime_error& e) {
                std::cerr << "Erro: " << e.what() << std::endl;
            }
        }

        if (jogo.verificar_vitoria(jogador_atual)) {
            vitoria = true;
        } else {
            jogador_atual = (jogador_atual == 1) ? 2 : 1;
        }
    }

    jogo.imprimir_tabuleiro();

    if (vitoria) {
        std::cout << "Jogador " << num_jogador.at(jogador_atual) << " venceu!" << std::endl;
        return num_jogador.at(jogador_atual);
    } else {
        std::cout << "Empate!" << std::endl;
        return " ";
    }
}

std::string Partida::iniciar_jogo(std::string jogo, std::string jogador_1, std::string jogador_2) {
    if (jogo == "R") {
        Reversi reversi;
        return jogar_partida(reversi, jogador_1, jogador_2);
    } else if (jogo == "L") {
        ConnectFour connectfour;
        return jogar_partida(connectfour, jogador_1, jogador_2);
    } else {
        TicTacToe tictactoe;
        return jogar_partida(tictactoe, jogador_1, jogador_2);
    } 
}