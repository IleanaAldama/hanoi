#include <stdlib.h>
#include "hanoi.h"



HanoiState init_state(int num_pieces) 
{
    HanoiState state;

    state.pile_a = init_pile(num_pieces);
    state.pile_b = init_pile(num_pieces);
    state.pile_c = init_pile(num_pieces);

    // Move pieces to pile_a
    for(int i = 0; i < num_pieces; ++i) {
        push(state.pile_a, num_pieces - i);
    }

    return state;
}

void clear_state(HanoiState state) 
{
    clear_pile(state.pile_a);
    clear_pile(state.pile_b);
    clear_pile(state.pile_c);
}

void move(int num_pieces, void (callback)(), Pile *source, Pile *target, Pile *aux) 
{
    if(num_pieces == 0) {
        callback();
        return;
    }

    move(num_pieces - 1, callback, source, aux, target);

    push(target, pop(source));

    move(num_pieces - 1, callback, aux, target, source);
}

int hanoi(int num_pieces, void(*callback)(HanoiState*)) 
{
    HanoiState state = init_state(num_pieces);

    void _callback() { callback(&state); }

    move(num_pieces, _callback, state.pile_a, state.pile_c, state.pile_b);

    clear_state(state);
    return 0;
}