#include <iostream>
#include <vector>

// transforma funções booleanas de 0 e 1 para true ou false
std::string to_alpha(bool x) {
    return x ? "true" : "false";
}

// existe: Alguém com o valor X está na fila?
bool existe (const std::vector<int>& fila, int x) {
    for (int i : fila) {
        if (x == i) 
            return true;
    }
    return false;
}

// contar: Quantas vezes o valor X apareceu na fila?
int contar(const std::vector<int>& fila, int x) {
    int count = 0;
    for (int i : fila) {
        if (i == x) 
            count++;
    }
    return count;
}

// procurar: Em que posição da fila aparece X pela primeira vez?
// retorna -1 se não encontrar
int procurar(const std::vector<int>& fila, int x){
    for (int i : fila) {
        if (i == x) 
            return 1;
    }
    return -1;
}

int main()
{
    std::cout << "existe: " << to_alpha(existe({-1, -50, -99}, -1)) << '\n'; // 1/true
    std::cout << "existe: " << to_alpha(existe({-1, -50, -1, -99}, 10)) << '\n' << '\n'; // 0/false

    std::cout << "contar: " << contar({-1, -50, -1, -99}, -1) << '\n'; // 2
    std::cout << "contar: " << contar({-1, -50, -1, -99}, 10) << '\n' << '\n'; // 0

    std::cout << "procurar: " << procurar({-1, -50, -1 -99}, -50) << '\n'; // 1
    std::cout << "procurar: " << procurar({-1, -50, -1, -99}, 10) << '\n' << '\n'; // -1
}