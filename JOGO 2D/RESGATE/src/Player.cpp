#include "Player.h"
#include "Map.h"

Player::Player(const std::string& name, int x, int y)
    : Entity(x, y, '@'), name(name), hp(100), maxHp(100), level(1), gold(0) {}

bool Player::tryMove(int dx, int dy, const Map &map) {
    int nx = x + dx;
    int ny = y + dy;

    if (!map.isInside(nx, ny)) return false;

    char tile = map.getTile(nx, ny);
    if (tile == '#') return false;

    x = nx;
    y = ny;
    return true;
}
