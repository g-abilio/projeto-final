#ifndef TIC_TAC_TOE_HPP
#define TIC_TAC_TOE_HPP

#include "jogo_tabuleiro.hpp"
#include <iostream>
#include <stdexcept>

class TicTacToe : public JogoTabuleiro {
public:
    // construtor para inicializar o tabuleiro 3x3
    TicTacToe() {
        linhas = 3;
        colunas = 3;
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

    // realiza uma jogada inserindo a peca na posicao especificada
    bool realizar_jogada(int jogador, const std::vector<int>& posicao) override {
        if (posicao.size() != 2) {
            throw std::invalid_argument("tic tac toe requer linha e coluna");
        }
        int linha = posicao[0];
        int coluna = posicao[1];

        if (linha < 0 || linha >= linhas || coluna < 0 || coluna >= colunas) {
            throw std::invalid_argument("posicao fora do limite");
        }

        if (tabuleiro[linha][coluna] != 0) {
            throw std::runtime_error("posicao ja ocupada");
        }

        tabuleiro[linha][coluna] = jogador;
        return true;
    }

    // verifica se o jogador atual venceu o jogo
    bool verificar_vitoria(int jogador) const override {
        // verifica linhas
        for (int i = 0; i < linhas; ++i) {
            if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) {
                return true;
            }
        }

        // verifica colunas
        for (int j = 0; j < colunas; ++j) {
            if (tabuleiro[0][j] == jogador && tabuleiro[1][j] == jogador && tabuleiro[2][j] == jogador) {
                return true;
            }
        }

        // verifica diagonais
        if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) {
            return true;
        }

        if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador) {
            return true;
        }

        return false;
    }

    void boas_vindas() const override {
        std::cout << "Bem-vindo ao Tic Tac Toe!\n";
    }

};

#endif