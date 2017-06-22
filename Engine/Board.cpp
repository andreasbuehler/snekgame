#include "Board.h"

Board::Board(Graphics & gfx)
	:
	gfx(gfx)
{
}

void Board::DrawCell(const Location& loc, Color c)
{
	gfx.DrawRectDim(dimension*loc.x, dimension*loc.y, dimension, dimension, c);
}

int Board::getWidth() 
{
	return width;
}

int Board::getHeight() 
{
	return height;
}

bool Board::isInsideBoard(Location & loc)
{
	if (loc.x+1 > width || loc.x < 0 || loc.y+1 > height || loc.y < 0)
	{
		return false;
	}
	else {
		return true;
	}
}

bool Board::isEating(Location& loc_snake, Location& loc_food)
{
	if (loc_snake.x == loc_food.x && loc_snake.y == loc_food.y)
	{
		return true;
	}
	return false;
}
