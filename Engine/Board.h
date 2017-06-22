#pragma once
#include "Graphics.h"
#include "Location.h"

class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c);
	int getWidth() ;
	int getHeight() ;
	bool isInsideBoard(Location& delta_loc);
	bool isEating(Location& loc_snake, Location& loc_food);
private:
	Graphics& gfx;
	static constexpr int dimension = 25;
	static constexpr int width = 800/dimension;
	static constexpr int height = 600/dimension;
};
