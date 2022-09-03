#pragma once

/*
\◯▷
╚╝

\O>
^^
*/

class Bird{ 
private:
	int pos[2] = {6,8};
	int prev_pos[2] = {6,8};
	bool jump=false;
	int score = 0;

public:
	void renderBird() const;
	void runPhysics();
	bool checkCollision(std::array<std::array<int, 3> ,5> builds);
	void inputHandler(int key);
	int getScore();
	void reset();
};