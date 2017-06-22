#pragma once

struct Location
{
	void Add(const Location& delta_loc) {
		x += delta_loc.x;
		y += delta_loc.y;
	}
	int x;
	int y;
};