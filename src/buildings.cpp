#include <iostream>
#include <array>
#include "buildings.h"



Buildings::Buildings(){
	cout << WIDTH << 'x' << HEIGHT << endl;
}

Buildings::~Buildings(){}

void Buildings::listBuildings() const {
	for(auto build : builds)
		cout << "At:" << build[0] << "  Height:" << build[1] << endl;
}

void Buildings::moveBuildings(){
	builds[0][0] = 50;
	builds[0][1] = 7;
	builds[0][2] = 4;
}

void Buildings::renderBuildings() const{
	for(auto build : builds){
		int pos= build[0]; 
		int height = build[1];
		int width = build[2];
	
		for(int i=HEIGHT-2; i> -(height-HEIGHT+2); i--){ // render side walls
			move( i, pos);
			printw("o");
			move( i, pos+width);
			printw("o");
		}

		for(int i=pos; i<pos+width+1;i++){
			move(-(height-HEIGHT+2), i);
			printw("o");
		}		
	}
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