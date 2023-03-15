#ifndef EVENT_H
#define EVENT_H

#include <stdio.h>
#include <osbind.h>
#include "TYPES.H"
#include "model.h"


void player_movement(Player *player, unsigned long key_press);

bool has_user_input();

unsigned long get_user_input();


#endif