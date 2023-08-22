#pragma once

#include<SFML/Graphics.hpp>

#include<vector>

struct Board
{
	Board(std::vector<std::vector<int>>& positions);

	auto at(int x, int y) -> int;
	auto set(int x, int y, int value) -> void;

	std::vector<std::vector<int>> pos{};
};