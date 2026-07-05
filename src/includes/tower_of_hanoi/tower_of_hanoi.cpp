#include "tower_of_hanoi.hpp"

#define YES 1
#define NO 0

#define NUMBER_VISUALIZE NO

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
    out << "A <-";
    
    

    std::cout << out.str();
    #endif
}

void Tower_of_Hanoi::solve(){
    this->visualize();  //we'll first, visualize the tower

    usage("[solve]: NOT IMPLEMENTED YET.\n");
}