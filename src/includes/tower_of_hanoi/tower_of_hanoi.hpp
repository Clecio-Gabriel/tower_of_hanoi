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
    bool tower_parity;
    int comparisons;
    int moves;
    int max_moves;

    size_t coord_check;

    // invisible methods
    bool is_valid_move (const State& piece) const; //to check if a move is valid
    void change_coord_check();  //to change the coordinate that is checking stuff
    void visualize() const; //visualize the tower

    public:

    Tower_of_Hanoi(size_t num_discs)
    : comparisons(0), moves(0), coord_check(0)
    {
        auto tp {num_discs % 2 != 0};
        tower_parity = tp;
        for (size_t i {num_discs}; i > 0; i--){
            towers[0].push(State(i, tower_parity));
        }

        max_moves = static_cast<int>(std::pow(2, num_discs));
        max_moves--;
    };

    
    void solve();
    const int& get_comparisons(){ return comparisons; };

};

#endif