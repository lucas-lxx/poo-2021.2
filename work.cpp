#include <iostream>
#include <vector>
#include "work-lib.hpp"


int main()
{
    // Busca: 4 funções
    // existe: Alguém com o valor X está na fila?
    std::cout << "existe: " << to_alpha(existe({-1, -50, -99}, -1)) << '\n'; // 1/true
    std::cout << "existe: " << to_alpha(existe({-1, -50, -1, -99}, 10)) << '\n' << '\n'; // 0/false

    // contar: Quantas vezes o valor X apareceu na fila?
    std::cout << "contar: " << contar({-1, -50, -1, -99}, -1) << '\n'; // 2
    std::cout << "contar: " << contar({-1, -50, -1, -99}, 10) << '\n' << '\n'; // 0

    // procurar: Em que posição da fila aparece X pela primeira vez?
    std::cout << "procurar: " << procurar({-1, -50, -1 -99}, -50) << '\n'; // 1
    std::cout << "procurar: " << procurar({-1, -50, -1, -99}, 10) << '\n' << '\n'; // -1

    // procurar_apartir: Dada a posição para iniciar a busca, qual a próxima posição em que aparece X?
    std::cout << "procurar a partir: " << procurar_apartir({5, 3, -1, -50, -1, -99}, -1, 0) << '\n'; // 2
    std::cout << "procurar a partir: " << procurar_apartir({5, 3, -1, -50, -1, -99}, -1, 3) << '\n'; // 4
    std::cout << "procurar a partir: " << procurar_apartir({5, 3, -1, -50, -1, -99}, -1, 4) << '\n' << '\n'; // 4

    // Melhor caso: 4 funções
    // procurar_menor: qual o menor valor da lista?
    std::cout << "procurar menor: " << procurar_menor({5, 3, -1, -50, -1, -99}) << '\n' << '\n'; // -99

    // procurar_pos_menor: qual a posição do menor valor da lista?
    std::cout << "procurar a posição do menor no vetor: " << procurar_pos_menor({5, 3, -1, -50, -1, -99}) << '\n' << '\n'; // 5

    // procurar_pos_menor_apartir: Dada a posição para iniciar a busca, qual a posição do menor valor da lista?
    std::cout << "procurar menor posição a partir de um ponto: " << procurar_pos_menor_apartir({5, 3, -1, -50, -1, 10}, 3) << '\n' << '\n'; // 3

    // procurar_pos_melhor_se: qual a posição do HOMEM mais calmo? (menor valor maior que 0)
    std::cout << "Qual a posição do homem mais calmo: " << procurar_pos_melhor_se({5, 3, -1, -50, -1, -99}) << '\n'; //1
    std::cout << "Qual a posição do homem mais calmo: " << procurar_pos_melhor_se({-1, -50, -1, -99}) << '\n' << '\n'; // -1

    // Contagem: 4 funções
    // calcular_stress_medio: qual a média de stress da fila? (abs)
    std::cout << "Stress medio de uma fila: " << calcular_stress_medio({-51, 99, 1, -50, -1, -99}) << '\n';
    std::cout << "Stress medio de uma fila: " << calcular_stress_medio({5, 3, -1, -50, -1, -99}) << '\n' << '\n'; 
}