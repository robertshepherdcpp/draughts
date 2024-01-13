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

    int position_x_from = 0;
    int position_y_from = 0;

    bool already_clicked = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (already_clicked)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

                    int x_remainder = int(worldPos.x) % 25;
                    int y_remainder = int(worldPos.y) % 25;

                    int x_pos = (int(worldPos.x) - x_remainder) / 25;
                    int y_pos = (int(worldPos.y) - y_remainder) / 25;

                    if (board.at(position_x_from, position_y_from) == 1) { board.set(y_pos, x_pos, 1); }
                    else if (board.at(position_x_from, position_y_from) == 2) { board.set(y_pos, x_pos, 2); }

                    board.set(position_x_from, position_y_from, 0);

                    already_clicked = false;
                }
                else
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

                    int x_remainder = int(worldPos.x) % 25;
                    int y_remainder = int(worldPos.y) % 25;

                    int x_pos = (int(worldPos.x) - x_remainder) / 25;
                    int y_pos = (int(worldPos.y) - y_remainder) / 25;

                    position_x_from = y_pos;
                    position_y_from = x_pos;

                    already_clicked = true;

                }
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Z)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

                    int x_remainder = int(worldPos.x) % 25;
                    int y_remainder = int(worldPos.y) % 25;

                    int x_pos = (int(worldPos.x) - x_remainder) / 25;
                    int y_pos = (int(worldPos.y) - y_remainder) / 25;

                    board.set(x_pos, y_pos, 0);
                }
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