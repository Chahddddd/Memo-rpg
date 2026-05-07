#ifndef BOARD_H
#define BOARD_H

#define SIZE 5

// types de cellules
typedef enum {
    EMPTY, // cellule vide
    MONSTER, // cellule avec un monstre
    TREASURE, // cellule avec un trésor
    WEAPON, // cellule avec une arme
    PORTAL, // cellule avec un portail
    TOTEM // cellule avec un totem
} CellType;

// structure de la cellule et du plateau
typedef struct {
    CellType type;
    int revealed;
} Cell;

// structure du plateau
typedef struct {
    Cell grid[SIZE][SIZE];
} Board;

// fonctions
void init_board(Board *board);
void display_board(Board *board);
void reveal_cell(Board *board, int x, int y);

#endif
