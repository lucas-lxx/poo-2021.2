#include <iostream>
#include <vector>
#include <sstream>
#include "estressados_lib.hpp"



int main()
{
    // Map - Manipulação: 3 funções
    // sozinhos: Quais PESSOAS eram as únicas representantes do seu nível de stress na fila? (abs)
    //{1, 3, 4, 3, -1, -3, -3} -> {4}
    std::cout << "Retorna as pessoas que representam um estresse que não se repete " << vet_print(sozinhos({1, 3, 4, 3, -1, -3, -3})) << '\n' << '\n';
}