#include "escape.h"
#include <osbind.h>
#include <stdio.h>
#include <string.h>

int curr_room = 0;
const UINT32 buffer[32256]; /*Second Screen for double buffering */
const UINT32 buffer3[33000]; /*3rd buffer*/
bool room_changed = false;
int door_counter;
int actual_counter;

void async_events(Model* model, UINT32* screen1) {
		
	unsigned long input;
	int i;
	

	while(has_user_input()) { 
	  
		
		input = get_user_input();	
    
		player_movement(&model->player, &model->room_array[curr_room], input);
		interact(&model->player, &model->room_array[curr_room], input);
	
		if(switch_room(&model->player, &model->room_array[curr_room].door_array[0]) && (curr_room == 0) && (model->room_array[curr_room].door_array[0].locked == false)) {
			set_player(&model->player, 320, 336);
			curr_room++;
			room_changed = true;
			
		} else if((curr_room == 1) && (switch_room(&model->player, &model->room_array[curr_room].door_array[1])) && (model->room_array[curr_room].door_array[1].locked == false)){
			set_player(&model->player, 320,96);
			curr_room--;
			room_changed = true;
		}
		render_player(screen1, &model->player);
	
	}
	
	


			
}

UINT8 *get_screen1(UINT8 *buffer) {
  UINT8 *screen1;
  UINT16 difference;
  screen1 = buffer;
  difference = (int) screen1;
  difference %= 0x100;
  difference = 0x100 - difference;
  return screen1 + difference;
}

long get_time() {

    long* timer = (long*) SYSTEM_CLOCK;  
    long oldSSP = Super(0);
	long curr_time = *timer;

    Super(oldSSP);

    return curr_time;

}


void game_loop() {
	/*changes
		screen1 -> screen1
		screen2 -> screen2
		curr_screen -> curr_screen
		
	*/
	
	unsigned long prev_time, curr_time, time_elapsed;
	bool swap_buffer = false;
	Model model;
	UINT32 *screen1 = Physbase();
	UINT32 *screen2 = (UINT32*) get_screen1((UINT8*)buffer);
	
	UINT32 *screen3 = (UINT32*) get_screen1((UINT8*)buffer3);
	
	UINT32 *curr_screen = screen1;
	
	initialize_game(&model);

	render_curr_room(screen3, &model, curr_room);
	memcpy((void*) curr_screen, screen3, 32000);


	while(1) {


	async_events(&model, curr_screen);
	
	curr_time = get_time();
	time_elapsed = curr_time - prev_time;
	if (time_elapsed > 0) {
		
		if (room_changed) {
			
		render_curr_room(screen3, &model, curr_room);

			room_changed = false;
		}
            if (swap_buffer){
                curr_screen = screen1;
            } else {
                curr_screen = screen2;						
            }
			
			prev_time = curr_time;
			/*sync_events such as proj*/
	
			

			memcpy((void*) curr_screen, screen3, 32000);
			render_player(curr_screen, &model.player);	
			door_counter = 0;
			actual_counter = model.room_array[curr_room].actual_doors;
			while (door_counter < actual_counter) {
				if (model.room_array[curr_room].door_array[door_counter].locked == true) {
					/*TO-DO + unrender some stuff in render_curr_room*/
					render_door(curr_screen, &model.room_array[curr_room].door_array[door_counter]);
				}
				door_counter ++;
			} 
			if (model.room_array[curr_room].item.on_stage == true) {
				render_item(curr_screen, &model.room_array[curr_room].item);
			}
			render_heldslot(curr_screen, &model.player);
			
			swap_buffer = !swap_buffer;			
			Setscreen(-1, curr_screen, -1);

			
            Vsync();
          
		}

		
	}
	
	
	
}

	




