#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "reversi.hpp"

TEST_CASE("inicializar_tabuleiro") {
    Reversi jogo;
    jogo.inicializar_tabuleiro();

    // verifica as pecas iniciais no centro do tabuleiro
    CHECK(jogo.tabuleiro[3][3] == 'X');
    CHECK(jogo.tabuleiro[3][4] == 'O');
    CHECK(jogo.tabuleiro[4][3] == 'O');
    CHECK(jogo.tabuleiro[4][4] == 'X');

    // verifica que as outras posicoes estao vazias
    CHECK(jogo.tabuleiro[0][0] == '.');
    CHECK(jogo.tabuleiro[7][7] == '.');
}

TEST_CASE("realizar_jogada valida") {
    Reversi jogo;
    jogo.inicializar_tabuleiro();

    // jogador 'X' realiza uma jogada valida
    CHECK_NOTHROW(jogo.realizar_jogada('X', {2, 3}));

    // jogador 'O' realiza uma jogada valida
    CHECK_NOTHROW(jogo.realizar_jogada('O', {5, 4}));
}

TEST_CASE("realizar_jogada invalida") {
    Reversi jogo;
    jogo.inicializar_tabuleiro();

    // jogada fora dos limites
    CHECK_THROWS_AS(jogo.realizar_jogada('X', {-1, 3}), std::invalid_argument);
    CHECK_THROWS_AS(jogo.realizar_jogada('X', {8, 8}), std::invalid_argument);

    // jogada em uma posicao ja ocupada
    CHECK_THROWS_AS(jogo.realizar_jogada('X', {3, 3}), std::runtime_error);
}

TEST_CASE("verificar_vitoria") {
    Reversi jogo;
    jogo.inicializar_tabuleiro();

    // simula um estado onde o jogador 'X' tem mais pecas
    jogo.realizar_jogada('X', {2, 3});
    jogo.realizar_jogada('X', {2, 4});
    jogo.realizar_jogada('X', {5, 3});

    CHECK(jogo.verificar_vitoria('X') == true);
    CHECK(jogo.verificar_vitoria('O') == false);
}