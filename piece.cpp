#include "piece.h"
#include "Position.h"

piece::piece(std::string filename, Position position)
{
	piece_texture.loadFromFile(filename);
	piece_sprite.setTexture(piece_texture);

    int x = position.m_x;
    int y = position.m_y;
    while ((x >= 0) && (x <= 7) && (y >= 0) && (y <= 7))
    {
        x += 1;
        y += 1;
        positions.push_back(Position(x, y));
    }

    x = position.m_x;
    y = position.m_y;

    while ((x >= 0) && (x <= 7) && (y >= 0) && (y <= 7))
    {
        x -= 1;
        y -= 1;
        positions.push_back(Position(x, y));
    }

    x = position.m_x;
    y = position.m_y;

    while ((x >= 0) && (x <= 7) && (y >= 0) && (y <= 7))
    {
        x += 1;
        y -= 1;
        positions.push_back(Position(x, y));
    }

    x = position.m_x;
    y = position.m_y;

    while ((x >= 0) && (x <= 7) && (y >= 0) && (y <= 7))
    {
        x -= 1;
        y += 1;
        positions.push_back(Position(x, y));
    }

    x = position.m_x;
    y = position.m_y;
}