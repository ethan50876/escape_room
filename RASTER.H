#ifndef RASTER_H
#define RASTER_H

#include "types.h"

#define BYTES_PER_SCREEN 32000
#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 400


void blank_screen();
void fill_screen(UINT8 *base, UINT8 pattern);
void plot_point(UINT8 *base, int x, int y); 
void plot_vline(UINT8 *base, int x, int y1, int y2);
void plot_hline(UINT8 *base, int x1, int x2, int y);
void plot_rectangle(UINT8 *base, int x, int y, int height, int length);

#endif
