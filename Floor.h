//
// Created by Tran on 4/9/2022.
//

#ifndef DUNGEONCRAWLERS_FLOOR_H
#define DUNGEONCRAWLERS_FLOOR_H
#include "Tile.h"
#include "Character.h"
#include "Item.h"

class Floor : public Tile{
private:
    Item * m_item;
public:
    Floor(char symbol);
    ~Floor(){};
    virtual void onLeave(Tile *toTile);
    virtual void onEnter(Character* c, Tile* fromTile);
    void setItem(Item *i);
};


#endif //DUNGEONCRAWLERS_FLOOR_H
