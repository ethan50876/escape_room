#include "model.h"

void move_player(Player *player, Direction direction) {
	switch (direction) {
		case left:
		player->x -= GRID_VALUE;
		case right:
		player->x += GRID_VALUE;
		case up:
		player->y -= GRID_VALUE;
		case down:
		player->y += GRID_VALUE;
		default:
		break;
	}

}

void initialize_player(Player *player) {
	player->x = 320;
	player->y = 200;
	
}
void initialize_game(Model *model){
	
	initialize_player(&model->player);
	
}
