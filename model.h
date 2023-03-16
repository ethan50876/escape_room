#ifndef MODEL_H
#define MODEL_H

#include <stdio.h>
#include <osbind.h>
#include "TYPES.H"

typedef struct{
    int x;
    int y;
    Direction direction;

} Player;


typedef struct {
    int x1;
	int x2;
    int y1;
	int y2;
} Bound;

typedef struct {
    Bound left_bound;
	Bound right_bound;
	Bound up_bound;
	Bound down_bound;
	Bound item;
	Bound door;
} Room;



typedef struct { 
	int room_count;
    Player player;
	Room room_array[MAX_ROOMS];
	
} Model;



void move_player(Player *player, Room *room, Direction direction);
void initialize_player(Player *player);
void initialize_game(Model *model);
void initialize_room1(Room *room);
void initialize_array(Model *model);
bool is_in_bounds(Player *player, Room *room, Direction direction);

#endif