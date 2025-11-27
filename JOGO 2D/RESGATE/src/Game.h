#ifndef GAME_H
#define GAME_H

#include "Map.h"
#include <string>
#include <vector>

class Game {
public:
    Game();

    void start();
    void update();
    void render();
    bool isRunning();

private:
    bool running;
    Map map;

    struct Player {
        int x = 1;
        int y = 1;
        int hp = 100;
        int xp = 0;
        int gold = 0;
        std::vector<std::string> inventario;
    } player;

    void processTile(char tile);
};

#endif
