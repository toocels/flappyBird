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

public:
	int score = 0;

	void renderBird() const;
	void runPhysics();
	bool checkCollision(std::array<std::array<int, 3> ,5> builds);
	void inputHandler(int key);

};