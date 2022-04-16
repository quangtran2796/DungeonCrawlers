//
// Created by Tran on 4/6/2022.
//

#ifndef DUNGEONCRAWLERS_DUNGEONMAP_H
#define DUNGEONCRAWLERS_DUNGEONMAP_H

#include "Tile.h"
#include <string>
#include <vector>
#include "Character.h"
class DungeonMap {
private:
    const int width;
    const int height;

    Tile*** gameWorld;
    DungeonMap(const DungeonMap& oldObject);
public:
    struct Position{
        int row;
        int column;
    };
    //Ask about the Kopierkonstruktor
    DungeonMap(int height, int width);
    DungeonMap(int height, int width, const std::vector<std::string>& data);
    ~DungeonMap();

    void place(Position pos, Character* c);
    Position findTile(Tile* t);
    Tile* findTile(Position pos);
    Position findCharacter(Character *c);
    void setTile(Position pos, Tile* t);
    void print();
};


#endif //DUNGEONCRAWLERS_DUNGEONMAP_H
