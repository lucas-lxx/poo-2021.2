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
}

