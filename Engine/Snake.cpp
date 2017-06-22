#include "Snake.h"
#include <assert.h>
#include <math.h>

Snake::Snake(const Location & loc)
{
	segments[0].InitHead(loc);
}

void Snake::MoveBy(const Location & delta_loc)
{
	for (int i = nSegments - 1; i > 0; --i)
	{
		segments[i].Follow(segments[i - 1]);
		segments[i].InitBody();
	}
	segments[0].MoveBy(delta_loc);
}

void Snake::Grow()
{
	if (nSegments < maxSegments)
	{
		++nSegments;
	
	}
}

void Snake::Draw(Board & brd) const
{
	for (int i = 0; i < nSegments; ++i)
	{
		segments[i].Draw( brd );
	}
}

Location Snake::GetNextHeadLocation(const Location & delta_loc) const
{
	Location l( segments[0].getLoc() );
	l.Add(delta_loc);
	return l;
}

bool Snake::isSelfEaten()
{
	for (int i = nSegments; i > 0; i--)
	{
		if (segments[0].getLoc().x == segments[i].getLoc().x
			&& segments[0].getLoc().y == segments[i].getLoc().y)
		{
			return true;
		}
	}
	return false;
}

void Snake::Segment::InitHead(const Location & in_loc)
{
	loc = in_loc;
	c = Snake::headColor;
}

void Snake::Segment::InitBody()
{
	c = Snake::bodyColor;
}

void Snake::Segment::Follow(const Segment & next)
{
	loc = next.loc;
}

void Snake::Segment::MoveBy(const Location & delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.Add(delta_loc);

}

void Snake::Segment::Draw(Board & brd) const
{
	brd.DrawCell(loc,c);
}

Location Snake::Segment::getLoc() const
{
	return loc;
}

