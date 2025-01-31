#ifndef TIC_TAC_TOE_HPP
#define TIC_TAC_TOE_HPP

#include "jogo_tabuleiro.hpp"
#include <iostream>
#include <stdexcept>

class TicTacToe : public JogoTabuleiro {
public:
    // construtor para inicializar o tabuleiro 3x3
    TicTacToe();

    // inicializa o tabuleiro, preenchendo com zeros
    void inicializar_tabuleiro() override;

    // imprime o tabuleiro no console
    void imprimir_tabuleiro() const override;

    // realiza uma jogada inserindo a peca na posicao especificada
    bool realizar_jogada(int jogador, const std::vector<int>& posicao) override;

    // verifica se o jogador atual venceu o jogo
    bool verificar_vitoria(int jogador) const override;

    void boas_vindas() const override;
};

#endif