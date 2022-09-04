#pragma once

/*
\◯▷
╚╝

\O>
^^
*/

class Bird{ 
private:
	float pos[2] = {6,8};
	float prev_pos[2] = {6,8};
	bool jump=false;
	int score = 0;

public:
	void renderBird() const;
	void runPhysics();
	bool checkCollision(Buildings &buildings);
	void inputHandler(int key);
	int getScore();
	void reset();
};