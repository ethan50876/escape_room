#include "escape.h"
#include <osbind.h>



void async_events(Model* model, UINT32* base) {
		
	unsigned long input;

	if (has_user_input()) { 
	  
		printf("hi");
		input = get_user_input();	
    
		player_movement(&model->player, &model->room_array[0], input);

	}
	render_player_r1(base, &model->player);

	

}



void game_loop() {
	
	
	
	Model model;
	UINT32 *base = Physbase();
	initialize_game(&model);


	while(1) {
	render_room1(base, &model);
	async_events(&model, base);
	}

	
}



