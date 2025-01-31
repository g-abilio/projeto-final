#include "tic_tac_toe.hpp"
#include <iostream>
#include <stdexcept>

int main() {
    TicTacToe jogo;
    jogo.inicializar_tabuleiro();

    std::cout << "=== Bem-vindo ao Tic Tac Toe ===" << std::endl;
    int jogador = 1;
    bool venceu = false;

    while (!venceu) {
        try {
            jogo.imprimir_tabuleiro();
            std::cout << "Jogador " << jogador << ", escolha uma linha e uma coluna (0-2): ";
            int linha, coluna;
            std::cin >> linha >> coluna;

            // Corrigir chamada da função realizar_jogada
            jogo.realizar_jogada(jogador, {linha, coluna});

            if (jogo.verificar_vitoria(jogador)) {
                venceu = true;
                std::cout << "Parabéns! O jogador " << jogador << " venceu!" << std::endl;
                jogo.imprimir_tabuleiro();
                break;
            }

            jogador = (jogador == 1) ? 2 : 1;
        } catch (const std::exception& e) {
            std::cout << "Erro: " << e.what() << std::endl;
        }
    }

    return 0;
}