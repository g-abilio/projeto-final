#ifndef PARTIDA_HPP
#define PARTIDA_HPP

#include "jogo_tabuleiro.hpp"
#include "reversi.hpp"
#include "tic_tac_toe.hpp"
#include "connect_four.hpp"

class Partida {
    public: 
        Partida() {};

        // metodo que escolhe qual jogo executar
        void iniciar_jogo(); 

    private: 

        // metodo aux para ler alguma jogada de um jogo de certo tipo
        std::vector<int> ler_jogada(const JogoTabuleiro& jogo); 

        // metodo que executa uma partida
        void jogar_partida(JogoTabuleiro& jogo);
};

#endif