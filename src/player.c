#include <stdio.h>
#include <string.h>
#include "player.h"

// Initialiser un joueur
void init_player(Player *player, char name[], PlayerClass playerClass, int startX, int startY) {

    strcpy(player->name, name);

    player->playerClass = playerClass;

    player->x = startX;
    player->y = startY;

    player->currentWeapon = SHIELD;

    player->hasTreasure = 0;
    player->hasAncientWeapon = 0;

    player->alive = 1;
    player->blocked = 0;

    player->wins = 0;
    player->gamesPlayed = 0;
}

// Afficher les infos du joueur
void display_player(Player *player) {

    printf("\n=== PLAYER INFO ===\n");

    printf("Name: %s\n", player->name);

    printf("Position: (%d, %d)\n", player->x + 1, player->y + 1);

    printf("Treasure: %s\n", player->hasTreasure ? "YES" : "NO");

    printf("Ancient Weapon: %s\n", player->hasAncientWeapon ? "YES" : "NO");

    printf("Alive: %s\n", player->alive ? "YES" : "NO");

    printf("Wins: %d\n", player->wins);

    printf("Games Played: %d\n", player->gamesPlayed);
}

// Déplacer le joueur
void move_player(Player *player, int newX, int newY) {

    player->x = newX;
    player->y = newY;
}

// Reset du joueur
void reset_player(Player *player, int startX, int startY) {

    player->x = startX;
    player->y = startY;

    player->alive = 1;
    player->blocked = 0;

    player->hasTreasure = 0;
    player->hasAncientWeapon = 0;
}