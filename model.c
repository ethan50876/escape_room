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