#include "tower_of_hanoi.hpp"
#include <iostream>

int main(){

    std::vector <int> num {1,2,3,4,5};

    for (auto number : num){
        std::cout << number << ' ';
    }
    std::cout << '\n';

    return EXIT_SUCCESS;
}