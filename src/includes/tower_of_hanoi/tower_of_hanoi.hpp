#ifndef TOWER_OF_HANOI
#define TOWER_OF_HANOI
#include "state.hpp"
#include "stack.hpp"
#include <iostream>
#include <string>
#include <vector>

void usage(std::string msg = "");

class Tower_of_Hanoi{

    public:

    Tower_of_Hanoi(){

    };

    void visualize() const;
    void solve();

};

#endif