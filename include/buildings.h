#pragma once


class Buildings{
private:
	std::array<std::array<int, 3> ,5> builds = {{0,0,0}}; // pos, height, width
	std::array<std::array<int, 3> ,5> old_builds = {{0,0,0}}; // pos, height, width

public:
	Buildings();
	~Buildings();
	
	void listBuildings() const;
	void moveBuildings();
	void renderBuildings();

	static void drawBorders();
};