#pragma once

/*
building stored as, bottom left part position, height
max, 5 buildings
*/

class Buildings{
private:
	std::array<std::array<int, 3> ,5> builds = {{0,0}}; // pos, height, width

public:
	Buildings();
	~Buildings();
	
	void listBuildings() const;
	void moveBuildings();
	void renderBuildings() const;

	static void drawBorders();
};