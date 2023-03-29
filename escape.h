#ifndef ESCAPE_H
#define ESCAPE_H

#include <stdio.h>
#include <osbind.h>
#include "TYPES.H"
#include "event.h"
#include "model.h"
#include "render.h"


void on_switch_room(Model *model);
void async_events(Model* model, UINT32* base);
void sync_events(Model *model, UINT32 *base);
void game_loop();
UINT8 *get_base(UINT8 *buffer);
long get_time();

#endif