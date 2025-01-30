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
        std::string iniciar_jogo(std::string jogo, std::string jogador_1, std::string jogador_2); 

    private: 

        // metodo aux para ler alguma jogada de um jogo de certo tipo
        std::vector<int> ler_jogada(const JogoTabuleiro& jogo); 

        // metodo que executa uma partida
        std::string jogar_partida(JogoTabuleiro& jogo, std::string jogador_1, std::string jogador_2);
};

#endif