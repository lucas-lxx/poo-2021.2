#include <iostream>
#include <vector>

bool existe (const std::vector<int>& fila, int x) {
    for (int i : fila) {
        if (x == i) 
            return true;
    }
    return false;
}

int main()
{
    std::cout << existe({-1, -50, -99}, -1) << '\n';
    std::cout << existe({-1, -50, -1, -99}, 10) << '\n';
}