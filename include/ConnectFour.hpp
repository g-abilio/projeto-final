#ifndef CONNECTFOUR_HPP
#define CONNECTFOUR_HPP

#include "JogoTabuleiro.hpp"
#include <iostream>
#include <stdexcept>

class ConnectFour : public JogoTabuleiro {
public:
    // construtor para inicializar o tabuleiro com tamanho padrao (6x7)
    ConnectFour();

    // inicializa o tabuleiro, preenchendo com zeros
    void inicializar_tabuleiro() override;

    // imprime o tabuleiro no console
    void imprimir_tabuleiro() const override;

    // realiza uma jogada inserindo a peca na coluna especificada
    bool realizar_jogada(int jogador, const std::vector<int>& posicao) override;

    // verifica se o jogador atual venceu o jogo
    bool verificar_vitoria(int jogador) const override;

    void boas_vindas() const override;
};

#endif