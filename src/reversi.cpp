#include "reversi.hpp"
#include <iostream> 

Reversi::Reversi() : simbolos_jogadores("XO") {
    linhas = 8;
    colunas = 8;
    tabuleiro = std::vector<std::vector<int> >(linhas, std::vector<int>(colunas, 0));
    tabuleiro.resize(linhas, std::vector<int>(colunas, 0));
    inicializar_tabuleiro();
}

Reversi::Reversi(const std::string& simbolos_jogadores) : simbolos_jogadores(simbolos_jogadores) {
    linhas = 8;
    colunas = 8;
    tabuleiro.resize(linhas, std::vector<int>(colunas, 0));
    inicializar_tabuleiro();
}

void Reversi::inicializar_tabuleiro() {
    limpar_tabuleiro();
    tabuleiro[3][3] = 1;
    tabuleiro[3][4] = 2;
    tabuleiro[4][3] = 2;
    tabuleiro[4][4] = 1;
}

void Reversi::imprimir_tabuleiro() const{
    for (const auto& linha : tabuleiro) {
        for (int celula : linha) {
            char simbolo = (celula == 0) ? '.' : simbolos_jogadores[celula - 1];
            std::cout << simbolo << " ";
        }
        std::cout << std::endl;
    }
}

void Reversi::set_tabuleiro(const std::vector<std::vector<int>>& novo_tabuleiro) {
    tabuleiro = novo_tabuleiro;
}

bool Reversi::realizar_jogada(int jogador, const std::vector<int>& posicao) {
    int linha = posicao[0];
    int coluna = posicao[1];

    if (!esta_dentro_do_tabuleiro(linha, coluna) || tabuleiro[linha][coluna] != 0) {
        return false; // posicao invalida ou ja ocupada
    }

    char simbolo_jogador = simbolos_jogadores[jogador - 1];
    int valor_jogador = (simbolo_jogador == 'X') ? 1 : 2;

    bool jogada_valida = false;

    // percorre todas as direcoes para verificar se a jogada captura pecas do adversario
    for (int incremento_linha = -1; incremento_linha <= 1; incremento_linha++) {
        for (int incremento_coluna = -1; incremento_coluna <= 1; incremento_coluna++) {
            if (incremento_linha || incremento_coluna) { // ignora incremento (0,0)
                int l = linha + incremento_linha;
                int c = coluna + incremento_coluna;
                bool encontrou_adversario = false;

                // percorre a direcao enquanto houver pecas do adversario
                while (esta_dentro_do_tabuleiro(l, c) && tabuleiro[l][c] != 0 && tabuleiro[l][c] != valor_jogador) {
                    encontrou_adversario = true;
                    l += incremento_linha;
                    c += incremento_coluna;
                }

                // verifica se a jogada captura alguma peca do adversario
                if (encontrou_adversario && esta_dentro_do_tabuleiro(l, c) && tabuleiro[l][c] == valor_jogador) {
                    jogada_valida = true;
                }
            }
        }
    }

    // se a jogada nao capturar pecas, ela nao e valida
    if (!jogada_valida) {
        return false;
    }

    // coloca a peca no tabuleiro
    tabuleiro[linha][coluna] = valor_jogador;

    // percorre novamente para inverter as pecas do adversario nas direcoes validas
    for (int incremento_linha = -1; incremento_linha <= 1; incremento_linha++) {
        for (int incremento_coluna = -1; incremento_coluna <= 1; incremento_coluna++) {
            if (incremento_linha || incremento_coluna) {
                inverter_pecas_direcao(simbolo_jogador, linha, incremento_linha, coluna, incremento_coluna);
            }
        }
    }

    return true;
}

