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

    // pegar_mulheres_calmas: retorne uma lista com as mulheres com nível de stress menor que 10.(negativos menor que 10)
    std::cout << "Retorna uma lista com as mulheres calmas: " << vet_print(pegar_mulheres_calmas({-23, -52, 34, 84, -29, 91, -1, 1, 43, 234, -1, -3, 2, -4, 4, -8, 1, -3, 1, -5})) << '\n' << '\n';

    // inverter com copia
    std::cout<< "Retorna o vetor, " << vet_print({1, 2, 3, 4}) << " ao inverso, " << vet_print(inverter_com_copia({1, 2, 3, 4})) << '\n' << '\n';
}