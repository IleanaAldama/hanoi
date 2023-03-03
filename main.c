#include "hanoi.h"
#include <stdio.h>

void print_pile(char *tag, Pile *pile)
{
    int index = pile->index;
    printf("%s: ", tag);
    if (index < 0) {
        printf("empty\n");
        return;
    }
   for(int i = 0; i <= index; i++) {
        printf("%d, ", pile->elems[i]);
    }
    printf("\n");
}

void print_hanoi_state(HanoiState *state)
{
    print_pile("A", state->pile_a);
    print_pile("B", state->pile_b);
    print_pile("C", state->pile_c);
    printf("\n");
}

int main() 
{
    int num_pieces = 3;
    int err = hanoi(num_pieces, print_hanoi_state);
    return err;
}