bool Reversi::pode_realizar_jogada(int jogador, const std::vector<int>& posicao) const {
    int linha = posicao[0];
    int coluna = posicao[1];

    if (!esta_dentro_do_tabuleiro(linha, coluna) || tabuleiro[linha][coluna] != 0) {
        return false; // posicao invalida ou ja ocupada
    }

    char simbolo_jogador = simbolos_jogadores[jogador - 1];
    int valor_jogador = (simbolo_jogador == 'X') ? 1 : 2;

    for (int incremento_linha = -1; incremento_linha <= 1; incremento_linha++) {
        for (int incremento_coluna = -1; incremento_coluna <= 1; incremento_coluna++) {
            if (incremento_linha || incremento_coluna) { 
                int l = linha + incremento_linha;
                int c = coluna + incremento_coluna;
                bool encontrou_adversario = false;

                // percorre a direcao enquanto houver pecas do adversario
                while (esta_dentro_do_tabuleiro(l, c) && tabuleiro[l][c] != 0 && tabuleiro[l][c] != valor_jogador) {
                    encontrou_adversario = true;
                    l += incremento_linha;
                    c += incremento_coluna;
                }

                // a jogada so e valida se ha uma peca do jogador no final
                if (encontrou_adversario && esta_dentro_do_tabuleiro(l, c) && tabuleiro[l][c] == valor_jogador) {
                    return true; // jogada valida
                }
            }
        }
    }

    return false; // nenhuma direcao valida encontrada
}

bool Reversi::verificar_vitoria(int jogador) const {
    bool algum_jogador_pode_jogar = false;

    // verifica se algum jogador ainda pode jogar
    for (int j = 1; j <= 2; j++) { // verifica para ambos os jogadores
        for (int i = 0; i < linhas; ++i) {
            for (int k = 0; k < colunas; ++k) {
                if (tabuleiro[i][k] == 0) { // verifica apenas posicoes vazias
                    if (pode_realizar_jogada(j, {i, k})) {
                        algum_jogador_pode_jogar = true; // ha jogadas validas
                    }
                }
            }
        }
    }

    // se nenhum jogador puder jogar, o jogo acabou
    return !algum_jogador_pode_jogar;
}

void Reversi::boas_vindas() const {
    std::cout << "Bem-vindo ao Reversi!\n";
}

void Reversi::exibir_resultados() const {
    int contagem[2] = {0, 0};

    for (const auto& linha : tabuleiro) {
        for (int celula : linha) {
            if (celula > 0) {
                contagem[celula - 1]++;
            }
        }
    }

    std::cout << "Jogador " << simbolos_jogadores[0] << " controla " << contagem[0] << " quadrados.\n";
    std::cout << "Jogador " << simbolos_jogadores[1] << " controla " << contagem[1] << " quadrados.\n";

    if (contagem[0] > contagem[1]) {
        std::cout << "Jogador " << simbolos_jogadores[0] << " vence!\n";
    } else if (contagem[1] > contagem[0]) {
        std::cout << "Jogador " << simbolos_jogadores[1] << " vence!\n";
    } else {
        std::cout << "O jogo terminou empatado\n";
    }
}

void Reversi::inverter_pecas_direcao(char simbolo_jogador, int linha, int incremento_linha, int coluna, int incremento_coluna) {
    int l = linha + incremento_linha;
    int c = coluna + incremento_coluna;
    std::vector<std::pair<int, int> > pecas_para_inverter;

    // converte simbolo para numero (1 para 'X', 2 para 'O')
    int valor_jogador = (simbolo_jogador == 'X') ? 1 : 2;

    // percorre a direcao verificando se pode inverter as pecas
    while (esta_dentro_do_tabuleiro(l, c) && tabuleiro[l][c] != 0 && tabuleiro[l][c] != valor_jogador) {
        pecas_para_inverter.push_back({l, c});
        l += incremento_linha;
        c += incremento_coluna;
    }
    
    // so inverte se terminou em uma peca do jogador atual
    if (esta_dentro_do_tabuleiro(l, c) && tabuleiro[l][c] == valor_jogador) {
        for (const auto& pos : pecas_para_inverter) {
            tabuleiro[pos.first][pos.second] = valor_jogador;
        }
    }
}

bool Reversi::esta_dentro_do_tabuleiro(int linha, int coluna) const {
    return linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas;
}