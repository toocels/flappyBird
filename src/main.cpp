#include <iostream>
#include <unistd.h>
#include <chrono>
#include <ncurses.h>

#define WIDTH 80
#define HEIGHT 24
#define FPS 30

using std::cout, std::endl, std::cin;

#include "buildings.cpp"
#include "bird.cpp"

auto time_now = []{return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();};
auto sleep_ms = [](int ms){usleep(ms*1000);};

int main(){
	
	Buildings buildings{};
	Bird bird{};

	initscr();  // init screen
	noecho();   // no echo keyboard
	timeout(5); // ms wait for keyboard

	bool gameRunning = true;
	unsigned int fps=0;
	unsigned long int start = time_now();  //start of frame in epoch ms
	unsigned long int prev_frame = time_now();

	while (gameRunning) {
		// Keyboard input
		int ch = getch();
		if (ch != ERR) {
			flushinp();
			if(ch == 27)
				gameRunning = false;

			// move(5,5);
			// printw("%d",ch);

			// clrtoeol(); // add keypress back to input queue
			bird.inputHandler(ch);
		}

		// Calculation stuff
		if(time_now() - prev_frame > 50){
			prev_frame = time_now();
			buildings.moveBuildings();
	
			if(bird.checkCollision(buildings)){
				move(5,10);
				printw("Press q to continue.");
				move(6,10);
				printw("Press p to quit.");
				while(true){
					int ch = getch();
					flushinp();
					if(ch == 113){
						buildings.reset();
						bird.reset();
						clear();
						break;
					}
					else if(ch == 112 || ch == 27){
						gameRunning = false;
						clear();
						break;
					}
				}
			}
			bird.runPhysics();
	
			move(3,2);
			printw("Score: %i ", bird.getScore());
		}

		// Rendering stuff
	   	buildings.drawBorders();
	   	buildings.renderBuildings();
	   	bird.renderBird();
	   	
		move(0,0);
		printw("FPS: %d ", fps);

		refresh();
		// clear();

		// Fps stuff
		sleep_ms(33);
		fps=1000/(time_now()-start+1);
		start = time_now();
	}

	clear();
	move(5,30);
	printw(":Game Over:");
	refresh();
	sleep_ms(1000);

	endwin();

	cout << "Game over, your score: " << bird.getScore() << endl;

	return 0;
}

/*
classes-> screen, buildings, bird(intelligence)


	cout << "\x1B[5;5H at place \x1B[m";
	
	cout << "\x1B[m  empty \x1B[m" << endl;
	cout << "\x1B[31;107m   dfs  \x1B[m" << endl;
	cout << "\x1B[64m  HELLO! \x1B[m" << endl;

	for(int i=0;i<108;i++){
		cout << "\x1B[" << i << "m" << "Text " << i << "\x1B[m" << endl;
	}
*/