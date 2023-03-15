#include "model.h"

void move_player(Player *player, Direction direction) {
	switch (direction) {
		case left:
		player->x -= GRID_VALUE;
		break;
		case right:
		player->x += GRID_VALUE;
		break;
		case up:
		player->y -= GRID_VALUE;
		break;
		case down:
		player->y += GRID_VALUE;
		break;
		default:
		break;
	}

}

void initialize_player(Player *player) {
	player->x = 320;
	player->y = 64;
	
}
void initialize_game(Model *model){
	
	initialize_player(&model->player);
	
}

