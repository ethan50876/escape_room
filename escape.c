#include "escape.h"
#include <osbind.h>

int curr_room = 0;
const UINT32 buffer[32256]; /*Second Screen for double buffering */

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

UINT8 *get_base(UINT8 *buffer) {
  UINT8 *base;
  UINT16 difference;
  base = buffer;
  difference = (int) base;
  difference %= 0x100;
  difference = 0x100 - difference;
  return base + difference;
}

long get_time() {

    long* timer = (long*) SYSTEM_CLOCK;  
    long oldSSP = Super(0);
	long curr_time = *timer;

    Super(oldSSP);

    return curr_time;

}


void game_loop() {
	
	
	unsigned long prev_time, curr_time, time_elapsed;
	bool swap_buffer = false;
	Model model;
	UINT32 *base = Physbase();
	UINT32 *buffer2 = (UINT32*) get_base((UINT8*)buffer);
	UINT32 *curr_base = base;
	initialize_game(&model);
	render_room1(base, &model);
	render_curr_room(buffer2, &model, curr_room);
	


	while(1) {

	async_events(&model, base);	
	curr_time = get_time();
	time_elapsed = curr_time - prev_time;
	if (time_elapsed > 0) {
            if (swap_buffer){
                curr_base = base;
            } else {
                curr_base = buffer2;			
            }
			
			prev_time = curr_time;
			/*sync_events such as proj*/
	
			render_curr_room(curr_base, &model, curr_room);
			render_player(curr_base, &model.player);			
			
			Setscreen(-1, curr_base, -1);

            Vsync();
            swap_buffer = !swap_buffer;
		}
		
	}
	
	
	
}

	




