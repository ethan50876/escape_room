#include "event.h"


/* 
Params:
Returns:
Purpose:

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
/* docu */
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