#ifndef JOGO_TABULEIRO_HPP
#define JOGO_TABULEIRO_HPP

#include <vector>
#include <string>
#include <iostream>

class JogoTabuleiro {
public:
    // destrutor virtual para permitir destruicao correta em classes derivadas
    virtual ~JogoTabuleiro() {}

    // metodos abstratos
    virtual void inicializar_tabuleiro() = 0;
    virtual void imprimir_tabuleiro() const = 0;
    virtual bool realizar_jogada(int jogador, const std::vector<int>& posicao) = 0;
    virtual bool verificar_vitoria(int jogador) const = 0;
    virtual void boas_vindas() const = 0;

    // getters
    int get_linhas() const { return linhas; }
    int get_colunas() const { return colunas; }

    // metodo concreto para limpar o tabuleiro
    void limpar_tabuleiro() {
        for (auto& linha : tabuleiro) {
            std::fill(linha.begin(), linha.end(), 0);
        }
    }

protected:
    std::vector<std::vector<int> > tabuleiro; // representacao generica do tabuleiro
    int linhas;
    int colunas;
};

#endif