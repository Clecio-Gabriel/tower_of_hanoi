#ifndef STATE
#define STATE

#include <cstddef>

struct State{
    size_t disc_size;
    size_t origin;
    size_t destination;
    size_t aux;
    size_t action;

    State(size_t ds, size_t o, size_t dt, size_t aux, size_t act)
    : disc_size(ds), origin(o), destination(dt), aux(aux), action(act)
    {};
    
};

#endif