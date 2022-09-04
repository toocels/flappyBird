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

void Bird::reset(){
	pos[0] = 6;
	pos[1] = 8;
	prev_pos[0] = 6;
	prev_pos[1] = 8;
	jump=false;
	score = 0;
}

void Bird::runPhysics(){
	prev_pos[0] = pos[0];
	prev_pos[1] = pos[1];
	
	pos[0] += 0.3;

	if(jump){
		jump=false;
		pos[0]-=3;
	}

	if(pos[0] >= HEIGHT-1) //hitting floor
		pos[0] = 0;
	else if(pos[0] <= 1)
		pos[0] = 1;
}

bool Bird::checkCollision(Buildings &buildings){
	for(int build=0; build<5; build++)
		if(pos[1] > buildings.getBuilds(build,0) && pos[1] < buildings.getBuilds(build,0)+buildings.getBuilds(build,2))
			if(pos[0] > HEIGHT-buildings.getBuilds(build,1)-4)
				return true;

	for(int build=0; build<5; build++){
		if(pos[0] == buildings.getBuilds(build,0)+buildings.getBuilds(build,2)){
			score+=1;
			// system("echo -en \"\\007\"");
		}
	}

	return false;
}

void Bird::inputHandler(int key){
	if(key==32)
		jump=true;
}

int Bird::getScore(){
	return score;
}