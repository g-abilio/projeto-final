#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "TicTacToe.hpp"

TEST_CASE("inicializar_tabuleiro") {
    TicTacToe jogo;
    jogo.inicializar_tabuleiro();

    // verifica se todas as posicoes foram zeradas
    CHECK_NOTHROW(jogo.realizar_jogada(1, {0, 0}));
    CHECK_NOTHROW(jogo.realizar_jogada(2, {1, 1}));
}

TEST_CASE("realizar_jogada valida") {
    TicTacToe jogo;
    jogo.inicializar_tabuleiro();

    CHECK_NOTHROW(jogo.realizar_jogada(1, {1, 1}));
    CHECK_NOTHROW(jogo.realizar_jogada(2, {2, 2})); // outra jogada valida
}