#include "model.h"

void move_player(Player *player, Room *room, Direction direction) {
	switch (direction) {
		case left:
		if (is_in_bounds(player, room, direction))
			player->x -= GRID_VALUE;
			
		break;
		case right:
		if (is_in_bounds(player, room, direction))
			player->x += GRID_VALUE;
		break;
		case up:
		if (is_in_bounds(player, room, direction))
			player->y -= GRID_VALUE;
		break;
		case down:
		if (is_in_bounds(player, room, direction))
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
	
	initialize_array(model);
	initialize_player(& model->player);
	
	
}


void initialize_room1(Room *room) {
	 
	 room->up_bound.x1 = 0;
	 room->up_bound.x2 = 640;
	 room->up_bound.y1 = 0;
	 room->up_bound.y2 = 16;
	 
	 room->right_bound.x1 = 608;
	 room->right_bound.x2 = 640;
	 room->right_bound.y1 = 0;
	 room->right_bound.y2 = 400;
	 
	 room->left_bound.x1 = 0;
	 room->left_bound.x2 = 16;
	 room->left_bound.y1 = 0;
	 room->left_bound.y2 = 400;
	 
	 room->down_bound.x1 = 0;
	 room->down_bound.x2 = 640;
	 room->down_bound.y1 = 368;
	 room->down_bound.y2 = 400;
	 

}

void initialize_array(Model *model){
	
	initialize_room1(&(model->room_array[0]));
}

bool is_in_bounds(Player *player, Room *room, Direction direction) {
	
	switch (direction) {
		
		case left: 
		if (player->x - GRID_VALUE > room->left_bound.x2)
			return true;
			else
				return false;
		
		case right:
		if ((player->x) + GRID_VALUE < room->right_bound.x1)
			return true;
			else
				return false;
		
		case down:
		if ((player->y) + GRID_VALUE < room->down_bound.y1)
			return true;
			else
				return false;
		
		case up:
		if ((player->y) - GRID_VALUE > room->up_bound.y2)
			return true;
			else
				return false;
		
		default:
		break;
	}
	
	
}