#include "event.h"



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

bool has_user_input() {
	
	return (bool) (Cconis());

	
}

unsigned long get_user_input() {
	
	return Cnecin() >> 16;
	
}