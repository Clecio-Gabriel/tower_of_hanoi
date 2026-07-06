#ifndef STATE
#define STATE

#include <cstddef>
#include <vector>

struct State{
private:
    std::vector<size_t> aux_even;
    std::vector<size_t> aux_odd;
    size_t action_ptr;
    size_t origin_ptr;

public:
    size_t disc_size;
    size_t origin;
    size_t destination;

    State(size_t ds, bool isOddNumDiscs) : disc_size(ds)
    {
        if (isOddNumDiscs){
            aux_even = {0, 1, 2};
            aux_odd = {0, 2, 1};
        }
        else{
            aux_even = {0, 2, 1};
            aux_odd = {0, 1, 2};
        }

        origin_ptr = 0;
        action_ptr = 1;

        get_new_val();

    };
    
    void change_action(){
        origin_ptr = action_ptr;
        action_ptr = (action_ptr + 1) % 3;
        
        get_new_val();
    }

    void get_new_val(){
        const auto& aux = (disc_size % 2 == 0) ? aux_even : aux_odd;
        origin = aux[origin_ptr];
        destination = aux[action_ptr];
        
    }

};

#endif