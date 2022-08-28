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

void Bird::runPhysics(){
	prev_pos[0] = pos[0];
	prev_pos[1] = pos[1];
	
	pos[0] += 1;

	if(jump){
		jump=false;
		pos[0]-=3;
	}

	if(pos[0] >= HEIGHT-1) //hit floor
		pos[0] = 0;
	else if(pos[0] <= 1)
		pos[0] = 1;
}

void Bird::inputHandler(int key){
	if(key==32)
		jump=true;
	// move(5,3);
	// printw("%d  ", key);
}