#include "escape.h"
#include <osbind.h>
#include <stdio.h>
#include <string.h>
#include "rooms.h"

int curr_room = 0;
const UINT32 buffer[32256]; /*Second Screen for double buffering */
const UINT32 buffer3[33000]; /*3rd buffer*/
bool room_changed = false;
int door_counter;
int actual_counter;
int game_time = 0;
int game_seconds;
bool game_running = true;





void on_switch_room(Model *model) {
	
	
	switch (curr_room) {
		
		case 0: 
	
		if (switch_room(&model->player, &model->room_array[curr_room].door_array[0]) && (model->room_array[curr_room].door_array[0].locked == false)) {
			set_player(&model->player, 320, 336);
			curr_room = 1;
			room_changed = true;
		}
		break;
		
		case 1:
		if ((switch_room(&model->player, &model->room_array[curr_room].door_array[1])) && (model->room_array[curr_room].door_array[1].locked == false)) {
			set_player(&model->player, 288, 64);
			curr_room = 0;
			room_changed = true;
		} else if (switch_room(&model->player, &model->room_array[curr_room].door_array[0]) && (model->room_array[curr_room].door_array[0].locked == false)) {
			set_player(&model->player, 320, 336);
			curr_room = 2;
			room_changed = true;
		}
		break;
		
		case 2:
		if ((switch_room(&model->player, &model->room_array[curr_room].door_array[1])) && (model->room_array[curr_room].door_array[1].locked == false)) {
			set_player(&model->player, 288, 64);
			curr_room = 1;
			room_changed = true;
		} else if (switch_room(&model->player, &model->room_array[curr_room].door_array[0]) && (model->room_array[curr_room].door_array[0].locked == false)) {
			set_player(&model->player, 320, 336);
			curr_room = 3;
			room_changed = true;
		}
		break;
		
		case 3:
		if ((switch_room(&model->player, &model->room_array[curr_room].door_array[0])) && (model->room_array[curr_room].door_array[0].locked == false)) {
			set_player(&model->player, 320, 336);
			curr_room = 10; /* to-do - connecting to trap door room 2*/
			room_changed = true;
		} else if (switch_room(&model->player, &model->room_array[curr_room].door_array[1]) && (model->room_array[curr_room].door_array[1].locked == false)) {
			set_player(&model->player, 64, 200);
			curr_room = 4;
			room_changed = true;
		} else if (switch_room(&model->player, &model->room_array[curr_room].door_array[2]) && (model->room_array[curr_room].door_array[2].locked == false)) {
			set_player(&model->player, 288, 64);
			curr_room = 2;
			room_changed = true;
		} else if (switch_room(&model->player, &model->room_array[curr_room].door_array[3]) && (model->room_array[curr_room].door_array[3].locked == false)) {
			set_player(&model->player, 576, 200);
			curr_room = 8; /*to-do - connecting to proj2 room */
			room_changed = true;
		}
		break;
		
		
		case 4:
		if ((switch_room(&model->player, &model->room_array[curr_room].door_array[0])) && (model->room_array[curr_room].door_array[0].locked == false)) {
			set_player(&model->player, 288, 64);
			curr_room = 5; 
			room_changed = true;
		} else if (switch_room(&model->player, &model->room_array[curr_room].door_array[1]) && (model->room_array[curr_room].door_array[1].locked == false)) {
			set_player(&model->player, 64, 200);
		
		} else if (switch_room(&model->player, &model->room_array[curr_room].door_array[2]) && (model->room_array[curr_room].door_array[2].locked == false)) {
			set_player(&model->player, 64, 200);
			
		} else if (switch_room(&model->player, &model->room_array[curr_room].door_array[3]) && (model->room_array[curr_room].door_array[3].locked == false)) {
			set_player(&model->player, 576, 200);
			curr_room = 3; 
			room_changed = true;
		
		}
		break;

		case 5:
		if ((switch_room(&model->player, &model->room_array[curr_room].door_array[0])) && (model->room_array[curr_room].door_array[0].locked == false)) {
			set_player(&model->player, 64 , 200);
			curr_room = 4; 
			room_changed = true;
		} else if (switch_room(&model->player, &model->room_array[curr_room].door_array[1]) && (model->room_array[curr_room].door_array[1].locked == false)) {
			set_player(&model->player, 64, 200);
			curr_room = 4;
			room_changed = true;
		
		} else if (switch_room(&model->player, &model->room_array[curr_room].door_array[2]) && (model->room_array[curr_room].door_array[2].locked == false)) {
			set_player(&model->player, 288, 64);
			curr_room = 6; 
			room_changed = true;	
		} else if (switch_room(&model->player, &model->room_array[curr_room].door_array[3]) && (model->room_array[curr_room].door_array[3].locked == false)) {	
			set_player(&model->player, 64, 200);
			curr_room = 4;
			room_changed = true;
		
		}
		break;
		
		case 6:
		if ((switch_room(&model->player, &model->room_array[curr_room].door_array[0])) && (model->room_array[curr_room].door_array[0].locked == false)) {
			set_player(&model->player, 64 , 200);
			curr_room = 4; 
			room_changed = true;
		} else if (switch_room(&model->player, &model->room_array[curr_room].door_array[1]) && (model->room_array[curr_room].door_array[1].locked == false)) {
			set_player(&model->player, 64, 200);
			curr_room = 4;
			room_changed = true;
		
		} else if (switch_room(&model->player, &model->room_array[curr_room].door_array[2]) && (model->room_array[curr_room].door_array[2].locked == false)) {
			set_player(&model->player, 64, 200);
			curr_room = 7; 
			room_changed = true;	
		} 
		break;
		
		case 7:
		if ((switch_room(&model->player, &model->room_array[curr_room].door_array[0])) && (model->room_array[curr_room].door_array[0].locked == false)) {
			set_player(&model->player, 64 , 200);
			curr_room = 4; 
			room_changed = true;
		} 
		break;
		
		case 8:
		if ((switch_room(&model->player, &model->room_array[curr_room].door_array[0])) && (model->room_array[curr_room].door_array[0].locked == false)) {
			set_player(&model->player, 64 , 200);
			curr_room = 3; 
			room_changed = true;
		} else if (switch_room(&model->player, &model->room_array[curr_room].door_array[1]) && (model->room_array[curr_room].door_array[1].locked == false)) {
			set_player(&model->player, 576 , 200);
			curr_room = 9;
			room_changed = true;
		
		}
		break;
		
		case 9:
		if ((switch_room(&model->player, &model->room_array[curr_room].door_array[0])) && (model->room_array[curr_room].door_array[0].locked == false)) {
			set_player(&model->player, 64 , 200);
			curr_room = 8; 
			room_changed = true;
		} 
		break;
		
		
		case 10:
		if ((switch_room(&model->player, &model->room_array[curr_room].door_array[0])) && (model->room_array[curr_room].door_array[0].locked == false)) {
			set_player(&model->player, 320, 336);
			
		} else if (switch_room(&model->player, &model->room_array[curr_room].door_array[1]) && (model->room_array[curr_room].door_array[1].locked == false)) {
			set_player(&model->player, 320, 336);
			
		
		} else if (switch_room(&model->player, &model->room_array[curr_room].door_array[2]) && (model->room_array[curr_room].door_array[2].locked == false)) {
			set_player(&model->player, 320, 336);
			curr_room = 11; 
			room_changed = true;	
		} else if (switch_room(&model->player, &model->room_array[curr_room].door_array[3]) && (model->room_array[curr_room].door_array[3].locked == false)) {	
			set_player(&model->player, 320, 64);
			curr_room = 3;
			room_changed = true;
		
		}
		break;
		
		case 11:
		if ((switch_room(&model->player, &model->room_array[curr_room].door_array[0])) && (model->room_array[curr_room].door_array[0].locked == false)) {
			set_player(&model->player, 320 , 64);
			curr_room = 10; 
			room_changed = true;
		} 
		break;
		
		
		default:
		break;
	}
	
}
	

