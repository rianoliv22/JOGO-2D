#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>

class Map {
private:
    std::vector<std::string> grid;

    public:
    Map() = default;

    bool isWall(int x, int y);
    bool loadFromFile(const std::string &path);
    void loadDefault();
    void render(int px, int py) const;

    bool isInside(int x, int y) const;
    char getTile(int x, int y) const;
    void setTile(int x, int y, char c);

    int width() const;
    int height() const;
};

#endif // MAP_H
