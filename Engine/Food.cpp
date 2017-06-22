#include "Food.h"
Food::Food(Location& in_loc)
	:
	rng(std::random_device()())
{
	loc = in_loc;
}

void Food::Update(Board& brd)
{
	
	std::uniform_int_distribution<int> xDist(0, brd.getWidth()-1);
	std::uniform_int_distribution<int> yDist(0, brd.getHeight() - 1);
	loc = { xDist(rng), yDist(rng) };
}

void Food::Draw(Board & brd) const
{
	brd.DrawCell(loc, c);
}

Location Food::getLoc()
{
	return loc;
}
