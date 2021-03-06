#include "Board.h"

Board::Board(Graphics & gfx)
	:
	gfx(gfx)
{
}

void Board::DrawBorder(int x,int y, Graphics & gfx, Color C)
{
	gfx.DrawRectH(x, y, Width*Dim, Height*Dim, C);
}

const int Board::GetWidth() const
{
	return Width;
}

const int Board::GetHeight() const
{
	return Height;
}

/*bool Board::IsInside(const Location & loc) const
{
	return (loc.x >= 50) && (loc.x < GetWidth()) && (loc.y >= 20) && (loc.y<GetHeight());
}
*/