#pragma once

struct Position
{
	Position(int x, int y);
	Position() = default;

	int m_x{};
	int m_y{};
};