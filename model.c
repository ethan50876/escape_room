#include "model.h"


/* docu */
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
void set_player(Player *player, int x, int y) {
	
	player->x = x;
	player->y = y;
	
}

void initialize_player(Player *player) {

	set_player(player, 320, 300);

}
void initialize_game(Model *model){
	
	initialize_array(model);
	initialize_player(&model->player);
	/*model->room_count = 0;*/
	
	
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
	 
	 room->door_array[0].locked = false;
	 room->door_array[0].door_box.x1 = 288;
	 room->door_array[0].door_box.x2 = 320;
	 room->door_array[0].door_box.y1 = 16;
	 room->door_array[0].door_box.y2 = 64;
	 

}
void initialize_room2(Room *room) {
	 
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
	 
	/* room->door_array[0].locked = true;
	 room->door_array[0].door_box.x1 = 288;
	 room->door_array[0].door_box.x2 = 320;
	 room->door_array[0].door_box.y1 = 16;
	 room->door_array[0].door_box.y2 = 64; */
	 
	 room->door_array[1].locked = false;
	 room->door_array[1].door_box.x1 = 288;
	 room->door_array[1].door_box.x2 = 320;
	 room->door_array[1].door_box.y1 = 336;
	 room->door_array[1].door_box.y2 = 400;
	 
	 

}


void initialize_array(Model *model){
	
	initialize_room1(&(model->room_array[0]));
	initialize_room2(&(model->room_array[1]));
}

/* docu */
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

/* docu */
bool collided (Player *player, Bound *bound) {
	
	if ((player->x >= bound->x1) && (player->x <= bound->x2)) {
		if ((player->y >= bound->y1) && (player->y <= bound->y2)) {
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
	

	/*switch (direction) {
		
		case left: 
		if (player->x <= bound->x2)
			return true;
			else
				return false;
		
		case right:
		if (player->x >= bound->x1)
			return true;
			else
				return false;
		
		case down:
		
		if (player->y >= bound->y1)
			return true;
			else
				return false;
		
		case up:
		if (player->y <= bound->y2)
			return true;
			else
				return false;
		
		default:
		break;
	}
*/

}