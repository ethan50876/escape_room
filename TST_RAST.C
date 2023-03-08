#include <osbind.h>
#include "raster.h"
#include "bitmaps.h"
#include "rooms.h"
#include "render.h"


int main()
{
	
	void *base = Physbase();

	
	blank_screen();
	
	render_room1(base, player32x32, key_demo, door, demo_room, heldslot);	
	

	return 0;
}
