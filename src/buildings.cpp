#include <iostream>
#include <array>
#include "buildings.h"


Buildings::Buildings(){
	cout << WIDTH << 'x' << HEIGHT << endl;
	srand(time(0));

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
	if(builds[0][0] < -builds[0][2]){
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

	// for(const auto& build : old_builds){
	// 	if(build[0] > WIDTH)
	// 		continue;
	
	// 	for(int i=HEIGHT-2; i> HEIGHT-build[1]-2; i--){ // render side walls
	// 		if(build[0] < WIDTH && build[0] > 0){
	// 			move( i, build[0]);
	// 			printw(" ");	
	// 		}
	// 		if(build[0]+build[2] < WIDTH && build[0]+build[2] > 0){
	// 			move( i, build[0]+build[2]);
	// 			printw(" ");	
	// 		}
	// 	}

	// 	for(int i=build[0]; i<build[0]+build[2]+1;i++){ // rendering roof
	// 		if(i < 0 || i > WIDTH-1)
	// 			continue;
	// 		move(HEIGHT-build[1]-2, i);
	// 		printw(" ");
	// 	}		
	// }

	for(const auto& build : builds){
		if(build[0] > WIDTH)
			continue;
	
		for(int i=HEIGHT-2; i> HEIGHT-build[1]-2; i--){ // render side walls
			if(build[0] < WIDTH && build[0] > 0){
				move( i, build[0]);
				printw("o");	
			}
			if(build[0]+build[2] < WIDTH && build[0]+build[2] > 0){
				move( i, build[0]+build[2]);
				printw("o");	
			}
		}

		for(int i=build[0]; i<build[0]+build[2]+1;i++){ // rendering roof
			if(i < 0 || i > WIDTH-1)
				continue;
			move(HEIGHT-build[1]-2, i);
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