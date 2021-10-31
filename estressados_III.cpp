#include <iostream>
#include <vector>
#include <sstream>
#include "estressados_lib.hpp"



int main()
{
    // Map - Manipulação: 3 funções
    // sozinhos: Quais PESSOAS eram as únicas representantes do seu nível de stress na fila? (abs)
    // saida da funcao sozinhos();
    //{1, 3, 4, 3, -1, -3, -3, -5} -> {4, -5}
    std::cout << "Retorna as pessoas que representam um estresse que não se repete " << vet_print(sozinhos({1, 3, 4, 3, -1, -3, -3, -5})) << '\n' << '\n';

    // mais_ocorrencias: Qual a maior quantidade de ocorrências do mesmo nível de stress. (abs)
    // saida da funcao mais_ocorrencias();
    // {1, 3, 4, 5, -1, -5, -5} -> 3
    std::cout << "Retorna a maior quantidade de ocorrencias do mesmo nivel de stress [ " << mais_ocorrencias({1, 3, 4, 5, -1, -5, -5}) << " ]\n" << '\n';

    // mais_recorrentes: Quais os níveis de stress mais recorrentes. (abs)
    // {1, 3, 4, 5, -1, -5, -5, 3, -3} -> {3, 5}
    std::cout << "Retorna os niveis de estresse mais recorrentes, " << vet_print(mais_recorrentes({1, 3, 4, 5, -1, -5, -5, 3, -3})) << '\n' << '\n';

    // Proximidade: 2 funções
    // briga Quando alguém super estressado(>50) está ao lado de duas pessoas muito estressadas(>30) pode dar briga. Quantas vezes essa situação acontece?
    // {50, 98, 31, -51, 31, -99} -> {2}
    std::cout << "Quantas brigas ocorreram na fila, " << briga({50, 98, 31, -51, 31, -99}) << '\n' << '\n';

    // apaziguado Se alguém hiper estressado(>80) estiver ao lado de pelo menos uma pessoa bem tranquila (<10) ela vai ser apaziguada. Em que posições estão esses que serão apaziguados?
    // {83, -4, 65, 8, -99, 12 } -> {0, 4}
    std::cout << "Retorna a posição das pessoas apaziguadas, " << vet_print(apaziguados({83, -4, 65, 8, -99, 12 })) << '\n' << '\n';

    // Sequências: 3 funções
    // quantos_times Duas ou mais pessoas do mesmo sexo seguidas podem formar um time. Quantos times existem na fila?
    // quantos_times({5, 3, 1, -11, 1, 99, -11, -1, -2, 44});  // 3
    // quantos_times({1, 1, 1, -1, 1, -1, -1});  // 2
    // quantos_times({ 28,  26,  1,  6,  39});  // 1
    std::cout << "Retorna times possiveis, " << quantos_times({5, 3, 1, -11, 1, 99, -11, -1, -2, 44}) << '\n';  // 3
    std::cout << "Retorna times possiveis, " << quantos_times({1, 1, 1, -1, 1, -1, -1}) << '\n';  // 2
    std::cout << "Retorna times possiveis, " << quantos_times({ 28,  26,  1,  6,  39}) << '\n' << '\n';  // 1

    // maior_time Qual o maior time que apareceu na fila?
    std::cout << "Retorna qual eh o maior time que apareceu na fila: " << vet_print(maior_time({-5, 3, -1, 15, 1, -99, 11, 1 })) << '\n'; // {15, 1}
    std::cout << "Retorna qual eh o maior time que apareceu na fila: " << vet_print(maior_time({-5, 3, -1, 15, -1, 99, -11, 1 })) << '\n'; // {}
    std::cout << "Retorna qual eh o maior time que apareceu na fila: " << vet_print(maior_time({-5, 3, 1, -15, -1, 99, -11, -1, -7 })) << '\n' << '\n'; // {-11, -1, -7}



    // sem_time Quantas pessoas não estavam em um time?
    std::cout << "Retorna quantas pessoas estao sem time: " << sem_time({-5, 3, 1, -15, -1, 99, -11, -1, -7 }) << '\n'; // 2
    std::cout << "Retorna quantas pessoas estao sem time: " << sem_time({-5, -3, -1, -15, -1, -99, -11, -1, -7 }) << '\n'; // 0
    std::cout << "Retorna quantas pessoas estao sem time: " << sem_time({-5, 3, 1, 15, -1, -99, -11, -1, -7 }) << '\n' << '\n'; // 1

    std::cout << "Retorna quantos casais existem no vetor " << casais_no_vetor({1, 3, 19, -4, 5, -19, -19, -43, -1, 4, -3}) << '\n' << '\n';
}