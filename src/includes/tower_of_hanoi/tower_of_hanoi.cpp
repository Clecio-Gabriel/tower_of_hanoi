#include "tower_of_hanoi.hpp"

void usage(std::string msg){
    if (not msg.empty()){
        std::cout << "  ERROR: " << msg;
    }
    else {
        std::cout << "  Welcome to Tower_of_Hanoi.\n\n";
    }
}

void Tower_of_Hanoi::visualize() const{
    usage("[visualize]: NOT IMPLEMENTED YET.\n");
}

void Tower_of_Hanoi::solve(){
    this->visualize();

    usage("[solve]: NOT IMPLEMENTED YET.\n");
}