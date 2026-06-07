#ifndef TOWER_OF_HANOI
#define TOWER_OF_HANOI
#include "state.hpp"
#include "stack.hpp"
#include <vector>

class tower_of_hanoi{

    public:

    tower_of_hanoi(){

    };

    void visualize() const;
    void solve();

};

#endif