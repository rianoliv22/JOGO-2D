#ifndef ENTITY_H
#define ENTITY_H

class Entity {
public:
    int x;
    int y;
    char symbol;

    Entity(int x = 0, int y = 0, char symbol = '?') : x(x), y(y), symbol(symbol) {}
    virtual ~Entity() = default;
};

#endif // ENTITY_H
