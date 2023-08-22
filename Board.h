#pragma once

#include<SFML/Graphics.hpp>

#include<vector>

struct Board
{
	Board(std::vector<std::vector<int>>& positions);

	auto draw(sf::RenderWindow& window) -> void;

	auto at(int x, int y) -> int;
	auto set(int x, int y, int value) -> void;

	std::vector<std::vector<int>> pos{};

	sf::Texture black_piece_texture;
	sf::Texture white_piece_texture;

	sf::Sprite black_piece_sprite;
	sf::Sprite white_piece_sprite;
};