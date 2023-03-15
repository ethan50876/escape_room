#ifndef MODEL_H
#define MODEL_H

#include <stdio.h>
#include <osbind.h>
#include "TYPES.H"

typedef struct Player {
    int x;
    int y;
    Direction direction;

} Player;



typedef struct Model {
    Player player;

	
} Model;



void move_player(Player *player, Direction direction);
void initialize_player(Player *player);
void initialize_game(Model *model);

#endif