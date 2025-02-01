#include "ConnectFour.hpp"

/**
 * @brief Construtor da classe ConnectFour, inicializa o tabuleiro.
 */
ConnectFour::ConnectFour() {
    linhas = 6;
    colunas = 7;
    tabuleiro = std::vector<std::vector<int> >(linhas, std::vector<int>(colunas, 0));
}

/**
 * @brief Reinicializa o tabuleiro preenchendo com zeros.
 */
void ConnectFour::inicializar_tabuleiro(){
    for (auto& linha : tabuleiro) {
        std::fill(linha.begin(), linha.end(), 0);
    }
}

/**
 * @brief Imprime o tabuleiro no console
 */
void ConnectFour::imprimir_tabuleiro() const {
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
 * @param std::vector<int> posicao Vetor contendo a coluna onde a peca sera inserida.
 * @return bool Retorna true se a jogada for bem-sucedida.
 * 
 * @exception std::invalid_argument Se a posicao informada não for valida.
 * @exception std::runtime_error Se a coluna estiver cheia.
 */
bool ConnectFour::realizar_jogada(int jogador, const std::vector<int>& posicao) {
    if (posicao.size() != 1) {
        throw std::invalid_argument("connect four requer apenas a coluna");
    }
    int coluna = posicao[0];

    if (coluna < 0 || coluna >= colunas) {
        throw std::invalid_argument("coluna fora do limite");
    }

    for (int i = linhas - 1; i >= 0; --i) {
        if (tabuleiro[i][coluna] == 0) {
            tabuleiro[i][coluna] = jogador;
            return true;
        }
    }

    throw std::runtime_error("coluna cheia");
}

/**
 * @brief Verifica se um jogador venceu a partida.
 * 
 * @param int jogador Numero do jogador (1 ou 2).
 * @return bool Retorna true se o jogador venceu.
 */
bool ConnectFour::verificar_vitoria(int jogador) const {
    // verifica linhas
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j <= colunas - 4; ++j) {
            if (tabuleiro[i][j] == jogador && tabuleiro[i][j + 1] == jogador &&
                tabuleiro[i][j + 2] == jogador && tabuleiro[i][j + 3] == jogador) {
                return true;
            }
        }
    }

    // verifica colunas
    for (int j = 0; j < colunas; ++j) {
        for (int i = 0; i <= linhas - 4; ++i) {
            if (tabuleiro[i][j] == jogador && tabuleiro[i + 1][j] == jogador &&
                tabuleiro[i + 2][j] == jogador && tabuleiro[i + 3][j] == jogador) {
                return true;
            }
        }
    }

    // verifica diagonais (cima-esquerda para baixo-direita)
    for (int i = 0; i <= linhas - 4; ++i) {
        for (int j = 0; j <= colunas - 4; ++j) {
            if (tabuleiro[i][j] == jogador && tabuleiro[i + 1][j + 1] == jogador &&
                tabuleiro[i + 2][j + 2] == jogador && tabuleiro[i + 3][j + 3] == jogador) {
                return true;
            }
        }
    }

    // verifica diagonais (baixo-esquerda para cima-direita)
    for (int i = 3; i < linhas; ++i) {
        for (int j = 0; j <= colunas - 4; ++j) {
            if (tabuleiro[i][j] == jogador && tabuleiro[i - 1][j + 1] == jogador &&
                tabuleiro[i - 2][j + 2] == jogador && tabuleiro[i - 3][j + 3] == jogador) {
                return true;
            }
        }
    }

    return false;
}

/**
 * @brief Exibe uma mensagem de boas-vindas ao jogo.
 */
void ConnectFour::boas_vindas() const {
    std::vector<std::vector<std::string> > letras;
 
    std::vector<std::string> l;
    l.push_back(std::string(BOLD) + std::string(CYAN) + " ██╗    " + std::string(RESET));
    l.push_back(std::string(BOLD) + std::string(CYAN) + " ██║    " + std::string(RESET));
    l.push_back(std::string(BOLD) + std::string(BLUE) + " ██║    " + std::string(RESET));
    l.push_back(std::string(BOLD) + std::string(BLUE) + " ██║    " + std::string(RESET));
    l.push_back(std::string(BOLD) + std::string(BLUE) + " ██████╗ " + std::string(RESET));
    l.push_back(std::string(BOLD) + std::string(BLUE) + " ╚═════╝ " + std::string(RESET));
    letras.push_back(l);

    std::vector<std::string> i;
    i.push_back(std::string(BOLD) + std::string(CYAN) + "  ██╗" + std::string(RESET));
    i.push_back(std::string(BOLD) + std::string(CYAN) + "  ██║" + std::string(RESET));
    i.push_back(std::string(BOLD) + std::string(BLUE) + "  ██║" + std::string(RESET));
    i.push_back(std::string(BOLD) + std::string(BLUE) + "  ██║" + std::string(RESET));
    i.push_back(std::string(BOLD) + std::string(BLUE) + " ██║" + std::string(RESET));
    i.push_back(std::string(BOLD) + std::string(BLUE) + " ══╝" + std::string(RESET));
    letras.push_back(i);
     
    std::vector<std::string> g;
    g.push_back(std::string(BOLD) + std::string(CYAN) + "  ██████╗ " + std::string(RESET));
    g.push_back(std::string(BOLD) + std::string(CYAN) + " ██╔════╝ " + std::string(RESET));
    g.push_back(std::string(BOLD) + std::string(BLUE) + " ██║ ████╗" + std::string(RESET));
    g.push_back(std::string(BOLD) + std::string(BLUE) + " ██║   ██║" + std::string(RESET));
    g.push_back(std::string(BOLD) + std::string(BLUE) + " ██╚═══██║" + std::string(RESET));
    g.push_back(std::string(BOLD) + std::string(BLUE) + " ╚██████═╝" + std::string(RESET));
    letras.push_back(g);

    std::vector<std::string> quatro;
    quatro.push_back(std::string(BOLD) + std::string(CYAN) + " ██╗  ██╗" + std::string(RESET));
    quatro.push_back(std::string(BOLD) + std::string(CYAN) + " ██║  ██║" + std::string(RESET));
    quatro.push_back(std::string(BOLD) + std::string(BLUE) + " ███████║" + std::string(RESET));
    quatro.push_back(std::string(BOLD) + std::string(BLUE) + "  ╚═══██║" + std::string(RESET));
    quatro.push_back(std::string(BOLD) + std::string(BLUE) + "      ██║" + std::string(RESET));
    quatro.push_back(std::string(BOLD) + std::string(BLUE) + "      ╚═╝" + std::string(RESET));
    letras.push_back(quatro);

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