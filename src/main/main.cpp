#include "tower_of_hanoi.hpp"

#define YES 1
#define NO 0

#define STACK_TEST YES


int main(){

    usage();

    #if STACK_TEST
    Stack a ({1,2,3});
    Stack<int> b;
    std::cout << a << "\n" << a.peek() << '\n' << a.get_size() << "\n" << b.get_size() << '\n';
    a.clear();
    if (a.empty()) std::cout << "true\n";

    std::cout << '\n';

    a.push(10);
    a.push(9);
    a.push(8);
    std::cout << a << '\n';

    std::cout << a.peek() << "\n";

    a.pop();
    std::cout << a << '\n';
    #endif

    Tower_of_Hanoi tower;
    tower.visualize();
    tower.solve();


    return EXIT_SUCCESS;
}