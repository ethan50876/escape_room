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
Purpose: uses the collided() function fom model.c to check for collision with a door
and allowing the player to switch the next respective room
*/
bool switch_room(Player *player, Door *door) {
	
	if ((collided(player, &door->door_box) == true)) {
		return true;
	} else {
		return false;
	}
	
		
}

/*void interact(Player player, etc) */

bool has_user_input() {
	
	return Cconis();

	
}

unsigned long get_user_input() {
	
	return Cnecin() >> 16;
	
}
