#include "tower_of_hanoi.hpp"

#define YES 1
#define NO 0

#define NUMBER_VISUALIZE YES

void usage(std::string msg){
    if (not msg.empty()){
        std::cout << "  ERROR: " << msg;
    }
    else {
        std::cout << "  Welcome to Tower_of_Hanoi.\n\n";
    }
}

bool Tower_of_Hanoi::is_valid_move (const State& piece) const{
    auto cmp {towers[piece.destination].peek().disc_size};
    return piece.disc_size < cmp;
}

void Tower_of_Hanoi::visualize() const{
    #if NUMBER_VISUALIZE
    std::ostringstream out{};

    for (int i {0}; i < 3; i++){
        if (i == 0) out << "A <- ";
        else if (i == 1) out << "B <- ";
        else out << "C <- ";

        if (not towers[i].empty()){
            sc::Stack twr (towers[i]);
            twr.reverse();

            for (auto ptr {twr.cbegin()}; ptr != nullptr; ptr++){
                out << (*ptr).disc_size;
            }
        }

        out << "\n\n";
    }

    std::cout << out.str();
    #endif
}

void Tower_of_Hanoi::solve(){
    this->visualize();  //we'll first, visualize the tower

    for (auto i{0}; i < max_moves; i++){
        std::cout << ++moves << ")\n";
        
    }

    usage("[solve]: NOT IMPLEMENTED YET.\n");
}