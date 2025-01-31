#include "tic_tac_toe.hpp"

TicTacToe::TicTacToe() {
    linhas = 3;
    colunas = 3;
    tabuleiro = std::vector<std::vector<int> >(linhas, std::vector<int>(colunas, 0));
}

void TicTacToe::inicializar_tabuleiro() {
    for (auto& linha : tabuleiro) {
        std::fill(linha.begin(), linha.end(), 0);
    }
}

void TicTacToe::imprimir_tabuleiro() const {
    for (const auto& linha : tabuleiro) {
        for (const auto& celula : linha) {
            char simbolo = (celula == 0) ? '.' : (celula == 1 ? 'X' : 'O');
            std::cout << simbolo << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool TicTacToe::realizar_jogada(int jogador, const std::vector<int>& posicao) {
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

bool TicTacToe::verificar_vitoria(int jogador) const {
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

void TicTacToe::boas_vindas() const {
    std::cout << "Bem-vindo ao Tic Tac Toe!\n";
}