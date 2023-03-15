#include "event.h"



void player_movement(Player *player, unsigned long key_press) {
	switch (key_press) {
		
        case LEFT_KEY:
        move_player(player, left);
		break;
        case RIGHT_KEY:
        move_player(player, right);
		break;
        case UP_KEY:
        move_player(player,up);
		break;
        case DOWN_KEY:
        move_player(player, down);
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