#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"

// fonctions pour initialiser et afficher le plateau
void init_board(Board *board) {

    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {

        for (int j = 0; j < SIZE; j++) {

            board->grid[i][j].type = rand() % 6;

            board->grid[i][j].revealed = 0;

            board->grid[i][j].playerNumber = 0;
        }
    }
}

// Affiche le plateau (X pour non révélé, type pour révélé)
void display_board(Board *board) {

    printf("\n   1 2 3 4 5\n");

    for (int i = 0; i < SIZE; i++) {

        printf("%d  ", i + 1);

        for (int j = 0; j < SIZE; j++) {

            // afficher joueur
            if (board->grid[i][j].playerNumber > 0) {

                printf("%d ", board->grid[i][j].playerNumber);
            }

            // afficher case révélée
            else if (board->grid[i][j].revealed) {

                printf("O ");
            }

            // case cachée
            else {

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

    board->grid[x][y].revealed = 1; // revealed = ça révèle la cellule
}

void place_player(Board *board, int x, int y, int playerNumber) {

    board->grid[x][y].playerNumber = playerNumber;
}

void remove_player(Board *board, int x, int y) {

    board->grid[x][y].playerNumber = 0;
}

void hide_board(Board *board) {

    for (int i = 0; i < SIZE; i++) {

        for (int j = 0; j < SIZE; j++) {

            board->grid[i][j].revealed = 0;
        }
    }
}
