#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "reversi.hpp"

TEST_CASE("verificar_vitoria") {
    Reversi jogo;
    jogo.inicializar_tabuleiro();

    // antes do tabuleiro estar completamente preenchido, nao ha vitoria
    CHECK(jogo.verificar_vitoria(1) == false);
    CHECK(jogo.verificar_vitoria(2) == false);

    // simula um tabuleiro final onde um jogador venceu
    std::vector<std::vector<int>> tabuleiro_final = {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1}
    };

    jogo.set_tabuleiro(tabuleiro_final); // precisa adicionar essa funcao no Reversi

    // agora o jogo deve indicar que ha uma vitoria para o jogador 1
    CHECK(jogo.verificar_vitoria(1) == true);
    CHECK(jogo.verificar_vitoria(2) == true); // pois o jogo terminou, mas nao significa que ele venceu

    // agora testamos um empate
    std::vector<std::vector<int>> tabuleiro_empate = {
        {1, 2, 1, 2, 1, 2, 1, 2},
        {2, 1, 2, 1, 2, 1, 2, 1},
        {1, 2, 1, 2, 1, 2, 1, 2},
        {2, 1, 2, 1, 2, 1, 2, 1},
        {1, 2, 1, 2, 1, 2, 1, 2},
        {2, 1, 2, 1, 2, 1, 2, 1},
        {1, 2, 1, 2, 1, 2, 1, 2},
        {2, 1, 2, 1, 2, 1, 2, 1}
    };

    jogo.set_tabuleiro(tabuleiro_empate);
    CHECK(jogo.verificar_vitoria(1) == true);
    CHECK(jogo.verificar_vitoria(2) == true);
}