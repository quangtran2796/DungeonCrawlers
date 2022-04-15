//
// Created by Tran on 4/9/2022.
//

#ifndef DUNGEONCRAWLERS_WALL_H
#define DUNGEONCRAWLERS_WALL_H
#include "Tile.h"

class Wall : public Tile{
public:
    Wall(char symbol);
    // Need always define a destructor?
    ~Wall(){};
    virtual void onLeave(Tile* toTile);
    virtual void onEnter(Character* c, Tile* fromTile);
};


#endif //DUNGEONCRAWLERS_WALL_H
