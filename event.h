#ifndef EVENT_H
#define EVENT_H

#include <stdio.h>
#include <osbind.h>
#include "TYPES.H"
#include "model.h"
#include "rooms.h"

void on_esc(unsigned long key_press, bool *game_running);
void exit_game(bool *game_running);
void player_movement(Player *player, Room *room, unsigned long key_press);
bool switch_room(Player *player, Door *door);
bool unlock_door(Player *player, Door *door);
void interact(Player *player, Room *room, unsigned long key_press);
void on_proj_move(Room *room, UINT32 *base, int curr_room);
void on_proj_vmove(Room *room, UINT32 *base, int curr_room);
void on_proj_hit(Player *player, Room *room, bool *game_running);


bool has_user_input();

unsigned long get_user_input();


#endif