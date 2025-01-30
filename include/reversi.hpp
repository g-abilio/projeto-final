#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "jogo_tabuleiro.hpp"
#include <iostream>
#include <vector>
#include <string>

class Reversi : public JogoTabuleiro {
public:
    Reversi() : simbolos_jogadores("XO") {
        linhas = 8;
        colunas = 8;
<<<<<<< HEAD
        tabuleiro = std::vector<std::vector<int> >(linhas, std::vector<int>(colunas, 0));
=======
        tabuleiro.resize(linhas, std::vector<int>(colunas, 0));
        inicializar_tabuleiro();
>>>>>>> dev-jogo-reversi
    }

    Reversi(const std::string& simbolos_jogadores) : simbolos_jogadores(simbolos_jogadores) {
        linhas = 8;
        colunas = 8;
        tabuleiro.resize(linhas, std::vector<int>(colunas, 0));
        inicializar_tabuleiro();
    }

    ~Reversi() override = default;

    void inicializar_tabuleiro() override {
        limpar_tabuleiro();
        tabuleiro[3][3] = 1;
        tabuleiro[3][4] = 2;
        tabuleiro[4][3] = 2;
        tabuleiro[4][4] = 1;
    }

    void imprimir_tabuleiro() const override {
        for (const auto& linha : tabuleiro) {
            for (int celula : linha) {
                char simbolo = (celula == 0) ? '.' : simbolos_jogadores[celula - 1];
                std::cout << simbolo << " ";
            }
            std::cout << std::endl;
        }
    }

    bool realizar_jogada(int jogador, const std::vector<int>& posicao) override {
        int linha = posicao[0];
        int coluna = posicao[1];

        if (!esta_dentro_do_tabuleiro(linha, coluna) || tabuleiro[linha][coluna] != 0) {
            return false; // posicao invalida ou ja ocupada
        }

        char simbolo_jogador = simbolos_jogadores[jogador - 1];
        tabuleiro[linha][coluna] = jogador;

        for (int incremento_linha = -1; incremento_linha <= 1; incremento_linha++) {
            for (int incremento_coluna = -1; incremento_coluna <= 1; incremento_coluna++) {
                if (incremento_linha || incremento_coluna) {
                    inverter_pecas_direcao(simbolo_jogador, linha, incremento_linha, coluna, incremento_coluna);
                }
            }
        }
        return true;
    }

    bool verificar_vitoria(int jogador) const override {
        for (const auto& linha : tabuleiro) {
            for (int celula : linha) {
                if (celula == 0) {
                    return false;
                }
            }
        }
        return true;
    }

    void exibir_boas_vindas() const {
        std::cout << "Bem-vindo ao Reversi!\n";
    }

    void exibir_resultados() const {
        int contagem[2] = {0, 0};

        for (const auto& linha : tabuleiro) {
            for (int celula : linha) {
                if (celula > 0) {
                    contagem[celula - 1]++;
                }
            }
        }

        std::cout << "Jogador " << simbolos_jogadores[0] << " controla " << contagem[0] << " quadrados.\n";
        std::cout << "Jogador " << simbolos_jogadores[1] << " controla " << contagem[1] << " quadrados.\n";

        if (contagem[0] > contagem[1]) {
            std::cout << "Jogador " << simbolos_jogadores[0] << " vence!\n";
        } else if (contagem[1] > contagem[0]) {
            std::cout << "Jogador " << simbolos_jogadores[1] << " vence!\n";
        } else {
            std::cout << "O jogo terminou empatado\n";
        }
    }

private:
    std::string simbolos_jogadores;

    void inverter_pecas_direcao(char simbolo_jogador, int linha, int incremento_linha, int coluna, int incremento_coluna) {
        int l = linha + incremento_linha;
        int c = coluna + incremento_coluna;
        std::vector<std::pair<int, int>> pecas_para_inverter;

        // converte simbolo para numero (1 para 'X', 2 para 'O')
        int valor_jogador = (simbolo_jogador == 'X') ? 1 : 2;

        // percorre a direcao verificando se pode inverter as pecas
        while (esta_dentro_do_tabuleiro(l, c) && tabuleiro[l][c] != 0 && tabuleiro[l][c] != valor_jogador) {
            pecas_para_inverter.push_back({l, c});
            l += incremento_linha;
            c += incremento_coluna;
        }
        
        // so inverte se terminou em uma peca do jogador atual
        if (esta_dentro_do_tabuleiro(l, c) && tabuleiro[l][c] == valor_jogador) {
            for (const auto& pos : pecas_para_inverter) {
                tabuleiro[pos.first][pos.second] = valor_jogador;
            }
        }
    }

    bool esta_dentro_do_tabuleiro(int linha, int coluna) const {
        return linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas;
    }
};

#endif