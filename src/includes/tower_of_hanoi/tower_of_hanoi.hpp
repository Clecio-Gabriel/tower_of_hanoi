#ifndef TOWER_OF_HANOI
#define TOWER_OF_HANOI
#include "state.hpp"
#include "stack.hpp"
#include <string>
#include <sstream>
#include <vector>

void usage(std::string msg = "");

class Tower_of_Hanoi{
    private:
    sc::Stack<State> towers [3];
    int moves;

    // invisible methods
    bool is_valid_move (const State& piece) const; //to check if a move is valid
    void visualize() const; //visualize the tower

    public:

    Tower_of_Hanoi(size_t num_discs)
    : moves(0)
    {
        for (size_t i {num_discs}; i > 0; i--){
            towers[0].push(State(i, i, i, i, i));
        }
    };

    
    void solve();

};

#endif