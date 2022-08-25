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

void Buildings::moveBuildings(){}

void Buildings::renderBuildings(){}

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