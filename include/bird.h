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

public:

	void renderBird() const;
	void runPhysics();

};