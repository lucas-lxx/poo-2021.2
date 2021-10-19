#include <iostream>
#include <string>
#include <vector>
#include "estressados_lib.hpp"

int main()
{
    std::vector<int> vetor_original = {1, 2, 3, 4, 5};
    std::vector<int> vetor_copia = clonar(vetor_original);
    std::cout << "O vetor original eh: " << vet_print(vetor_copia) << '\n';
    std::cout << "O vetor copia eh: " << vet_print(vetor_copia) << '\n';
    
}