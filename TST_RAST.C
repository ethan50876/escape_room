#include <osbind.h>
#include "raster.h"
#include "bitmaps.h"


int main()
{
	
	void *base = Physbase();

	
	blank_screen();
	
	plot_bitmap_8(base, player8x8, 300, 100, 8);
	
	
	plot_bitmap_16(base, player16x16, 300, 150, 16);
	
	
	plot_bitmap_32(base, player32x32, 300, 200, 32);
	
	
	plot_bitmap_32(base, blockA, 100, 100, 32);
	

	plot_bitmap_32(base, blockB, 100, 150, 32);
	

	plot_bitmap_32(base, blockC, 100, 200, 32);
	

	plot_bitmap_32(base, blockD, 100, 250, 32);

	
	plot_bitmap_32(base, heldslot, 200, 100, 32);
	
	
	plot_bitmap_32(base, key_demo, 200, 150, 32);
	
	
	plot_bitmap_32(base, projectile, 200, 200, 32);
	
	
	plot_bitmap_32(base, trash_bin, 200, 250, 32);
	


	
	

	return 0;
}
