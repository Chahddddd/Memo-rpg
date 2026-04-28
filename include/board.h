#ifndef BOARD_H
#define BOARD_H

#define SIZE 5

// types de cellules
typedef enum {
    EMPTY,
    MONSTER,
    TREASURE,
    WEAPON,
    PORTAL,
    TOTEM
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

#endif