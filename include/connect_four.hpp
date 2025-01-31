#ifndef CONNECT_FOUR_HPP
#define CONNECT_FOUR_HPP

#include "jogo_tabuleiro.hpp"
#include <iostream>
#include <stdexcept>

class ConnectFour : public JogoTabuleiro {
public:
    // construtor para inicializar o tabuleiro com tamanho padrao (6x7)
    ConnectFour() {
        linhas = 6;
        colunas = 7;
        tabuleiro = std::vector<std::vector<int> >(linhas, std::vector<int>(colunas, 0));
    }

    // inicializa o tabuleiro, preenchendo com zeros
    void inicializar_tabuleiro() override {
        for (auto& linha : tabuleiro) {
            std::fill(linha.begin(), linha.end(), 0);
        }
    }

    // imprime o tabuleiro no console
    void imprimir_tabuleiro() const override {
        for (const auto& linha : tabuleiro) {
            for (const auto& celula : linha) {
                char simbolo = (celula == 0) ? '.' : (celula == 1 ? 'X' : 'O');
                std::cout << simbolo << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    // realiza uma jogada inserindo a peca na coluna especificada
    bool realizar_jogada(int jogador, const std::vector<int>& posicao) override {
        if (posicao.size() != 1) {
            throw std::invalid_argument("connect four requer apenas a coluna");
        }
        int coluna = posicao[0];

        if (coluna < 0 || coluna >= colunas) {
            throw std::invalid_argument("coluna fora do limite");
        }

        for (int i = linhas - 1; i >= 0; --i) {
            if (tabuleiro[i][coluna] == 0) {
                tabuleiro[i][coluna] = jogador;
                return true;
            }
        }

        throw std::runtime_error("coluna cheia");
    }

    // verifica se o jogador atual venceu o jogo
    bool verificar_vitoria(int jogador) const override {
        // verifica linhas
        for (int i = 0; i < linhas; ++i) {
            for (int j = 0; j <= colunas - 4; ++j) {
                if (tabuleiro[i][j] == jogador && tabuleiro[i][j + 1] == jogador &&
                    tabuleiro[i][j + 2] == jogador && tabuleiro[i][j + 3] == jogador) {
                    return true;
                }
            }
        }

        // verifica colunas
        for (int j = 0; j < colunas; ++j) {
            for (int i = 0; i <= linhas - 4; ++i) {
                if (tabuleiro[i][j] == jogador && tabuleiro[i + 1][j] == jogador &&
                    tabuleiro[i + 2][j] == jogador && tabuleiro[i + 3][j] == jogador) {
                    return true;
                }
            }
        }

        // verifica diagonais (cima-esquerda para baixo-direita)
        for (int i = 0; i <= linhas - 4; ++i) {
            for (int j = 0; j <= colunas - 4; ++j) {
                if (tabuleiro[i][j] == jogador && tabuleiro[i + 1][j + 1] == jogador &&
                    tabuleiro[i + 2][j + 2] == jogador && tabuleiro[i + 3][j + 3] == jogador) {
                    return true;
                }
            }
        }

        // verifica diagonais (baixo-esquerda para cima-direita)
        for (int i = 3; i < linhas; ++i) {
            for (int j = 0; j <= colunas - 4; ++j) {
                if (tabuleiro[i][j] == jogador && tabuleiro[i - 1][j + 1] == jogador &&
                    tabuleiro[i - 2][j + 2] == jogador && tabuleiro[i - 3][j + 3] == jogador) {
                    return true;
                }
            }
        }

        return false;
    }

    void boas_vindas() const override {
        std::cout << "Bem-vindo ao Connect4!\n";
    }

};

#endif