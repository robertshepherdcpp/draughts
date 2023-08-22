#include <SFML/Graphics.hpp>

#include<vector>

#include "board.h"
#include "piece.h"
#include "Position.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    std::vector<std::vector<int>> positionsOfPieces
    {
            std::vector<int>{0, 1, 0, 1, 0, 1, 0, 1},
            std::vector<int>{1, 0, 1, 0, 1, 0, 1, 0},
            std::vector<int>{0, 1, 0, 1, 0, 1, 0, 1},
            std::vector<int>{0, 0, 0, 0, 0, 0, 0, 0},
            std::vector<int>{0, 0, 0, 0, 0, 0, 0, 0},
            std::vector<int>{2, 0, 2, 0, 2, 0, 2, 0},
            std::vector<int>{0, 2, 0, 2, 0, 2, 0, 2},
            std::vector<int>{2, 0, 2, 0, 2, 0, 2, 0}
    };

    Board board(positionsOfPieces);

    sf::Texture board_texture;
    board_texture.loadFromFile("chess_board.png");
    sf::Sprite board_sprite;
    board_sprite.setTexture(board_texture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        board.draw(window);

        window.clear();
        window.draw(board_sprite);
        board.draw(window);
        window.display();
    }

    return 0;
}