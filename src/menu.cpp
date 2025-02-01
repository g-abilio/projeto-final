#include <iostream>
#include "Partida.hpp"
#include "Menu.hpp"
#include <fstream>
#include <sstream>
#include <cctype>
#include <map>
#include <set>
#include <algorithm>

bool isNumber(const std::string& str) {
    if (str.empty()) return false;
    for (char ch : str) {
        if (!std::isdigit(ch)) {
            return false;
        }
    }
    return true;
}

Jogador lerLinha(const std::string& linha) {
    std::istringstream iss(linha);
    Data data;
    std::string palavra;

    // Ler o apelido
    iss >> data.apelido;

    // Ler o nome at� encontrar o primeiro n�mero
    while (iss >> palavra) {
        if (isNumber(palavra)) {
            data.numeros.push_back(std::stoi(palavra));
            break;
        } else {
            if (!data.nome.empty()) data.nome += " ";
            data.nome += palavra;
        }
    }

    // Ler os números restantes e adicionar na classe jogador
    int valor;
    while (iss >> valor) {
        data.numeros.push_back(valor);
    }

    Jogador Jogador_x(data.apelido, data.nome);

    Jogador_x.addHistReversi(data.numeros[0], data.numeros[1]);
    Jogador_x.addHistConnect4(data.numeros[2], data.numeros[3]);
    Jogador_x.addHistTicTacToe(data.numeros[4], data.numeros[5]);

    return Jogador_x;
}

bool compararRankingGeral(Jogador& a, Jogador& b) {
    if (a.getTotalVitorias() != b.getTotalVitorias())
        return a.getTotalVitorias() > b.getTotalVitorias(); // Mais vitórias primeiro
    return a.getTotalDerrotas() < b.getTotalDerrotas(); // Menos derrotas como desempate
}

bool compararRankingReversi(Jogador& a, Jogador& b) {
    int* vetor_a = a.getHistReversi();
    int* vetor_b = b.getHistReversi();
    if (vetor_a[0] != vetor_b[0])
        return vetor_a[0] > vetor_b[0];
    return vetor_a[1] < vetor_b[1];
}

bool compararRankingConnect4(Jogador& a,Jogador& b) {
    int* vetor_a = a.getHistConnect4();
    int* vetor_b = b.getHistConnect4();
    if (vetor_a[0] != vetor_b[0])
        return vetor_a[0] > vetor_b[0];
    return vetor_a[1] < vetor_b[1];
}

bool compararRankingTicTacToe(Jogador& a,Jogador& b) {
    int* vetor_a = a.getHistTicTacToe();
    int* vetor_b = b.getHistTicTacToe();
    if (vetor_a[0] != vetor_b[0])
        return vetor_a[0] > vetor_b[0];
    return vetor_a[1] < vetor_b[1];
}

