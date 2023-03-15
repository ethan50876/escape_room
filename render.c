#include "render.h"


void render_room1 (UINT32 *base, Model *model) {
	
	render_map(base);
	render_player_r1(base, &model->player);
	render_key_r1(base);
	render_door_r1(base);
	render_held_r1(base);

	
	
}

void render_map (UINT32 *base) {
	
	plot_room(base, demo_room);
	
}

void render_player_r1 (UINT32 *base, Player *player) {

	plot_bitmap_16(base, player16x16, player->x, player->y, 16);

}

void render_key_r1 (UINT32 *base) {

	plot_bitmap_32(base, key_demo, 350, 300, 32);
	
}

void render_door_r1 (UINT32 *base) {
	
	plot_bitmap_32(base, door, 288 , 0, 32);
	
}

void render_held_r1 (UINT32 *base) {
	
	plot_bitmap_32(base, heldslot, 580, 300, 32);
	
}
