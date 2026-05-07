
#include <stdio.h>
#include "board.h"

int main() {
    Board board;
    int x, y;

    init_board(&board);

    while (1) {
        display_board(&board);

        printf("Enter position (x y): ");
        scanf("%d %d", &x, &y);

        reveal_cell(&board, x - 1, y - 1); // Ajustement pour indexation 0
    }

    return 0;
} 