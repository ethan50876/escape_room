#include "event.h"


/* 
Params: a Player struct, a Room struc, an unsigned long 
Returns: none
Purpose: Provides a switch-case method for the calls of the move_player function from the model.c file.

*/
void player_movement(Player *player, Room *room, unsigned long key_press) {
	switch (key_press) {
		
        case LEFT_KEY:
        move_player(player, room, left);
		break;
        case RIGHT_KEY:
        move_player(player, room, right);
		break;
        case UP_KEY:
        move_player(player, room, up);
		break;
        case DOWN_KEY:
        move_player(player, room, down);
		break;
        default:
        break;
    }
	
}
/* 
Params: a Player struct, a Door struct
Return: a bool (typedef int - 0 representing false and 1 representing true)
Purpose: uses the collided() function from model.c to check for collision with a door
and allowing the player to switch the next respective room
*/
bool switch_room(Player *player, Door *door) {
	
	
	if ((collided(player, &door->door_box) == true)) {
		return true;
	} else {
		return false;
	}
	
	/*return (collided(player, door->door_box));*/

		
}

bool unlock_door(Player *player, Door *door) {
	
	if (player->heldslot_ID == door->door_ID) {
		return true;
	} else {
		return false;
	}
}
/*
TO-DO 3/24

initialize item, IDs, actual_door, etc
check for pointer errors in unlock_door, interact, update_heldslot
change the game loop to render doors depending on locked status 
change the game loop to render items depending on the on_stage status

*/
void interact(Player *player, Room *room, unsigned long key_press) {
	switch (key_press) {
		
		case SPACE_KEY:
		if ((room->item.on_stage == true) && (collided(player, &room->item.item_box))) {
			room->item.on_stage = false; /*add check for on_stage in escape.c*/
			update_heldslot(player, &room->item);			
		} else {
			int counter = 0;
			while (counter < (room->actual_doors)) {
				if ((room->door_array[counter].locked == true) && (collided(player, &room->door_array[counter].door_box) == true) 
					&& (unlock_door(player, &room->door_array[counter]) == true) ) {		
					room->door_array[counter].locked = false;
					player->heldslot_ID = 0;
				}
				counter ++;
			}
		}
		
		break;
		default:
		break;
	}
	
}

bool has_user_input() {
	
	return Cconis();

	
}

unsigned long get_user_input() {
	
	return Cnecin() >> 16;
	
}
