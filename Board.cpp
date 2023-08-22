#include<ranges>

#include "Board.h"
#include "Position.h"

Board::Board(std::vector<std::vector<int>>& positions)
{
	pos = positions;

	black_piece_texture.loadFromFile("black_checker.png");
	white_piece_texture.loadFromFile("white_checker.png");

	black_piece_sprite.setTexture(black_piece_texture);
	white_piece_texture.setTexture(white_piece_texture);
}

auto Board::draw(sf::RenderWindow& window) -> void
{
	for (int i = 0; i < pos.size(); i++)
	{
		for (int j = 0; j < pos[i].size(); j++)
		{
			if (pos[i][j] == 1) { window.draw(black_piece_sprite); }
			else if (pos[i][j] == 2) { window.draw(white_piece_sprite); }
		}
	}
}

auto Board::at(int x, int y) -> int
{
	return pos[x][y];
}

auto Board::set(int x, int y, int value) -> void
{
	pos[x][y] = value;
}
