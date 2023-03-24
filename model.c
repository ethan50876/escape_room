#include "model.h"


/* Param:  Player Struct, Room struct, Direction struct
*  Return: Void
*  Purpose: uses direction to change the players coordinates on the grid to allow movement. 
*/
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

/* Param:  Player struct, int, int
*  Return: Void
*  Purpose: sets players starting coordinates on the grid 
*/
void set_player(Player *player, int x, int y) {
	
	player->x = x;
	player->y = y;
	
}
/* Param:  Player struct
*  Return: void
*  Purpose: initializes the player for the first room.
*/
void initialize_player(Player *player) {

	set_player(player, 320, 300);
	player->heldslot_ID = 0;

}

/* Param:  Model struct
*  Return: void
*  Purpose: initializes the different bitmaps and values in the rooms. 
*/
void initialize_game(Model *model){
	
	initialize_array(model);
	initialize_player(&model->player);

	
	
}


/* Param:  Room struct
*  Return: void
*  Purpose: 
*/
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
	 
	 room->door_array[0].locked = true;
	 room->door_array[0].door_ID = 1;
	 room->door_array[0].rotate = 0;
	 room->door_array[0].door_box.x1 = 288;
	 room->door_array[0].door_box.x2 = 320;
	 room->door_array[0].door_box.y1 = 0;
	 room->door_array[0].door_box.y2 = 64;
	 room->actual_doors = 1;
	 
	 room->item.on_stage = true;
	 room->item.item_ID = 1;
	 room->item.item_box.x1 = 352;
	 room->item.item_box.x2 = 384;
	 room->item.item_box.y1 = 320;
	 room->item.item_box.y2 = 352;
	 

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

/* Param:  Player struct, Room struct, Direction struct
*  Return: a bool (typedef int - 0 representing false and 1 representing true)
*  Purpose: Checks the players diretion and current placement on the grid, then compares the players current grid value to the set boundry.
*           stops the player is they encounter a boundry location.
*/
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

/* Param:  Player struct Bound struct
*  Return: a bool (typedef int - 0 representing false and 1 representing true)
*  Purpose: Checks for a collisiom between an item or door, if the grid space occupied by the item/door is encountered by the player, set to true 
*           so an action can be completed. (ie... switch room, pick up key)
*/
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


void update_heldslot (Player *player, Item *item) {
	
	player->heldslot_ID = item->item_ID;
}





