#ifndef MODEL_H
#define MODEL_H

#include <stdio.h>
#include <osbind.h>
#include "TYPES.H"

/* 
Struct: Player
Fields: int x - x-cord of top-left vertex
	int y - y-cord of top-left vertex
	Direction direction - the direction the player is moving in (strictly cardinal direction)
*/
typedef struct{
    int x;				
	int y;				
    Direction direction;

} Player;

/* 
Struct: Bound
Purpose: Represents a rectangle box as a hitbox/bound for items/doors
Fields: int x1 -  left boundary
	int x2 -  right boundary
	int y1 -  top boundary
	int y2 -  bottom boundary
*/
typedef struct {
    int x1;
	int x2;
    int y1;
	int y2;
} Bound;

/* 
Struct: Door
Fields: Bound door_box - Bound struct representing the boundaries/hitbox of the door
	bool locked - int typedef representing the locked status of the door
*/
typedef struct {
	Bound door_box;
	bool locked;
} Door;

/* 
Struct: Room
Fields: Bound left_bound - rectangle of left wall in room
	Bound right_bound - rectangle of right wall in room
	Bound up_bound - rectangle of top wall in room
	Bound down_bound - rectangle of bottom wall in room
	Bound item - to-be made into it's own struc
	Door door_array[MAX_DOORS] - Door array representing the present doors in a room

*/
typedef struct {
    Bound left_bound; /* each bound has 3 unused fields for checking.  simplify later */
	Bound right_bound;
	Bound up_bound;
	Bound down_bound;
	Bound item;        /* to be shifted to it's own struct w/ fields representing status*/
	Door door_array[MAX_DOORS];
} Room;


/* 
Struct: Model
Fields: Player player - a Player struct representing the controllable player
	Room room_array[MAX_ROOMS] - a Room array representing the entire collection of rooms in the game
*/
typedef struct { 
	/*int room_count;*/
    Player player;
	Room room_array[MAX_ROOMS];
	
} Model;



void move_player(Player *player, Room *room, Direction direction);
void set_player(Player *player, int x, int y);
void initialize_player(Player *player);
void initialize_game(Model *model);
void initialize_room1(Room *room);
void initialize_array(Model *model);
bool is_in_bounds(Player *player, Room *room, Direction direction);
bool collided (Player *player, Bound *bound);

#endif
