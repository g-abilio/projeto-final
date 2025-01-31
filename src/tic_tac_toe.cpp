#include "tic_tac_toe.hpp"

/**
 * @brief Construtor da classe TicTacToe que inicializa o tabuleiro.
 */
TicTacToe::TicTacToe() {
    linhas = 3;
    colunas = 3;
    tabuleiro = std::vector<std::vector<int> >(linhas, std::vector<int>(colunas, 0));
}

/**
 * @brief Inicializa o tabuleiro zerando todas as posicoes.
 */
void TicTacToe::inicializar_tabuleiro() {
    for (auto& linha : tabuleiro) {
        std::fill(linha.begin(), linha.end(), 0);
    }
}

/**
 * @brief Imprime o tabuleiro no consle.
 */
void TicTacToe::imprimir_tabuleiro() const {
    for (const auto& linha : tabuleiro) {
        for (const auto& celula : linha) {
            char simbolo = (celula == 0) ? '.' : (celula == 1 ? 'X' : 'O');
            std::cout << simbolo << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

/**
 * @brief Realiza uma jogada no tabuleiro.
 * 
 * @param int jogador Numero do jogador (1 ou 2).
 * @param std::vector<int> posicao Vetor contendo a linha e a coluna da jogada.
 * @return bool Retorna true se a jogada for valida e realizada com sucesso.
 * 
 * @exception std::invalid_argument Se a posicao informada for invalida.
 * @exception std::runtime_error Se a posicao ja estiver ocupada.
 */
bool TicTacToe::realizar_jogada(int jogador, const std::vector<int>& posicao) {
    if (posicao.size() != 2) {
        throw std::invalid_argument("tic tac toe requer linha e coluna");
    }
    int linha = posicao[0];
    int coluna = posicao[1];

    if (linha < 0 || linha >= linhas || coluna < 0 || coluna >= colunas) {
        throw std::invalid_argument("posicao fora do limite");
    }

    if (tabuleiro[linha][coluna] != 0) {
        throw std::runtime_error("posicao ja ocupada");
    }

    tabuleiro[linha][coluna] = jogador;
    return true;
}

/**
 * @brief Verifica se um jogador venceu a partida
 * 
 * @param int jogador Numero do jogador (1 ou 2).
 * @return bool Retorna true se o jogador venceu.
 */
bool TicTacToe::verificar_vitoria(int jogador) const {
    // verifica linhas
    for (int i = 0; i < linhas; ++i) {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) {
            return true;
        }
    }

    // verifica colunas
    for (int j = 0; j < colunas; ++j) {
        if (tabuleiro[0][j] == jogador && tabuleiro[1][j] == jogador && tabuleiro[2][j] == jogador) {
            return true;
        }
    }

    // verifica diagonais
    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) {
        return true;
    }

    if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador) {
        return true;
    }

    return false;
}

/**
 * @brief Exibe uma mensagem de boas-vindas ao jogo.
 */
