#include "render.h"






void render_map (UINT32 *base) {
	
	plot_room(base, demo_room);
	
}


void render_proj_room (UINT32 *base) {
	
	plot_room(base, proj_room);
	
}

void render_player(UINT32 *base, Player *player) {

	plot_bitmap_16((UINT16*) base, player16x16, player->x, player->y, 16);

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
void render_player_test (UINT32 *base, Player *player) {

	plot_bitmap_16((UINT16*)base, player16x16, 320, 336, 16);

}

void render_room1 (UINT32 *base, Model *model) {
	
	render_map(base);
	render_player(base, &model->player);
	render_key_r1(base);
	render_door_r1(base);
	render_held_r1(base);

	
	
}
void render_projectiles(UINT32 *base) {
	plot_bitmap_32(base, projectile, 576, 336, 32);
	plot_bitmap_32(base, projectile, 64, 304, 32);
	plot_bitmap_32(base, projectile, 576, 240, 32);
	plot_bitmap_32(base, projectile, 64, 176, 32);
	plot_bitmap_32(base, projectile, 576, 144, 32);
}

void render_curr_room (UINT32 *base, Model *model, int curr) {
	
	
	switch (curr) {
		
		case 0: 
		render_room1(base, model);		
		break;
		case 1:
		render_proj_room(base);
		render_projectiles(base);
		render_player(base, &model->player);
		
	
		break;
		default:
		break;
	}
	
	render_player(base, &model->player);


	
}