#include "piece.h"

piece::piece(std::string filename, Position position)
{
	piece_texture.loadFromFile(filename);
	piece_sprite.setTexture(piece_texture);
}
