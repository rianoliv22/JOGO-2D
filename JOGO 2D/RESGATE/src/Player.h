#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include <string>

class Map; // declaração antecipada

class Player : public Entity {
public:
    std::string name;
    int hp;
    int maxHp;
    int level;
    int gold;

    Player(const std::string& name = "Hero", int x = 0, int y = 0);

    bool tryMove(int dx, int dy, const Map &map);
};

#endif // PLAYER_H
