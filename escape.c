#include "escape.h"
#include <osbind.h>



void async_events(Model* model, UINT32* base) {
	
  unsigned long input;
  if (has_user_input()) {
	  
    input = get_user_input();
	
    
    player_movement(&model->player, input);
	
    
  }
	render_player_r1(base, &model->player);
	
	
	/*
	
	printf("x is  ");
	printf(&model->player->x);
	printf('\n');
	printf("y is ");
	printf(&model->player->y);
	
	*/
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



