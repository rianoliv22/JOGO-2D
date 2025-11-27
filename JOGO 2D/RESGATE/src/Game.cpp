#include "Game.h"
#include <iostream>
#include <thread>
#include <chrono>

Game::Game() {
    running = true;
    map.loadDefault();
}

bool Game::isRunning() {
    return running;
}

void Game::start() {
    while (running) {
        update();
        render();

        // água deixa lento
        char tile = map.getTile(player.x, player.y);
        int delay = (tile == '~') ? 240 : 120;

        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
}

void Game::update() {
    char comando;

    std::cout << "\nDigite comando (w,a,s,d,q): ";
    std::cin >> comando;

    if (comando == 'q') {
        running = false;
        return;
    }

    int newX = player.x;
    int newY = player.y;

    if (comando == 'w') newY--;
    if (comando == 's') newY++;
    if (comando == 'a') newX--;
    if (comando == 'd') newX++;

    if (!map.isWall(newX, newY)) {
        player.x = newX;
        player.y = newY;

        char tile = map.getTile(newX, newY);
        processTile(tile);
    }
}

void Game::processTile(char tile) {
    switch (tile) {

        case 'F':
            player.hp += 10;
            if (player.hp > 100) player.hp = 100;
            player.inventario.push_back("Fruta");
            map.setTile(player.x, player.y, '.');
            break;

        case 'M':
            player.hp -= 20;
            player.inventario.push_back("Monstro derrotado");
            map.setTile(player.x, player.y, '.');
            if (player.hp <= 0) {
                running = false;
            }
            break;

        case 'L':
            player.xp += 15;
            player.inventario.push_back("Livro antigo");
            map.setTile(player.x, player.y, '.');
            break;

        case 'C':
            player.gold += 50;
            player.inventario.push_back("Cofre aberto");
            map.setTile(player.x, player.y, '.');
            break;

        case '~':
            // nada, só deixa mais lento no loop
            break;
    }
}

void Game::render() {
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#else
    system("clear");
#endif

    // HUD
    std::cout << "=== JOGO 2D RPG ===\n";
    std::cout << "Vida: " << player.hp << "\n";
    std::cout << "XP: " << player.xp << "\n";
    std::cout << "Ouro: " << player.gold << "\n";
    std::cout << "Posição: (" << player.x << "," << player.y << ")\n";

    std::cout << "Inventário: ";
    if (player.inventario.empty()) std::cout << "vazio";
    else {
        for (auto &item : player.inventario) {
            std::cout << item << ", ";
        }
    }

    std::cout << "\n\n";

    map.render(player.x, player.y);
}
