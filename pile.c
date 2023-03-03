#include "pile.h"

Pile* init_pile(size_t size) 
{
    Pile *pile = malloc(sizeof(Pile));
    pile->elems = calloc(sizeof(int), size);
    pile->size = size;
    pile->index = -1;

    return pile;
}

void clear_pile(Pile *pile)
{
    free(pile->elems);
    free(pile);
}

void push(Pile *pile, int value)
{
    // Pile is full.
   if(pile->index == pile->size) {
    return;
   }
   pile->elems[++pile->index] = value;
}

int pop(Pile *pile)
{
    // Pile is full
    if(pile->index < 0){
        return -1;
    }
    return pile->elems[pile->index--];
}