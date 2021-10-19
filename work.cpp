#include <iostream>
#include <vector>
#include "work-lib.hpp"


int main()
{
    std::cout << "existe: " << to_alpha(existe({-1, -50, -99}, -1)) << '\n'; // 1/true
    std::cout << "existe: " << to_alpha(existe({-1, -50, -1, -99}, 10)) << '\n' << '\n'; // 0/false

    std::cout << "contar: " << contar({-1, -50, -1, -99}, -1) << '\n'; // 2
    std::cout << "contar: " << contar({-1, -50, -1, -99}, 10) << '\n' << '\n'; // 0

    std::cout << "procurar: " << procurar({-1, -50, -1 -99}, -50) << '\n'; // 1
    std::cout << "procurar: " << procurar({-1, -50, -1, -99}, 10) << '\n' << '\n'; // -1

    std::cout << "procurar a partir: " << procurar_apartir({5, 3, -1, -50, -1, -99}, -1, 0) << '\n'; // 2
    std::cout << "procurar a partir: " << procurar_apartir({5, 3, -1, -50, -1, -99}, -1, 3) << '\n'; // 4
    std::cout << "procurar a partir: " << procurar_apartir({5, 3, -1, -50, -1, -99}, -1, 4) << '\n' << '\n'; // 4

    std::cout << "procurar menor: " << procurar_menor({5, 3, -1, -50, -1, -99}) << '\n' << '\n'; // -99

    std::cout << "procurar a posição do menor no vetor: " << procurar_pos_menor({5, 3, -1, -50, -1, -99}) << '\n' << '\n'; // 5

    std::cout << "procurar menor posição a partir de um ponto: " << procurar_pos_menor_apartir({5, 3, -1, -50, -1, 10}, 3) << '\n' << '\n'; // 3

    std::cout << "Qual a posição do homem mais calmo: " << procurar_pos_melhor_se({5, 3, -1, -50, -1, -99}) << '\n'; //1
    std::cout << "Qual a posição do homem mais calmo: " << procurar_pos_melhor_se({-1, -50, -1, -99}) << '\n' << '\n'; // -1
}