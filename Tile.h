//
// Created by Tran on 4/6/2022.
//

#ifndef DUNGEONCRAWLERS_TILE_H
#define DUNGEONCRAWLERS_TILE_H

#include "Tile.h"
#include "Character.h"
// Ask public or private enum, struct

class Tile {
public:
    enum KachelTypen{
        Floor,
        Wall
    };

private:
    KachelTypen kachelTyp;
    Character *character;
    
public:
    Tile(KachelTypen initKachelTyp);
    ~Tile();

    KachelTypen getKachelTyp();
    Character* getCharacter();

    void setCharacter(Character* newCharacter);
    bool hasCharacter();
    void onLeave(Tile* toTile);
    void onEnter(Character* c, Tile* fromTile);
};

#endif //DUNGEONCRAWLERS_TILE_H