void TicTacToe::boas_vindas() const {
    std::vector<std::vector<std::string> > letras;

    std::vector<std::string> t;
    t.push_back(std::string(BOLD) + std::string(CYAN) + " ████████ " + std::string(RESET));
    t.push_back(std::string(BOLD) + std::string(CYAN) + "  ╚═██╗ " + std::string(RESET));
    t.push_back(std::string(BOLD) + std::string(BLUE) + "    ██║ " + std::string(RESET));
    t.push_back(std::string(BOLD) + std::string(BLUE) + "    ██║ " + std::string(RESET));
    t.push_back(std::string(BOLD) + std::string(BLUE) + "    ██║ " + std::string(RESET));
    t.push_back(std::string(BOLD) + std::string(BLUE) + "    ██║" + std::string(RESET));
    letras.push_back(t);

    std::vector<std::string> i;
    i.push_back(std::string(BOLD) + std::string(CYAN) + " ██╗" + std::string(RESET));
    i.push_back(std::string(BOLD) + std::string(CYAN) + "   ██║" + std::string(RESET));
    i.push_back(std::string(BOLD) + std::string(CYAN) + "   ██║" + std::string(RESET));
    i.push_back(std::string(BOLD) + std::string(BLUE) + "   ██║" + std::string(RESET));
    i.push_back(std::string(BOLD) + std::string(BLUE) + "   ██║" + std::string(RESET));
    i.push_back(std::string(BOLD) + std::string(BLUE) + "    ██║" + std::string(RESET));
    i.push_back(std::string(BOLD) + std::string(BLUE) + "   ══╝" + std::string(RESET));
    letras.push_back(i);

    std::vector<std::string> c;
    c.push_back(std::string(BOLD) + std::string(CYAN) + "  ██████╗ " + std::string(RESET));
    c.push_back(std::string(BOLD) + std::string(CYAN) + " ██╔════╝ " + std::string(RESET));
    c.push_back(std::string(BOLD) + std::string(BLUE) + " ██║      " + std::string(RESET));
    c.push_back(std::string(BOLD) + std::string(BLUE) + " ██║      " + std::string(RESET));
    c.push_back(std::string(BOLD) + std::string(BLUE) + " ██╚════╗" + std::string(RESET));
    c.push_back(std::string(BOLD) + std::string(BLUE) + " ╚██████╝" + std::string(RESET));
    letras.push_back(c);

    std::vector<std::string> t2;
    t2.push_back(std::string(BOLD) + std::string(CYAN) + "   ████████ " + std::string(RESET));
    t2.push_back(std::string(BOLD) + std::string(CYAN) + "    ╚═██╗ " + std::string(RESET));
    t2.push_back(std::string(BOLD) + std::string(BLUE) + "      ██║ " + std::string(RESET));
    t2.push_back(std::string(BOLD) + std::string(BLUE) + "      ██║ " + std::string(RESET));
    t2.push_back(std::string(BOLD) + std::string(BLUE) + "       ██║ " + std::string(RESET));
    t2.push_back(std::string(BOLD) + std::string(BLUE) + "       ██║" + std::string(RESET));
    letras.push_back(t2);

    std::vector<std::string> a;
    a.push_back(std::string(BOLD) + std::string(CYAN) + "  ██████╗ " + std::string(RESET));
    a.push_back(std::string(BOLD) + std::string(CYAN) + "   ██╔═══██  " + std::string(RESET));
    a.push_back(std::string(BOLD) + std::string(BLUE) + "   ████████" + std::string(RESET));
    a.push_back(std::string(BOLD) + std::string(BLUE) + "   ██╔═══██╗" + std::string(RESET));
    a.push_back(std::string(BOLD) + std::string(BLUE) + "   ██║   ██║" + std::string(RESET));
    a.push_back(std::string(BOLD) + std::string(BLUE) + "    ╚═╝   ╚═╝" + std::string(RESET));
    letras.push_back(a);
    
    std::vector<std::string> c2;
    c2.push_back(std::string(BOLD) + std::string(CYAN) + "   ██████╗ " + std::string(RESET));
    c2.push_back(std::string(BOLD) + std::string(CYAN) + " ██╔════╝ " + std::string(RESET));
    c2.push_back(std::string(BOLD) + std::string(BLUE) + "   ██║      " + std::string(RESET));
    c2.push_back(std::string(BOLD) + std::string(BLUE) + "  ██║      " + std::string(RESET));
    c2.push_back(std::string(BOLD) + std::string(BLUE) + "  ██╚════╗" + std::string(RESET));
    c2.push_back(std::string(BOLD) + std::string(BLUE) + "  ╚██████╝" + std::string(RESET));
    letras.push_back(c2);

    std::vector<std::string> t3;
    t3.push_back(std::string(BOLD) + std::string(CYAN) + "   ████████ " + std::string(RESET));
    t3.push_back(std::string(BOLD) + std::string(CYAN) + "    ╚═██╗ " + std::string(RESET));
    t3.push_back(std::string(BOLD) + std::string(BLUE) + "      ██║ " + std::string(RESET));
    t3.push_back(std::string(BOLD) + std::string(BLUE) + "      ██║ " + std::string(RESET));
    t3.push_back(std::string(BOLD) + std::string(BLUE) + "       ██║ " + std::string(RESET));
    t3.push_back(std::string(BOLD) + std::string(BLUE) + "       ██║" + std::string(RESET));
    letras.push_back(t3);

    std::vector<std::string> o;
    o.push_back(std::string(BOLD) + std::string(CYAN) + " ██████╗ " + std::string(RESET));
    o.push_back(std::string(BOLD) + std::string(CYAN) + "  ██╔═══██╗" + std::string(RESET));
    o.push_back(std::string(BOLD) + std::string(BLUE) + "  ██║   ██║" + std::string(RESET));
    o.push_back(std::string(BOLD) + std::string(BLUE) + "  ██║   ██║" + std::string(RESET));
    o.push_back(std::string(BOLD) + std::string(BLUE) + "  ██╚═══██╗" + std::string(RESET));
    o.push_back(std::string(BOLD) + std::string(BLUE) + "   ╚██████═╝" + std::string(RESET));
    letras.push_back(o);
  
    std::vector<std::string> e;
    e.push_back(std::string(BOLD) + std::string(CYAN) + " ██████╗ " + std::string(RESET));
    e.push_back(std::string(BOLD) + std::string(CYAN) +   " ██╔═══╝" + std::string(RESET));
    e.push_back(std::string(BOLD) + std::string(BLUE) +   " █████╗  " + std::string(RESET));
    e.push_back(std::string(BOLD) + std::string(BLUE) +  " ██╔══╝  " + std::string(RESET));
    e.push_back(std::string(BOLD) + std::string(BLUE) +  " ██████╗ " + std::string(RESET));
    e.push_back(std::string(BOLD) + std::string(BLUE) + " ╚═════╝ " + std::string(RESET));
    letras.push_back(e);

    int max_linhas_letra = 6;

    for (int i = 0; i < max_linhas_letra; ++i) {
        for (int j = 0; j < letras.size(); ++j) {
            if (i < letras[j].size()) {
                std::cout << letras[j][i];
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}