#include "render.h"


void render_room1 (UINT32 *base, UINT32 player, UINT32 key, UINT32 door, UINT32 room, UINT32 heldslot) {
	
	render_map(base, room);
	render_player_r1(base, player);
	render_key_r1(base, key);
	render_door_r1(base, door);
	render_held_r1(base, heldslot);
	
}

void render_map (UINT32 *base, UINT32 room) {
	
	plot_room(base, room);
	
}

void render_player_r1 (UINT32 *base, UINT32 player) {

	plot_bitmap_32(base, player, 340, 150, 32);

}

void render_key_r1 (UINT32 *base, UINT32 key) {

	plot_bitmap_32(base, key, 350, 300, 32);
	
}

void render_door_r1 (UINT32 *base, UINT32 door) {
	
	plot_bitmap_32(base, door, 288 , 0, 32);
	
}

void render_held_r1 (UINT32 *base, UINT32 heldslot) {
	
	plot_bitmap_32(base, heldslot, 580, 300, 32);
	
}
