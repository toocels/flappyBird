#pragma once

/*
building stored as, bottom left part position, height
max, 5 buildings
*/

class Buildings{
private:
	std::array<std::array<int, 2> ,5> builds = {{0,0}};

public:
	Buildings();
	~Buildings();
	
	void listBuildings() const;
	void moveBuildings();
	void renderBuildings() const;

	static void drawBorders();
};