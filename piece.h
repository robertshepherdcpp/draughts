#pragma once

#include<SFML/Graphics.hpp>

#include<string>

#include "board.h"
#include "Position.h"

struct piece
{
	piece(std::string filename, Position position);

	auto canMoveToPosition(Position position) -> bool;

	std::vector<Position> positions{};

	sf::Texture piece_texture;
	sf::Sprite piece_sprite;

	Position m_position;

	bool isKing = false;
};