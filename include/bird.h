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

	void renderBird() const;
	bool runPhysics(std::array<std::array<int, 3> ,5>);
	void inputHandler(int key);

};