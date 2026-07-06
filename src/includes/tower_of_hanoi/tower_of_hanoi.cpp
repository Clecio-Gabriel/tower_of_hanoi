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
    if (towers[piece.destination].empty()) return true;

    auto cmp {towers[piece.destination].peek().disc_size};
    return piece.disc_size < cmp;
}

void Tower_of_Hanoi::change_coord_check(){
    if (tower_parity)   //odd case
        coord_check = (coord_check + 1) % 3;
    else{               //even case
        if (coord_check == 0) coord_check = 2;
        else coord_check--;
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
    std::cout << "INITIAL STATE:\n";
    this->visualize();  //we'll first, visualize the tower

    for (auto i{0}; i < max_moves; i++){
        std::cout << ++moves << ")\n";
        while (true){
            if (not towers[coord_check].empty()){
                auto disc {towers[coord_check].peek()};
                comparisons++;
                if (is_valid_move(disc)){
                    std::cout << "Movimento valido\n";
                    towers[coord_check].pop();
                    auto dt {disc.destination};
                    disc.change_action();
                    std::cout << disc.disc_size << "->" << dt << '\n'
                            << "Próximo destino: " << disc.destination << '\n';
                    towers[dt].push(disc);
                    break;
                }
                else this->change_coord_check();
            }
            else this->change_coord_check();
        }

        this->visualize();
    }

}