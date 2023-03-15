#include "event.h"



void player_movement(Player *player, unsigned long key_press) {
	if (key_press == LEFT_KEY) 
		move_player(player, left);
	else if (key_press == RIGHT_KEY)
		move_player(player, right);
	else if (key_press == UP_KEY)
		move_player(player, up);
	else if (key_press == DOWN_KEY)
		move_player(player, down);
	
}

bool has_user_input() {
	
	return Cconis();
	
}

unsigned long get_user_input() {
	
	return Cnecin() >> 16;
	
}