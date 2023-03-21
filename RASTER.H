#ifndef RASTER_H
#define RASTER_H

#include "types.h"


#define BYTES_PER_SCREEN 32000
#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 400


void fill_screen(UINT32 *base, UINT8 pattern);
void plot_point(UINT8 *base, int x, int y); 
void plot_vline(UINT8 *base, int x, int y1, int y2);
void plot_hline(UINT8 *base, int x1, int x2, int y);
void plot_rectangle(UINT8 *base, int x, int y, int height, int length);
void plot_bitmap_8(UINT8 *base, UINT8 *bitmap, int x, int y, int height);
void plot_bitmap_16(UINT16 *base, UINT16 *bitmap, int x, int y, int height);
void plot_bitmap_32(UINT32 *base, UINT32 *bitmap, int x, int y, int height);
void plot_room(UINT32 *base, UINT32 *room);
void clear_bitmap_8(UINT8 *base, int x, int y, int width, int height);
void clear_bitmap_16(UINT16 *base, int x, int y, int width, int height);
void clear_bitmap_32(UINT32 *base, int x, int y, int width, int height);
void clear_hline(void *base, int x, int y, int width);
void clear_hline_8(UINT8 *base, int x, int y, int width);
void clear_hline_16(UINT16 *base, int x, int y, int width);
void clear_hline_32(UINT32 *base, int x, int y, int width);



#endif
