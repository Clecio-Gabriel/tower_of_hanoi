#ifndef TOWER_OF_HANOI
#define TOWER_OF_HANOI
#include "state.hpp"
#include "stack.hpp"
#include <string>
#include <cmath>
#include <sstream>
#include <vector>

void usage(std::string msg = "");

class Tower_of_Hanoi{
    private:
    sc::Stack<State> towers [3];
    int peek_times;
    int moves;
    int max_moves;

    size_t coord_check;

    // invisible methods
    bool is_valid_move (const State& piece) const; //to check if a move is valid
    void visualize() const; //visualize the tower

    public:

    Tower_of_Hanoi(size_t num_discs)
    : peek_times(0), moves(0), coord_check(0)
    {
        for (size_t i {num_discs}; i > 0; i--){
            towers[0].push(State(i));
        }

        max_moves = static_cast<int>(std::pow(2, num_discs));
        max_moves--;
    };

    
    void solve();

};

#endif