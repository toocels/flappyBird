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
	pos[0] += 1;

	if(pos[0] >= HEIGHT)
		pos[0] = 0;
}

void Bird::inputHandler(int key){
	prev_pos[0] = pos[0];
	prev_pos[1] = pos[1];

	if(key==32)
		pos[0]-=3;
	// move(5,3);
	// printw("%d  ", key);
}