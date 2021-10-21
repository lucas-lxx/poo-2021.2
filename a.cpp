#include <iostream>

int main()
{
    for(int i = 0; i < 101; i++) {
        std::cout << (rand() % 4) << " ";
    }
    std::cout << '\n';
}
