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
void initialize_room0(Room *room) {
	 
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
	 room->down_bound.y1 = 352;
	 room->down_bound.y2 = 400;
	 
	 room->door_array[0].locked = true;
	 room->door_array[0].door_ID = 1;
	 room->door_array[0].rotate = 0;
	 room->door_array[0].door_box.x1 = 288;
	 room->door_array[0].door_box.x2 = 320;
	 room->door_array[0].door_box.y1 = 0;
	 room->door_array[0].door_box.y2 = 32;
	 room->actual_doors = 1;
	 
	 room->item.on_stage = true;
	 room->item.item_ID = 1;
	 room->item.item_box.x1 = 352;
	 room->item.item_box.x2 = 384;
	 room->item.item_box.y1 = 320;
	 room->item.item_box.y2 = 352;
	 


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
	 room->door_array[0].door_box.y2 = 48; 
	 
	 room->door_array[1].locked = false;
	 room->door_array[1].door_box.x1 = 288;
	 room->door_array[1].door_box.x2 = 320;
	 room->door_array[1].door_box.y1 = 368;
	 room->door_array[1].door_box.y2 = 400;
	 
	 room->proj_array[0].direction = left;
	 room->proj_array[0].proj_box.x1 = 576;
	 room->proj_array[0].proj_box.x2 = 608; /*608 */
	 room->proj_array[0].proj_box.y1 = 296;
	 room->proj_array[0].proj_box.y2 = 328; /*328 */
	 
	 room->proj_array[1].direction = right;
	 room->proj_array[1].proj_box.x1 = 64;
	 room->proj_array[1].proj_box.x2 = 96; /* 96*/
	 room->proj_array[1].proj_box.y1 = 264;
	 room->proj_array[1].proj_box.y2 = 296; /* 296*/
	 
	 room->proj_array[2].direction = left;
	 room->proj_array[2].proj_box.x1 = 576;
	 room->proj_array[2].proj_box.x2 = 608; /*608 */
	 room->proj_array[2].proj_box.y1 = 200;
	 room->proj_array[2].proj_box.y2 = 232; /*232 */
	 
	 room->proj_array[3].direction = right;
	 room->proj_array[3].proj_box.x1 = 64;
	 room->proj_array[3].proj_box.x2 = 96; /*96*/
	 room->proj_array[3].proj_box.y1 = 136;
	 room->proj_array[3].proj_box.y2 = 168; /*168 */
	 
	 room->proj_array[4].direction = left;
	 room->proj_array[4].proj_box.x1 = 576;
	 room->proj_array[4].proj_box.x2 = 608; /*608 */
	 room->proj_array[4].proj_box.y1 = 104;
	 room->proj_array[4].proj_box.y2 = 136; /*136 */
	 
	 
	 
}


void initialize_room2(Room *room) {
	 
	 room->up_bound.x1 = 0;
	 room->up_bound.x2 = 640;
	 room->up_bound.y1 = 0;
	 room->up_bound.y2 = 16;
	 
	 room->right_bound.x1 = 400;
	 room->right_bound.x2 = 640;
	 room->right_bound.y1 = 0;
	 room->right_bound.y2 = 400;
	 
	 room->left_bound.x1 = 0;
	 room->left_bound.x2 = 224;
	 room->left_bound.y1 = 0;
	 room->left_bound.y2 = 400;
	 
	 room->down_bound.x1 = 0;
	 room->down_bound.x2 = 640;
	 room->down_bound.y1 = 368;
	 room->down_bound.y2 = 400;
	 
	 room->door_array[0].locked = false;
	 room->door_array[0].door_box.x1 = 288;
	 room->door_array[0].door_box.x2 = 320;
	 room->door_array[0].door_box.y1 = 0;
	 room->door_array[0].door_box.y2 = 32; 
	 
	 room->door_array[1].locked = false;
	 room->door_array[1].door_box.x1 = 288;
	 room->door_array[1].door_box.x2 = 320;
	 room->door_array[1].door_box.y1 = 368;
	 room->door_array[1].door_box.y2 = 400;
	 

	 
	 
}

void initialize_room3(Room *room) {
	 
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
	 room->door_array[0].door_box.x1 = 320;
	 room->door_array[0].door_box.x2 = 356;
	 room->door_array[0].door_box.y1 = 0;
	 room->door_array[0].door_box.y2 = 48; 
	 room->door_array[0].door_ID = 3;

	 
	  
	 room->door_array[1].locked = false;
	 room->door_array[1].door_box.x1 = 592;
	 room->door_array[1].door_box.x2 = 640;
	 room->door_array[1].door_box.y1 = 184;
	 room->door_array[1].door_box.y2 = 216; 
	 
	 room->door_array[2].locked = false;
	 room->door_array[2].door_box.x1 = 288;
	 room->door_array[2].door_box.x2 = 320;
	 room->door_array[2].door_box.y1 = 352;
	 room->door_array[2].door_box.y2 = 400;
	 
	 room->door_array[3].locked = true;
	 room->door_array[3].rotate = true;
	 room->door_array[3].door_ID = 2;
	 room->door_array[3].door_box.x1 = 0;
	 room->door_array[3].door_box.x2 = 48;
	 room->door_array[3].door_box.y1 = 184;
	 room->door_array[3].door_box.y2 = 216; 

	room->actual_doors = 4;
	 
}

