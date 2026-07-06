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

    usage("[solve]: NOT IMPLEMENTED YET.\n");
}