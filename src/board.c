#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"

// fonctions pour initialiser et afficher le plateau
void init_board(Board *board) {
    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board->grid[i][j].type = rand() % 6; // random type
            board->grid[i][j].revealed = 0;
        }
    }
}

// Affiche le plateau (X pour non révélé, type pour révélé)
void display_board(Board *board) {
    printf("\nBoard:\n");

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            if (board->grid[i][j].revealed) {
                printf("%d ", board->grid[i][j].type);
            } else {
                printf("X ");
            }

        }
        printf("\n");
    }
}
// Fonction pour révéler une cellule
void reveal_cell(Board *board, int x, int y) {
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
        printf("Invalid position\n");
        return;
    }

    board->grid[x][y].revealed = 1;
}
