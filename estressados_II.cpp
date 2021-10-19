#include <iostream>
#include <string>
#include <vector>
#include "estressados_lib.hpp"

int main()
{
    // clonar: retorna um novo vetor copiando os valores do vetor de entrada
    std::vector<int> vetor_original = {1, 2, 3, 4, 5};
    std::vector<int> vetor_copia = clonar(vetor_original);
    std::cout << "O vetor original eh: " << vet_print(vetor_copia) << '\n';
    std::cout << "O vetor copia eh: " << vet_print(vetor_copia) << '\n' << '\n';
    
    // pegar_homens: retorne uma lista com os homens (valores positivos)
    std::cout << "Retorna uma lista só com o estresse dos homens: " << vet_print(pegar_homens({-23, -52, 34, 84, -29, 91})) << '\n' << '\n';

    // pegar_calmos: retorne uma lista com as pessoas com stress menor que 10 (abs)
    std::cout << "Retorna uma lista só com as pessoas que tem o estresse menor que 10: " << vet_print(pegar_calmos({1, 10, -1, -10, 2, -2, 9, -9})) << '\n' << '\n';
}