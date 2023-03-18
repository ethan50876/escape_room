#include "escape.h"
#include <osbind.h>

int curr_room = 0;


void async_events(Model* model, UINT32* base) {
		
	unsigned long input;
	int i;
	
	/*need counter for current room*/

	while(has_user_input()) { 
	  
		
		input = get_user_input();	
    
		player_movement(&model->player, &model->room_array[curr_room], input);
		
	
		if(switch_room(&model->player, &model->room_array[curr_room].door_array[0]) && (curr_room == 0)) {
			set_player(&model->player, 320, 336);
			curr_room++;
		} else if((curr_room == 1) && (switch_room(&model->player, &model->room_array[curr_room].door_array[1]))){
			set_player(&model->player, 320,96);
			curr_room--;
		}
		render_player(base, &model->player);
	
	}
	
	


			
}



void game_loop() {
	
	
	
	Model model;
	UINT32 *base = Physbase();
	initialize_game(&model);
	render_room1(base, &model);
	


	while(1) {

	async_events(&model, base);	
	render_curr_room(base, &model, curr_room); 	
	}

	
}



