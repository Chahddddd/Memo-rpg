#include <stdio.h>
#include "board.h"
#include "player.h"

int main() {

    Board board;

    Player players[4];

    int numberOfPlayers;

    char playerName[MAX_NAME];

    int x, y;

    // Initialisation du plateau
    init_board(&board);

    // Choix du nombre de joueurs
    do {
        printf("Enter number of players (2-4): ");
        scanf("%d", &numberOfPlayers);

    } while (numberOfPlayers < 2 || numberOfPlayers > 4);

    // Création des joueurs
    for (int i = 0; i < numberOfPlayers; i++) {

        printf("\nEnter name for player %d: ", i + 1);
        scanf("%49s", playerName);

        // Pour l'instant :
        // classes automatiques selon l'ordre
        init_player(&players[i], playerName, i, 0, 0);
    }

    // Boucle de jeu
    while (1) {

        display_board(&board);

        // Tour de chaque joueur
        for (int i = 0; i < numberOfPlayers; i++) {

            printf("\n===== PLAYER %d TURN =====\n", i + 1);

            display_player(&players[i]);

            printf("Enter position (1-5) (x y): ");

            if (scanf("%d %d", &x, &y) != 2) {
                printf("Invalid input\n");
                return 1;
            }

            reveal_cell(&board, x - 1, y - 1);

            move_player(&players[i], x - 1, y - 1);
        }
    }

    return 0;
}