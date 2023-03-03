#pragma once
#include "pile.h"

typedef struct 
{
    Pile *pile_a;
    Pile *pile_b;
    Pile *pile_c;
} HanoiState;

int hanoi(int num_pieces, void(*callback)(HanoiState*));
