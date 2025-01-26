#include "connect_four.hpp"
#include <iostream>
#include <stdexcept>

int main() {
    ConnectFour jogo;
    jogo.inicializar_tabuleiro();

    std::cout << "=== Bem-vindo ao Connect Four ===" << std::endl;
    int jogador = 1;
    bool venceu = false;

    while (!venceu) {
        try {
            jogo.imprimir_tabuleiro();
            std::cout << "Jogador " << jogador << ", escolha uma coluna (0-6): ";
            int coluna;
            std::cin >> coluna;

            if (!jogo.realizar_jogada(jogador, coluna)) {
                std::cout << "Jogada invalida. Tente novamente." << std::endl;
                continue;
            }

            if (jogo.verificar_vitoria(jogador)) {
                venceu = true;
                std::cout << "Parabens! O jogador " << jogador << " venceu!" << std::endl;
                jogo.imprimir_tabuleiro();
                break;
            }

            // alterna entre os jogadores
            jogador = (jogador == 1) ? 2 : 1;
        } catch (const std::exception& e) {
            std::cout << "Erro: " << e.what() << std::endl;
        }
    }

    return 0;
}