#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "jogo_tabuleiro.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

class Reversi : public JogoTabuleiro {
public:
    // construtor para inicializar o tabuleiro 8x8 vazio
    Reversi() {
        linhas = 8;
        colunas = 8;
        tabuleiro = std::vector<std::vector<int> >(linhas, std::vector<int>(colunas, 0));
    }

    // inicializa o tabuleiro, preenchendo com zeros e colocando as pecas iniciais
    void inicializar_tabuleiro() override {
        for (auto& linha : tabuleiro) {
            std::fill(linha.begin(), linha.end(), 0);
        }
        tabuleiro[3][3] = 1;
        tabuleiro[3][4] = 2;
        tabuleiro[4][3] = 2;
        tabuleiro[4][4] = 1;
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

    // realiza uma jogada no tabuleiro
    bool realizar_jogada(int jogador, const std::vector<int>& posicao) override {
        if (posicao.size() != 2) {
            throw std::invalid_argument("reversi requer linha e coluna");
        }

        int linha = posicao[0];
        int coluna = posicao[1];

        if (linha < 0 || linha >= linhas || coluna < 0 || coluna >= colunas) {
            throw std::invalid_argument("posicao fora do limite");
        }

        if (tabuleiro[linha][coluna] != 0) {
            throw std::runtime_error("posicao ja ocupada");
        }

        // verifica se a jogada eh valida e inverte as pecas
        if (!jogada_valida(jogador, linha, coluna)) {
            throw std::runtime_error("jogada invalida");
        }

        return true;
    }

    // verifica se um jogador venceu
    bool verificar_vitoria(int jogador) const override {
        int contador_jogador = 0;
        int contador_oponente = 0;

        for (const auto& linha : tabuleiro) {
            for (const auto& celula : linha) {
                if (celula == jogador) contador_jogador++;
                else if (celula != 0) contador_oponente++;
            }
        }

        return contador_jogador > contador_oponente;
    }

private:
    // verifica se a jogada eh valida e realiza inversoes das pecas
    bool jogada_valida(int jogador, int linha, int coluna) {
        bool jogada_possivel = false;
        int direcoes[8][2] = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1},
            {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
        };

        for (auto& dir : direcoes) {
            int i = linha + dir[0];
            int j = coluna + dir[1];
            bool encontrou_oponente = false;

            while (i >= 0 && i < linhas && j >= 0 && j < colunas) {
                if (tabuleiro[i][j] == 0) break;
                if (tabuleiro[i][j] == jogador) {
                    if (encontrou_oponente) {
                        // inverte as pecas na direcao
                        int x = linha + dir[0];
                        int y = coluna + dir[1];
                        while (x != i || y != j) {
                            tabuleiro[x][y] = jogador;
                            x += dir[0];
                            y += dir[1];
                        }
                        jogada_possivel = true;
                    }
                    break;
                }
                encontrou_oponente = true;
                i += dir[0];
                j += dir[1];
            }
        }

        if (jogada_possivel) {
            tabuleiro[linha][coluna] = jogador;
        }

        return jogada_possivel;
    }
};

#endif