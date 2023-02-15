#include "raster.h"



void blank_screen()
{
	printf("\033E\033f\n");					/* blanks screen and hides cursor */
}

void fill_screen(UINT8 *base, UINT8 pattern)
{
	int i = 0;
	UINT8 *loc = base;

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
		*(base + (y1 + i) * 80 + (x >> 3)) ^= 1 << (7 - (x & 7));
			}
}

void plot_hline(UINT8 *base, int x1, int x2, int y) {
	
	int i;
	int width = x2 - x1;
	
	UINT8 *loc = base + (y * 80) + (x1 + 8 >> 3);
	
	
	for (i = 0; i < (width >> 3); i++) {
		*(loc++) ^= 0xff;
	}
	
}

void plot_rectangle(UINT8 *base, int x, int y, int height, int length) {
	
	plot_vline(base, x, y, y + height);
	plot_vline(base, x + length, y, y + height);
	plot_hline(base, x, x + length, y);
	plot_hline(base, x, x + length, y + height);
	
}


