#include "reversi.hpp"
#include <iostream>
#include <stdexcept>

int main() {
    Reversi jogo;
    jogo.inicializar_tabuleiro();

    std::cout << "=== Bem-vindo ao Reversi ===" << std::endl;
    char jogador = 'X';
    bool jogo_ativo = true;

    while (jogo_ativo) {
        try {
            jogo.imprimir_tabuleiro();
            std::cout << "Jogador " << jogador << ", escolha uma linha e uma coluna (0-7): ";
            int linha, coluna;
            std::cin >> linha >> coluna;

            jogo.realizar_jogada(jogador, {linha, coluna});

            if (jogo.verificar_vitoria(jogador)) {
                std::cout << "Parabens! O jogador " << jogador << " venceu!" << std::endl;
                jogo.imprimir_tabuleiro();
                jogo_ativo = false;
                break;
            }

            // alterna entre os jogadores
            jogador = (jogador == 'X') ? 'O' : 'X';
        } catch (const std::exception& e) {
            std::cout << "Erro: " << e.what() << std::endl;
        }
    }

    return 0;
}