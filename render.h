#ifndef RENDER_H
#define RENDER_H

#include <osbind.h>
#include "raster.h"
#include "bitmaps.h"


void render_room1 (UINT32 *base, UINT32 player, UINT32 key, UINT32 door, UINT32 room, UINT32 heldslot);
void render_player_r1 (UINT32 *base, UINT32 player);
void render_key_r1 (UINT32 *base, UINT32 key);
void render_door_r1 (UINT32 *base, UINT32 door);
void render_map (UINT32 *base, UINT32 room);

#endif