void initialize_room4(Room *room) {
	 
	 room->up_bound.x1 = 0;
	 room->up_bound.x2 = 640;
	 room->up_bound.y1 = 0;
	 room->up_bound.y2 = 16;
	 
	 room->right_bound.x1 = 600;
	 room->right_bound.x2 = 640;
	 room->right_bound.y1 = 0;
	 room->right_bound.y2 = 400;
	 
	 room->left_bound.x1 = 0;
	 room->left_bound.x2 = 24;
	 room->left_bound.y1 = 0;
	 room->left_bound.y2 = 400;
	 
	 room->down_bound.x1 = 0;
	 room->down_bound.x2 = 640;
	 room->down_bound.y1 = 360;
	 room->down_bound.y2 = 400;
	 
	  
	 room->door_array[0].locked = false;
	 room->door_array[0].door_box.x1 = 352;
	 room->door_array[0].door_box.x2 = 384;
	 room->door_array[0].door_box.y1 = 352;
	 room->door_array[0].door_box.y2 = 400;
	 
	 room->door_array[1].locked = false;
	 room->door_array[1].door_box.x1 = 288;
	 room->door_array[1].door_box.x2 = 320;
	 room->door_array[1].door_box.y1 = 352;
	 room->door_array[1].door_box.y2 = 400;
	 
	 room->door_array[2].locked = false;
	 room->door_array[2].door_box.x1 = 240;
	 room->door_array[2].door_box.x2 = 288;
	 room->door_array[2].door_box.y1 = 352;
	 room->door_array[2].door_box.y2 = 400; 


	 room->door_array[3].locked = false;
	 room->door_array[3].door_box.x1 = 0;
	 room->door_array[3].door_box.x2 = 48;
	 room->door_array[3].door_box.y1 = 200;
	 room->door_array[3].door_box.y2 = 232; 
	 
	  
	room->actual_doors = 4;
	 
}


void initialize_room5(Room *room) {
	 
	 room->up_bound.x1 = 0;
	 room->up_bound.x2 = 640;
	 room->up_bound.y1 = 0;
	 room->up_bound.y2 = 32;
	 
	 room->right_bound.x1 = 608;
	 room->right_bound.x2 = 640;
	 room->right_bound.y1 = 0;
	 room->right_bound.y2 = 400;
	 
	 room->left_bound.x1 = 0;
	 room->left_bound.x2 = 32;
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
	 room->door_array[0].door_box.y2 = 48;
	 
	 room->door_array[1].locked = false;
	 room->door_array[1].door_box.x1 = 352;
	 room->door_array[1].door_box.x2 = 384;
	 room->door_array[1].door_box.y1 = 352;
	 room->door_array[1].door_box.y2 = 400;
	 
	 room->door_array[2].locked = false;
	 room->door_array[2].door_box.x1 = 288;
	 room->door_array[2].door_box.x2 = 320;
	 room->door_array[2].door_box.y1 = 352;
	 room->door_array[2].door_box.y2 = 400;
	 
	 room->door_array[3].locked = false;
	 room->door_array[3].door_box.x1 = 240;
	 room->door_array[3].door_box.x2 = 288;
	 room->door_array[3].door_box.y1 = 352;
	 room->door_array[3].door_box.y2 = 400; 	 
	 
	  
	room->actual_doors = 4;
	 
}

void initialize_room6(Room *room) {
	 
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
	 room->door_array[0].door_box.y2 = 48;
	 
	 room->door_array[1].locked = false;
	 room->door_array[1].door_box.x1 = 592;
	 room->door_array[1].door_box.x2 = 640;
	 room->door_array[1].door_box.y1 = 200;
	 room->door_array[1].door_box.y2 = 232;
	 
	 room->door_array[2].locked = false;
	 room->door_array[2].door_box.x1 = 592;
	 room->door_array[2].door_box.x2 = 640;
	 room->door_array[2].door_box.y1 = 248;
	 room->door_array[2].door_box.y2 = 280;
		   
	room->actual_doors = 3;
	 
}

