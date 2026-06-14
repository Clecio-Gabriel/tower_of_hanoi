#include "tower_of_hanoi.hpp"

int main(){

    usage();

    Stack a ({1,2,3});
    Stack<int> b;
    std::cout << a << '\n' << a.get_size() << "\n" << b.get_size() << '\n';

    Tower_of_Hanoi tower;
    tower.visualize();
    tower.solve();


    return EXIT_SUCCESS;
}