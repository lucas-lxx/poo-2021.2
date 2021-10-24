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

    // Acesso: 5 funções
    // inverter com copia
    std::cout<< "Retorna o vetor, " << vet_print({1, 2, 3, 4}) << " ao inverso, " << vet_print(inverter_com_copia({1, 2, 3, 4})) << '\n' << '\n';

    // inverter inplace
    std::vector<int> inplace_asdf {1, 2, 3, 4};
    std::cout<< "Retorna o vetor, " << vet_print(inplace_asdf); 
    inverter_inplace(inplace_asdf);
    std::cout << " ao inverso, sem auxílio de vetor de cópia, " << vet_print(inplace_asdf) << '\n' << '\n';

    // sortear
    std::cout << "Retorna um número aleatório do vetor, " << vet_print(inplace_asdf) << " [ " << sortear(inplace_asdf) << " ]" << '\n' << '\n';

    // saida da função embaralhar
    std::vector<int> embaralhar_vet = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    std::cout << "Retorna um vetor embaralhado, " << vet_print(embaralhar_vet);
    // retorna o vetor embaralhado
    embaralhar(embaralhar_vet);
    std::cout << " " << vet_print(embaralhar_vet) << '\n' << '\n';

    // saida da funcao ordenar()
    // retorna o vetor desembaralhado
    ordenar(embaralhar_vet);
    std::cout << "Retorna um vetor ordenado, " << vet_print(embaralhar_vet) << '\n' << '\n';

    // Conjuntos: 3 funções
    // exclusivos: O fiscal permitiu a entrada de um único representante de cada valor, ou seja, uma lista dos valores que aparecem na fila sem repetição. Que conjunto foi formado?
    // saida //{1, 3, 4, 3, -1, -2, -2} -> {1, 3, 4, -1, -2}
    std::cout << "Retorna a fila, " << vet_print({1, 3, 4, 3, -1, -2, -2}) << " sem os elementos repetidos, ";
    std::cout << vet_print(exclusivos({1, 3, 4, 3, -1, -2, -2})) << '\n' << '\n';

    // diferentes: Qual a lista dos diferentes níveis de stress que aparecem?
    //{1, 3, 4, 3, -1, -2, -2} -> {1, 3, 4, 2}
    std::cout << "Retorna a lista dos diferentes niveis de stress " << vet_print(diferentes({1, 3, 4, 3, -1, -2, -2})) << '\n' << '\n';
}