#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "ConnectFour.hpp"

TEST_CASE("inicializar_tabuleiro") {
    ConnectFour jogo;
    jogo.inicializar_tabuleiro();

    // valida comportamento indiretamente ao tentar realizar jogadas em qualquer posicao
    CHECK_NOTHROW(jogo.realizar_jogada(1, {3}));
}

TEST_CASE("realizar_jogada valida") {
    ConnectFour jogo;
    jogo.inicializar_tabuleiro();

    CHECK_NOTHROW(jogo.realizar_jogada(1, {3})); // jogada valida
    CHECK_NOTHROW(jogo.realizar_jogada(2, {3})); // outra jogada valida na mesma coluna
}

TEST_CASE("realizar_jogada coluna cheia") {
    ConnectFour jogo;
    jogo.inicializar_tabuleiro();

    // preenche a coluna
    for (int i = 0; i < 6; ++i) {
        CHECK_NOTHROW(jogo.realizar_jogada(1, {3}));
    }

    // verifica que a coluna cheia lanca uma excecao
    CHECK_THROWS(jogo.realizar_jogada(1, {3}));
}

TEST_CASE("verificar_vitoria linha") {
    ConnectFour jogo;
    jogo.inicializar_tabuleiro();

    for (int i = 0; i < 4; ++i) {
        CHECK_NOTHROW(jogo.realizar_jogada(1, {i}));
    }

    CHECK(jogo.verificar_vitoria(1) == true);
}

TEST_CASE("verificar_vitoria coluna") {
    ConnectFour jogo;
    jogo.inicializar_tabuleiro();

    for (int i = 0; i < 4; ++i) {
        CHECK_NOTHROW(jogo.realizar_jogada(1, {3}));
    }

    CHECK(jogo.verificar_vitoria(1) == true);
}