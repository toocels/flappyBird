#include <iostream>

#include "bird.h"

void Bird::renderBird() const{
	move(prev_pos[0], prev_pos[1]);
	printw("   ");
	move(prev_pos[0]+1, prev_pos[1]);
	printw("  ");

	move(pos[0], pos[1]);
	printw("\\O>");
	move(pos[0]+1, pos[1]);
	printw("^^");
}

bool Bird::runPhysics(std::array<std::array<int, 3> ,5> builds){
	prev_pos[0] = pos[0];
	prev_pos[1] = pos[1];
	
	pos[0] += 1;

	if(jump){
		jump=false;
		pos[0]-=3;
		// system("echo -en \"\\007\"");
	}

	for(auto build:builds){
		if(pos[1] > build[0] && pos[1] < build[0]+build[2]){
			if(pos[0] > HEIGHT-build[1]-4){
				move(5,10);
				printw("Collide");
				return true;
			}
		}
		else{
			move(5,10);
			printw("No Collide");
		}
	}

	if(pos[0] >= HEIGHT-1) //hitting floor
		pos[0] = 0;
	else if(pos[0] <= 1)
		pos[0] = 1;

	return false;
}

void Bird::inputHandler(int key){
	if(key==32)
		jump=true;
}