#ifndef RENDER_H
#define RENDER_H

#include <osbind.h>
#include "raster.h"
#include "bitmaps.h"
#include "rooms.h"
#include "model.h"


void render_room1 (UINT32 *base, Model *model);
void render_player(UINT32 *base, Player *player);
void render_key_r1 (UINT32 *base);
void render_door_r1 (UINT32 *base);
void render_map (UINT32 *base);
void render_player_test (UINT32 *base, Player *player);
void render_curr_room (UINT32 *base, Model *model, int curr);
void render_door (UINT32 *base, Door *door);
void render_item (UINT32 *base, Item *item);
void render_heldslot (UINT32 *base, Player *player);

#endif