#pragma once
#include <stdlib.h>

typedef struct
{
    int* elems;
    size_t size;
    size_t index;
} Pile;

Pile* init_pile(size_t);

void clear_pile(Pile*);

void push(Pile*, int);

int pop(Pile*);