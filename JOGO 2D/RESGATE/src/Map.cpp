#include "Map.h"
#include <fstream>
#include <iostream>

bool Map::loadFromFile(const std::string &path) {
    std::ifstream f(path);
    if (!f.is_open()) return false;

    grid.clear();
    std::string line;
    while (std::getline(f, line)) {
        grid.push_back(line);
    }
    f.close();

    return !grid.empty();
}

void Map::loadDefault() {
    grid = {
        "###############################",
        "#V......F....M....F....L.....#",
        "#..F..##..F....MM....F....##.#",
        "#.....F..~~~.......F...M....C#",
        "#..M....F....###.............#",
        "#....L.......F.....M...F....##",
        "###############################"
    };
}

void Map::render(int px, int py) const {

#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#else
    system("clear");
#endif

    for (int y = 0; y < (int)grid.size(); ++y) {
        for (int x = 0; x < (int)grid[y].size(); ++x) {
            if (x == px && y == py)
                std::cout << '@';
            else
                std::cout << grid[y][x];
        }
        std::cout << '\n';
    }
}

bool Map::isInside(int x, int y) const {
    if (y < 0 || y >= (int)grid.size()) return false;
    if (x < 0 || x >= (int)grid[y].size()) return false;
    return true;
}

char Map::getTile(int x, int y) const {
    if (!isInside(x, y)) return '#';
    return grid[y][x];
}

void Map::setTile(int x, int y, char c) {
    if (!isInside(x, y)) return;
    grid[y][x] = c;
}

int Map::width() const {
    return grid.empty() ? 0 : grid[0].size();
}

int Map::height() const {
    return grid.size();
}

bool Map::isWall(int x, int y) {
    if (y < 0 || y >= grid.size()) return true;
    if (x < 0 || x >= grid[y].size()) return true;

    return grid[y][x] == '#';
}
