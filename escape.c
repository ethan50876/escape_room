#include "escape.h"


void async_events(Model* model) {
	
  unsigned long input;
  if (has_user_input()) {
	  
    input = get_user_input();
	
    
    player_movement(&model->player, input);
    
  }
}



void game_loop() {
	
	Model *model;
	UINT32 *base;
	
	render_room1(base, model);
	
	async_events(model);
	
	
	
}