void initialize_room7(Room *room) {
	 
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
	 room->door_array[0].door_box.x1 = 16;
	 room->door_array[0].door_box.x2 = 48;
	 room->door_array[0].door_box.y1 = 216;
	 room->door_array[0].door_box.y2 = 248;
	 
	 room->item.on_stage = true;
	 room->item.item_ID = 2;
	 room->item.item_box.x1 = 352;
	 room->item.item_box.x2 = 384;
	 room->item.item_box.y1 = 320;
	 room->item.item_box.y2 = 352;

		   
	room->actual_doors = 1;
	 
}
void initialize_room8(Room *room) {
	 
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
	 room->door_array[0].door_box.x1 = 592;
	 room->door_array[0].door_box.x2 = 640;
	 room->door_array[0].door_box.y1 = 200;
	 room->door_array[0].door_box.y2 = 232; 
	 
	 room->door_array[1].locked = false;
	 room->door_array[1].door_box.x1 = 0;
	 room->door_array[1].door_box.x2 = 48;
	 room->door_array[1].door_box.y1 = 200;
	 room->door_array[1].door_box.y2 = 232;

	 room->proj_array[0].direction = down;
	 room->proj_array[0].proj_box.x1 = 512;
	 room->proj_array[0].proj_box.x2 = 544; /*608 */
	 room->proj_array[0].proj_box.y1 = 32;
	 room->proj_array[0].proj_box.y2 = 64; /*328 */
	 
	 room->proj_array[1].direction = up;
	 room->proj_array[1].proj_box.x1 = 400;
	 room->proj_array[1].proj_box.x2 = 432; /* 96*/
	 room->proj_array[1].proj_box.y1 = 336;
	 room->proj_array[1].proj_box.y2 = 368; /* 296*/
	 
	 room->proj_array[2].direction = down;
	 room->proj_array[2].proj_box.x1 = 288;
	 room->proj_array[2].proj_box.x2 = 320; /*608 */
	 room->proj_array[2].proj_box.y1 = 32;
	 room->proj_array[2].proj_box.y2 = 64; /*232 */
	 
	 room->proj_array[3].direction = up;
	 room->proj_array[3].proj_box.x1 = 176;
	 room->proj_array[3].proj_box.x2 = 208; /*96*/
	 room->proj_array[3].proj_box.y1 = 136;
	 room->proj_array[3].proj_box.y2 = 168; /*168 */
	 
	
	 room->proj_array[4].proj_box.x1 = 0;
	 room->proj_array[4].proj_box.x2 = 0; 
	 room->proj_array[4].proj_box.y1 = 0;
	 room->proj_array[4].proj_box.y2 = 0; 
	 
	 
}

void initialize_room9(Room *room) {
	 
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
	 room->door_array[0].door_box.x1 = 592;
	 room->door_array[0].door_box.x2 = 640;
	 room->door_array[0].door_box.y1 = 200;
	 room->door_array[0].door_box.y2 = 232; 
	 
	 room->item.on_stage = true;
	 room->item.item_ID = 3;
	 room->item.item_box.x1 = 352;
	 room->item.item_box.x2 = 384;
	 room->item.item_box.y1 = 320;
	 room->item.item_box.y2 = 352;
	 
}

void initialize_room10(Room *room) {
	 
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
	 room->door_array[0].door_box.x1 = 192;
	 room->door_array[0].door_box.x2 = 224;
	 room->door_array[0].door_box.y1 = 16;
	 room->door_array[0].door_box.y2 = 48; 
	 
	 room->door_array[1].locked = false;
	 room->door_array[1].door_box.x1 = 288;
	 room->door_array[1].door_box.x2 = 320;
	 room->door_array[1].door_box.y1 = 16;
	 room->door_array[1].door_box.y2 = 48; 

	  
	 room->door_array[2].locked = false;
	 room->door_array[2].door_box.x1 = 384;
	 room->door_array[2].door_box.x2 = 416;
	 room->door_array[2].door_box.y1 = 16;
	 room->door_array[2].door_box.y2 = 48;
	 
	 room->door_array[3].locked = false;
	 room->door_array[3].door_box.x1 = 288;
	 room->door_array[3].door_box.x2 = 320;
	 room->door_array[3].door_box.y1 = 368;
	 room->door_array[3].door_box.y2 = 400;
	 
	
	 
}

void initialize_room11(Room *room) {
	 
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
	 room->door_array[0].door_box.x1 = 320;
	 room->door_array[0].door_box.x2 = 352;
	 room->door_array[0].door_box.y1 = 352;
	 room->door_array[0].door_box.y2 = 400; 
}


void initialize_array(Model *model){
	
	initialize_room0(&(model->room_array[0]));
	initialize_room1(&(model->room_array[1]));
	initialize_room2(&(model->room_array[2]));
	initialize_room3(&(model->room_array[3]));
	initialize_room4(&(model->room_array[4]));
	initialize_room5(&(model->room_array[5]));
	initialize_room6(&(model->room_array[6]));
	initialize_room7(&(model->room_array[7]));
	initialize_room8(&(model->room_array[8]));
	initialize_room9(&(model->room_array[9]));
	initialize_room10(&(model->room_array[10]));
	initialize_room11(&(model->room_array[11]));







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
		if (((player->y >= bound->y1) && (player->y <= bound->y2)) || ((player->y + 16 >= bound->y1) && (player->y + 16 <= bound->y2)) ) {
			return true;
		} 
	} else if ((player->x + 16 >= bound->x1) && (player->x + 16 <= bound->x2)) {
		if (((player->y >= bound->y1) && (player->y <= bound->y2)) || ((player->y + 16 >= bound->y1) && (player->y + 16 <= bound->y2)) ) {
			return true;
		}
	}
		return false;
	


}


void update_heldslot (Player *player, Item *item) {
	
	player->heldslot_ID = item->item_ID;
}





