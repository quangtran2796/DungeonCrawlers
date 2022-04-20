//
// Created by Tran on 4/6/2022.
//

#ifndef DUNGEONCRAWLERS_TILE_H
#define DUNGEONCRAWLERS_TILE_H

#include "Tile.h"
#include "Character.h"
// Ask public or private enum, struct

class Tile {
private:
    Character *m_character;
    char m_displaySymbol;
public:
    Tile();
    ~Tile();

    Character *getCharacterPointer();

    void setCharacter(Character* newCharacter);
    bool hasCharacter();
    void setDisplaySymbol(char s);
    char getDisplaySymbol();
    virtual void onLeave(Tile* toTile) = 0;
    virtual void onEnter(Character* c, Tile* fromTile) = 0;
    virtual bool isTransparent();
};

#endif //DUNGEONCRAWLERS_TILE_H