void async_events(Model *model, UINT32 *base) {
		
	unsigned long input;
	int i;
	

	while(has_user_input()) { 
	  
		
		input = get_user_input();	
    
		on_esc(input, &game_running);
		player_movement(&model->player, &model->room_array[curr_room], input);
		interact(&model->player, &model->room_array[curr_room], input);
		on_switch_room(model);
/*	
		if(switch_room(&model->player, &model->room_array[curr_room].door_array[0]) && (curr_room == 0) && (model->room_array[curr_room].door_array[0].locked == false)) {
			set_player(&model->player, 320, 336);
			curr_room++;
			room_changed = true;
		
			
		} else if((curr_room == 1) && (switch_room(&model->player, &model->room_array[curr_room].door_array[1])) && (model->room_array[curr_room].door_array[1].locked == false)){
			set_player(&model->player, 320,96);
			curr_room--;
			room_changed = true;
			
		} */

		render_player(base, &model->player);
	
	}
	
	


			
}

void sync_events(Model *model, UINT32 *base) {
	
	on_proj_vmove(&model->room_array[curr_room], base, curr_room);
	on_proj_move(&model->room_array[curr_room], base, curr_room);
	/*on_proj_hit(&model->player, &model->room_array[curr_room], &game_running);*/
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

	while(game_running == true) {


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
			sync_events(&model, curr_screen);
		
				

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
			render_projectiles(curr_screen, &model.room_array[curr_room]);
	
				
			swap_buffer = !swap_buffer;			
			Setscreen(-1, curr_screen, -1);
			
			
            Vsync();
			game_time ++;
			game_seconds = game_time / 70;
			
		}

		
	}
	
	
	
}





