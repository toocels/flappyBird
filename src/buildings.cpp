#include <iostream>
#include <array>
#include "buildings.h"



Buildings::Buildings(){
	cout << WIDTH << 'x' << HEIGHT << endl;
	srand(time(0));
	// cout << rand()%6 << endl;

	builds[0][0] = 0;
	builds[1][0] = 16;
	builds[2][0] = 32;
	builds[3][0] = 48;
	builds[4][0] = 56;
}

Buildings::~Buildings(){}

void Buildings::listBuildings() const {
	for(auto build : builds)
		cout << "At:" << build[0] << "  Height:" << build[1] << endl;
}

void Buildings::moveBuildings(){
	// check if need to gen new building
	if(builds[0][0] < 0){
		for(int i=0;i<4;i++){
			builds[i] = builds[i+1];
		}
		builds[4] = {builds[3][0]+builds[3][2]+10+rand()%11,3+rand()%8,3+rand()%8};
	}

	for(auto& build : builds){
		build[0] = build[0]-1;
	}
}

void Buildings::renderBuildings(){
	for(int i=0;i<builds.size();i++){
		move(3,2+i*5);
		printw("   ");
		printw("%d",builds[i][0]);

		move(4,2+i*5);
		printw("   ");
		printw("%d",builds[i][1]);

		move(5,2+i*5);
		printw("   ");
		printw("%d",builds[i][2]);
	}

	for(auto build : old_builds){
		int pos= build[0]; 
		int height = build[1];
		int width = build[2];
	
		for(int i=HEIGHT-2; i> -(height-HEIGHT+2); i--){ // render side walls
			move( i, pos);
			printw(" ");
			move( i, pos+width);
			printw(" ");
		}

		for(int i=pos; i<pos+width+1;i++){ // rendering roof
			move(-(height-HEIGHT+2), i);
			printw(" ");
		}		
	}

	for(auto build : builds){
		int pos = build[0]; 
		int height = build[1];
		int width = build[2];

		if(pos < 0 || pos > WIDTH)
			continue;
	
		for(int i=HEIGHT-2; i> -(height-HEIGHT+2); i--){ // render side walls
			move( i, pos);
			printw("o");
			move( i, pos+width);
			printw("o");
		}

		for(int i=pos+1; i<pos+width;i++){ // rendering roof
			move(-(height-HEIGHT+2), i);
			printw("o");
		}		
	}

	old_builds = builds;
}

void Buildings::drawBorders(){
    for(int h=0; h < HEIGHT; h++){
		move(h,0);
		printw("H");
		move(h,WIDTH-1);
		printw("H");
    }
    for(int w=0; w < WIDTH; w++){
		move(0, w);
		printw("I");
		move(HEIGHT-1, w);
		printw("I");
    }
}