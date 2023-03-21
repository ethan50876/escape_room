#include "raster.h"




void fill_screen(UINT32 *base, UINT8 pattern)
{
	int i = 0;
	UINT32 *loc = base;

	while (i++ < (BYTES_PER_SCREEN))
		*(loc++) = pattern;
}

void plot_point(UINT8 *base, int x, int y){
	
	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
		*(base + y * 80 + (x >> 3)) |= 1 << (7 - (x & 7));

}

void plot_vline(UINT8 *base, int x, int y1, int y2){
	int i;
	
	for (i = 0; i < (y2 - y1); i++) {
		*(base + (y1 + i) * 80 + (x >> 3)) |= 1 << (7 - (x & 7));
			}
}

void plot_hline(UINT8 *base, int x1, int x2, int y) {
	
	int i;
	int width = x2 - x1;
	
	UINT8 *loc = base + (y * 80) + (x1 >> 3);
	
	
	for (i = 0; i < (width >> 3); i++) {
		*(loc++) |= 0xff;
	}
	
}

void plot_rectangle(UINT8 *base, int x, int y, int height, int length) {
	
	int i = 0;
	UINT8 *loc = base;
	
	for (i = 0; i < height; i ++) {
		plot_hline(loc, x, y, length);
		loc += 80;
	}
	
}

void plot_bitmap_8(UINT8 *base, UINT8 *bitmap, int x, int y, int height) {
  int i;
  UINT8 *loc = base + (y * 80) + (x >> 3);
  for (i = 0; i < height; i++) {
    *loc |= *(bitmap++);
    loc += 80;
  }
}


void plot_bitmap_16(UINT16 *base, UINT16 *bitmap, int x, int y, int height) {
  int i;
  UINT16 *loc = base + (y * 40) + (x >> 4);	
  for (i = 0; i < height; i++) {
    *loc |= *(bitmap++);
    loc += 40;
  }
}

void plot_bitmap_32(UINT32 *base, UINT32 *bitmap, int x, int y, int height) {
  int i;
  UINT32 *loc = base + (y * 20) + (x >> 5);	
  for (i = 0; i < height; i++) {
    *loc |= *(bitmap++);
    loc += 20;
  }
}


void plot_room(UINT32 *base, UINT32 *room) {
  int i;
  for(i = 0; i < 8000; i++)
	*(base + i) = room[i];
 }

void clear_bitmap_8(UINT8 *base, int x, int y, int width, int height) {
  int i;
  UINT8 *draw = base;
  for (i = 0; i < height; i++) {
    clear_hline(draw, x, y, width);
    draw += 80;
  }
}


void clear_bitmap_16(UINT16 *base, int x, int y, int width, int height) {
  int i;
  UINT16 *draw = base;
  for (i = 0; i < height; i++) {
    clear_hline(draw, x, y, width);
    draw += 40;
  }
}


void clear_bitmap_32(UINT32 *base, int x, int y, int width, int height) {
  int i;
  UINT32 *draw = base;
  for (i = 0; i < height; i++) {
    clear_hline(draw, x, y, width);
    draw += 20;
  }
}

void clear_hline(void *base, int x, int y, int width) {
  if (width <= 8)
    clear_hline_8(base, x, y, width);
  else if (width <= 16)
    clear_hline_16(base, x, y, width);
  else
    clear_hline_32(base, x, y, width);
}

void clear_hline_8(UINT8 *base, int x, int y, int width) {
  int i = 0;
  int x_count = width >> 3;
  UINT8 *draw = base + (y * 80) + (x >> 3);

  for (i = 0; i < x_count; i++)
    *(draw++) = 0xff;
}

void clear_hline_16(UINT16 *base, int x, int y, int width) {
  int i = 0;
  int x_count = width >> 4;
  UINT16 *draw = base + (y * 40) + (x >> 4);

  for (i = 0; i < x_count; i++)
    *(draw++) = 0xffff;
}

void clear_hline_32(UINT32 *base, int x, int y, int width) {
  int i = 0;
  int x_count = width >> 5;
  UINT32 *draw = base + (y * 20) + (x >> 5);

  for (i = 0; i < x_count; i++)
    *(draw++) = 0xffffffff;
}