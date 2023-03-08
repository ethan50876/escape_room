#ifndef RENDER_H
#define RENDER_H

#include <osbind.h>
#include "raster.h"
#include "bitmaps.h"


void render_room1 (UINT32 *base, Model *model);
void render_player_r1 (UINT32 *base, const Player player);
void render_key_r1 (UINT32 *base);
void render_door_r1 (UINT32 *base);
void render_map (UINT32 *base);

#endif