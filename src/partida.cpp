#include <iostream>
#include <limits>
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

void Partida::jogar_partida(JogoTabuleiro& jogo) {
    jogo.inicializar_tabuleiro();
    int jogador_atual = 1; 
    bool vitoria = false;
    int jogadas_realizadas = 0;

    while (!vitoria && jogadas_realizadas < jogo.get_linhas() * jogo.get_colunas()) {
        jogo.imprimir_tabuleiro();

        std::cout << "Jogador " << jogador_atual << ":" << std::endl;
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
        std::cout << "Jogador " << jogador_atual << " venceu!" << std::endl;

    } else {
        std::cout << "Empate!" << std::endl;
    }
}

void Partida::iniciar_jogo() {
    int escolha;

    while (true) {
        std::cout << "Escolha um jogo:" << std::endl;
        std::cout << "1. Reversi" << std::endl;
        std::cout << "2. Tic Tac Toe" << std::endl;
        std::cout << "3. Connect Four" << std::endl;
        std::cout << "4. Sair" << std::endl;
        std::cout << "Opcão: ";

        std::cin >> escolha;

        if (std::cin.fail()) {
            std::cout << "Entrada inválida. Digite um número inteiro entre 1 e 4" << std::endl;
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue; 
        }

        if (escolha == 4) {
            break;
        }

        switch (escolha) {
            case 1: {
                Reversi reversi;
                jogar_partida(reversi);
                break;
            }
            case 2: {
                TicTacToe tictactoe;
                jogar_partida(tictactoe);
                break;
            }
            case 3: {
                ConnectFour connectfour;
                jogar_partida(connectfour);
                break;
            }
            default: {
                std::cout << "Entrada inválida. Digite um número inteiro entre 1 e 4" << std::endl;
                break;
            }
        }
    }
}