#ifndef MODEL_H
#define MODEL_H

#include <stdio.h>
#include <osbind.h>
#include "TYPES.H"

/* docu */
typedef struct{
    int x;				/*x-cord of top-left vertex */
	int y;				/*y-cord of top-left vertex */
    Direction direction;

} Player;

/* docu */
typedef struct {
    int x1;
	int x2;
    int y1;
	int y2;
} Bound;

/* docu */
typedef struct {
	Bound door_box;
	bool locked;
} Door;

/* docu */
typedef struct {
    Bound left_bound; /* each bound has 3 unused fields for checking.  simplify later */
	Bound right_bound;
	Bound up_bound;
	Bound down_bound;
	Bound item;        /* to be shifted to it's own struct w/ fields representing status*/
	Door door_array[MAX_DOORS];
} Room;


/* docu */
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