std::map<string,Jogador> menuJogos(std::map<string,Jogador>& jogadores_a, std::map<string,Jogador>& jogadores_n) {

    std::string ler_entrada, apelido, nome;
    std::string operacao, ordenar, apelido_j1, apelido_j2, jogo, tipo;

    do {

        // Recebe a linha digitada pelo usu�rio - a primeira string indica a opera��o
        std::getline(std::cin, ler_entrada);
        
        // não sei porque, mas parece ser necessario chamar getline duas vezes
        // quando chama-se o EP... esse if é uma solucao temporaria
        if (operacao == "EP") {
            std::getline(std::cin, ler_entrada);
        }

        std::istringstream ss(ler_entrada);
        ss >> operacao;

        //Verifica se a operação é válida
        std::set<std::string> operacoes_validas = {"CJ", "RJ", "LJ", "EP", "FS", "PJ"};

        if (operacoes_validas.find(operacao) == operacoes_validas.end()){
            std::cout << "ERRO: Operacao invalida" << std::endl;
        }

        //Cadastrar jogador
        else if (operacao == "CJ"){
            ss >> apelido;
            std::getline(ss, nome);

            if (!nome.empty() && nome[0] == ' ') {
                nome.erase(0, 1);
            }

            if(nome == ""){
                std::cout << "ERRO: Dados incorretos " << std::endl;
            }

            else if(jogadores_a.find(apelido)!= jogadores_a.end()){
                std::cout << "ERRO: Jogador repetido" << std::endl;
            }

            else if(jogadores_a.find(apelido) == jogadores_a.end()){
                Jogador Jogador1(apelido, nome);
                jogadores_a.insert(pair<string, Jogador>(Jogador1.getApelido(),Jogador1));
                jogadores_n.insert(pair<string, Jogador>(Jogador1.getNome(),Jogador1));
                std::cout << "Jogador " << apelido << " cadastrado com sucesso" << std::endl;
            }

        }

        //Remover Jogador
        else if (operacao == "RJ"){
            ss >> apelido;

            if(jogadores_a.find(apelido) != jogadores_a.end()){
                auto iter = jogadores_a.find(apelido);
                nome = iter->second.getNome();

                jogadores_a.erase(apelido);
                jogadores_n.erase(nome);
                std::cout << "Jogador " << apelido << " removido com sucesso" << std::endl;
            }

            else if(jogadores_a.find(apelido)== jogadores_a.end()){
                std::cout << "ERRO: Jogador inexistente" << std::endl;
            }
        }

        //Listar jogadores
        else if (operacao == "LJ"){
            ss >> ordenar;

            if(jogadores_a.empty()){
                std::cout << "Nao ha jogadores cadastrados para listar." << std::endl;
            }

            else if (ordenar == "A"){
                 map<string,Jogador>::iterator it;

                for (it = jogadores_a.begin(); it != jogadores_a.end(); it++) {

                    int* vetor_reversi = it->second.getHistReversi();
                    int* vetor_connect4 = it->second.getHistConnect4();
                    int* vetor_tictactoe = it->second.getHistTicTacToe();

                    std::cout << it->first << "  " << it->second.getNome() << std::endl;
                    std::cout << "REVERSI - V:" << vetor_reversi[0] << " D:" << vetor_reversi[1] << std::endl;
                    std::cout << "LIG4 - V:" << vetor_connect4[0] << " D:" << vetor_connect4[1] << std::endl;
                    std::cout << "VELHA - V:" << vetor_tictactoe[0] << " D:" << vetor_tictactoe[1] << "\n" << std::endl;
                }

            }

            else if (ordenar == "N"){
                 map<string,Jogador>::iterator it;

                for (it = jogadores_n.begin(); it != jogadores_n.end(); it++) {

                    int* vetor_reversi = it->second.getHistReversi();
                    int* vetor_connect4 = it->second.getHistConnect4();
                    int* vetor_tictactoe = it->second.getHistTicTacToe();

                    std::cout << it->second.getApelido() << "  " << it->second.getNome() << std::endl;
                    std::cout << "REVERSI - V:" << vetor_reversi[0] << " D:" << vetor_reversi[1] << std::endl;
                    std::cout << "LIG4 - V:" << vetor_connect4[0] << " D:" << vetor_connect4[1] << std::endl;
                    std::cout << "VELHA - V:" << vetor_tictactoe[0] << " D:" << vetor_tictactoe[1] << "\n" << std::endl;
                }
            }

            else {
                std::cout << "ERRO: Selecione uma operacao valida" << std::endl;
                std:cout << "      A - apelido ou N - nome"  << std::endl;
            }

        }

        //Executar partidas
        else if (operacao == "EP") {
            ss >> jogo;
            ss >> apelido_j1;
            ss >> apelido_j2;

            //Verifica se o jogo eh valido
            std::set<std::string> jogos_validos = {"R", "L", "V"};
            if (jogos_validos.find(jogo) == jogos_validos.end()){
                std::cout << "ERRO: O jogo selecionado eh invalido" << std::endl;
            }

            else if((apelido_j1 == "") || (apelido_j2 == "")){
                std::cout << "ERRO: Dados incorretos " << std::endl;
            }

            else if((jogadores_a.find(apelido_j1) == jogadores_a.end()) || (jogadores_a.find(apelido_j2) == jogadores_a.end()))
                if (jogadores_a.find(apelido_j1) == jogadores_a.end()){
                    std::cout << "ERRO: Jogador 1 inexistente" << std::endl;
                }
                else {
                    std::cout << "ERRO: Jogador 2 inexistente" << std::endl;
                }

            else if((jogo == "R") || (jogo == "L") || (jogo == "V")) {
                Partida partida; 
                auto resultado_partida = partida.iniciar_jogo(jogo, apelido_j1, apelido_j2);

                if (resultado_partida == apelido_j1) {
                    if (jogo == "R") {
                        jogadores_a.at(apelido_j1).addHistReversi(1, 0);
                        jogadores_a.at(apelido_j2).addHistReversi(0, 1);
                    } else if (jogo == "L") {
                        jogadores_a.at(apelido_j1).addHistConnect4(1, 0);
                        jogadores_a.at(apelido_j2).addHistConnect4(0, 1);
                    } else if (jogo == "V") {
                        jogadores_a.at(apelido_j1).addHistTicTacToe(1, 0);
                        jogadores_a.at(apelido_j2).addHistTicTacToe(0, 1);
                    }
                } else if (resultado_partida == apelido_j2) {
                    if (jogo == "R") {
                        jogadores_a.at(apelido_j2).addHistReversi(1, 0);
                        jogadores_a.at(apelido_j1).addHistReversi(0, 1);
                    } else if (jogo == "L") {
                        jogadores_a.at(apelido_j2).addHistConnect4(1, 0);
                        jogadores_a.at(apelido_j1).addHistConnect4(0, 1);
                    } else if (jogo == "V") {
                        jogadores_a.at(apelido_j2).addHistTicTacToe(1, 0);
                        jogadores_a.at(apelido_j1).addHistTicTacToe(0, 1);
                    }
                }
            }
        }

        //Pontuação dos jogadores
        else if (operacao == "PJ"){
            ss >> tipo;

            std::set<std::string> tipos_validos = {"R", "L", "V", "G"};
            std::vector<Jogador> jogadores_vec;

            map<string,Jogador>::iterator it;
            for (it = jogadores_a.begin(); it != jogadores_a.end(); it++) {
                jogadores_vec.push_back(it->second);
            }

            if(jogadores_a.empty()){
                std::cout << "Nao ha jogadores cadastrados para rankear." << std::endl;
            }

            else if (tipos_validos.find(tipo) == tipos_validos.end()){
                std::cout << "ERRO: O tipo de ranking selecionado eh invalido" << std::endl;
            }

            // //Exibindo ranking Geral
            else if (tipo == "G"){
                std::sort(jogadores_vec.begin(), jogadores_vec.end(), compararRankingGeral);

                std::cout << "----- Ranking Geral -----\n";
                for (size_t i = 0; i < jogadores_vec.size(); ++i) {
                    auto& jogador = jogadores_vec[i];
                    std::cout << i + 1 << ". " << jogador.getApelido()
                    << " - Vitorias: " << jogador.getTotalVitorias()
                    << ", Derrotas: " << jogador.getTotalDerrotas() << "\n";
    }
            }

            //Exibindo ranking do Reversi
            else if (tipo == "R"){
                std::sort(jogadores_vec.begin(), jogadores_vec.end(), compararRankingReversi);

                std::cout << "----- Ranking Reversi -----\n";
                for (size_t i = 0; i < jogadores_vec.size(); ++i) {
                    auto& jogador = jogadores_vec[i];
                    int* vetor = jogador.getHistReversi();
                        std::cout << i + 1 << ". " << jogador.getApelido()
                        << " - Vitorias: " << vetor[0]
                        << ", Derrotas: " << vetor[1] << "\n";
                }
            }

            //Exibindo ranking do Lig4
            else if (tipo == "L"){
                std::sort(jogadores_vec.begin(), jogadores_vec.end(), compararRankingConnect4);

                std::cout << "----- Ranking Lig4 -----\n";
                for (size_t i = 0; i < jogadores_vec.size(); ++i) {
                    auto& jogador = jogadores_vec[i];
                    int* vetor = jogador.getHistConnect4();
                        std::cout << i + 1 << ". " << jogador.getApelido()
                        << " - Vitorias: " << vetor[0]
                        << ", Derrotas: " << vetor[1] << "\n";
                }
            }

            //Exibindo ranking do Jogo da Velha
            else if (tipo == "V"){
                std::sort(jogadores_vec.begin(), jogadores_vec.end(), compararRankingTicTacToe);

                std::cout << "----- Ranking Jogo da Velha -----\n";
                for (size_t i = 0; i < jogadores_vec.size(); ++i) {
                    auto& jogador = jogadores_vec[i];
                    int* vetor = jogador.getHistTicTacToe();
                        std::cout << i + 1 << ". " << jogador.getApelido()
                        << " - Vitorias: " << vetor[0]
                        << ", Derrotas: " << vetor[1] << "\n";
                }
            }
        }

        //Limpando as strings de leitura
        apelido_j1.clear();
        apelido_j2.clear();
        nome.clear();
        apelido.clear();

    } while (operacao != "FS");

    return jogadores_a;
}
