#include "Board.h"

Board::Board(std::vector<std::vector<int>>& positions)
{
	pos = positions;
}

auto Board::at(int x, int y) -> int
{
	return pos[x][y];
}

auto Board::set(int x, int y, int value) -> void
{
	pos[x][y] = value;
}
