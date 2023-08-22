#include<ranges>

#include "Board.h"
#include "Position.h"

Board::Board(std::vector<std::vector<int>>& positions)
{
	pos = positions;

	black_piece_texture.loadFromFile("black_piece.png");
	white_piece_texture.loadFromFile("white_piece.png");

	black_piece_sprite.setTexture(black_piece_texture);
	white_piece_sprite.setTexture(white_piece_texture);
}

auto Board::draw(sf::RenderWindow& window) -> void
{
	for (auto i : std::ranges::views::iota(0) | std::ranges::views::take(pos.size()))
	{
		for (auto j : std::ranges::views::iota(0) | std::ranges::views::take(pos[i].size()))
		{
			if (pos[i][j] == 1) { black_piece_sprite.setPosition(j * 25, i * 25); window.draw(black_piece_sprite); }
			else if (pos[i][j] == 2) { white_piece_sprite.setPosition(j * 25, i * 25);  window.draw(white_piece_sprite); }
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
