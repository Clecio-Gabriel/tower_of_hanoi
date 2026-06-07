#include "tower_of_hanoi.hpp"

int main(){

    usage();

    Tower_of_Hanoi tower;
    tower.visualize();
    tower.solve();


    return EXIT_SUCCESS;
}