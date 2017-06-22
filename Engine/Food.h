#pragma once
#include "Board.h"
#include "Location.h"
#include <random>

class Food
{
public:
	Food(Location& in_loc);
	void Update(Board& brd);
	void Draw(Board& brd) const;
	Location getLoc();
private:
	Location loc;
	static constexpr Color c = Colors::Blue;
	std::mt19937 rng;
};