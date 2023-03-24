#ifndef EVENT_H
#define EVENT_H

#include <stdio.h>
#include <osbind.h>
#include "TYPES.H"
#include "model.h"


void player_movement(Player *player, Room *room, unsigned long key_press);
bool switch_room(Player *player, Door *door);
bool unlock_door(Player *player, Door *door);
void interact(Player *player, Room *room, unsigned long key_press);

bool has_user_input();

unsigned long get_user_input();


#endif