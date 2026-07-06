#ifndef STATE
#define STATE

#include <cstddef>

struct State{
private:
    size_t aux_even [3] = {0, 1, 2};
    size_t aux_odd [3] = {0, 2, 1};
    size_t* action;

public:
    size_t disc_size;
    size_t origin;
    size_t destination;

    State(size_t ds) : disc_size(ds)
    {
        if (ds%2==0) action = aux_even; 
        else action = aux_odd;

        origin = *action;
        destination = *(action+1);
    };
    
    void change_action(){
        if (disc_size % 2 == 0){
            if (action > (aux_even + 2)) action = aux_even;
            else action++;

        }
        else if (disc_size % 2 != 0){
            if (action > (aux_odd + 2)) action = aux_odd;
            else action++;

        }

        origin = *action;
        destination = *(action+1);
    }

};

#endif