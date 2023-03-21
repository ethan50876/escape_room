#ifndef ESCAPE_H
#define ESCAPE_H

#include <stdio.h>
#include <osbind.h>
#include "TYPES.H"
#include "event.h"
#include "model.h"
#include "render.h"
#include "clear.h"

void async_events(Model* model, UINT32* base);
void game_loop();
UINT8 *get_base(UINT8 *buffer);
long get_time();

#endif