#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "reversi.hpp"

TEST_CASE("inicializar_tabuleiro") {
    Reversi jogo;
    jogo.inicializar_tabuleiro();

    // verifica a posicao inicial padrao do jogo
    CHECK(jogo.realizar_jogada(1, {2, 3}) == false); // posicao invalida no inicio
    CHECK(jogo.realizar_jogada(2, {3, 5}) == false); // posicao invalida no inicio
}

TEST_CASE("realizar_jogada valida") {
    Reversi jogo;
    jogo.inicializar_tabuleiro();

    // realiza uma jogada valida e verifica se retorna true
    CHECK(jogo.realizar_jogada(1, {2, 3}) == false); // nao pode colocar peca aqui
    CHECK(jogo.realizar_jogada(1, {2, 4}) == true);  // jogada valida
}

TEST_CASE("realizar_jogada invalida") {
    Reversi jogo;
    jogo.inicializar_tabuleiro();

    CHECK(jogo.realizar_jogada(1, {0, 0}) == false); // jogada fora da area de jogo
    CHECK(jogo.realizar_jogada(2, {3, 3}) == false); // posicao ja ocupada
}

TEST_CASE("verificar_vitoria") {
    Reversi jogo;
    jogo.inicializar_tabuleiro();

    // antes do tabuleiro estar completamente preenchido, nao ha vitoria
    CHECK(jogo.verificar_vitoria(1) == false);
    CHECK(jogo.verificar_vitoria(2) == false);

    // simula um tabuleiro completo manualmente para testar a vitoria
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            jogo.realizar_jogada((i + j) % 2 + 1, {i, j});
        }
    }

    // com o tabuleiro cheio, o jogo deve indicar que ha uma vitoria
    CHECK(jogo.verificar_vitoria(1) == true);
    CHECK(jogo.verificar_vitoria(2) == true);
}