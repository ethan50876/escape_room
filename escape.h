#ifndef ESCAPE_H
#define ESCAPE_H

#include <stdio.h>
#include <osbind.h>
#include "TYPES.H"
#include "event.h"
#include "render.h"

void async_events(Model* model, UINT32* base);
void game_loop();

#endif