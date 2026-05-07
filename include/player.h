#ifndef PLAYER_H
#define PLAYER_H

#define MAX_NAME 50

// Classes des aventuriers
typedef enum {
    WARRIOR, // classe de guerrier
    RANGER, // classe de ranger
    MAGE, // classe de mage
    THIEF // classe de voleur
} PlayerClass;

// Armes utilisables
typedef enum {
    SHIELD, // arme de bouclier
    TORCH, // arme de torche
    BOW, // arme d'arc
    AXE // arme de hache
} Weapon;

// Structure joueur
typedef struct {
    char name[MAX_NAME]; // nom du joueur

    PlayerClass playerClass; // classe du joueur

    int x;
    int y;

    Weapon currentWeapon; // arme actuelle du joueur

    int hasTreasure; // le joueur a-t-il trouvé un trésor ?
    int hasAncientWeapon; // le joueur a-t-il trouvé une arme ancienne ?

    int alive; // le joueur est-il vivant ?
    int blocked; // le joueur est-il bloqué ?

    int wins; // nombre de victoires
    int gamesPlayed; // nombre de parties jouées

} Player;

// fonctions
void init_player(Player *player, char name[], PlayerClass playerClass, int startX, int startY);
void display_player(Player *player);
void move_player(Player *player, int newX, int newY);
void reset_player(Player *player, int startX, int startY);

#endif