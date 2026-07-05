#include "tower_of_hanoi.hpp"

#define YES 1
#define NO 0

#define STACK_TEST NO


int main(){

    usage();

    #if STACK_TEST
    sc::Stack a ({1,2,3});
    sc::Stack<int> b;
    std::cout << a << "\n" << a.peek() << '\n' << a.get_size() << "\n" << b.get_size() << '\n';
    a.clear();
    if (a.empty()) std::cout << "true\n";

    std::cout << '\n';

    a.push(10);
    a.push(9);
    a.push(8);
    std::cout << a << ' ' << a.get_size() << '\n';

    std::cout << a.peek() << "\n";

    a.pop();
    std::cout << a << ' ' << a.get_size() << '\n';

    if (a == a) std::cout << "True\n";

    sc::Stack c ({7,31});

    if (a != c) std::cout << "a == c is False\n";

    c.push(28);

    std::cout << "c:" << c << ' ' << c.get_size() << '\n'
              << "a:" << a << "\n\n";
    c = a;
    std::cout << "After using the equal constructor:\n"
              << "c:" << c << '\n'
              << "a:" << a << '\n';
    
    std::cout << '\n' << a.peek() << ' ' << c.peek() << '\n';

    sc::Stack d(a);

    std::cout << "\nd:" << d << ' ' << d.get_size() << '\n';
    #endif

    Tower_of_Hanoi tower;
    tower.solve();


    return EXIT_SUCCESS;
}