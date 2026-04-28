#include <stdio.h>

#include "board.h"

int main() {
    Board board;

    init_board(&board);
    display_board(&board);

    return 0;
}