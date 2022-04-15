//
// Created by Tran on 4/9/2022.
//

#include "Floor.h"
#include "Tile.h"

void Floor::onLeave(Tile *toTile) {
    if(hasCharacter() && !toTile->hasCharacter()){
        Character* tmpCharacter = getCharacterPointer();
        setCharacter(nullptr);
        toTile->onEnter(tmpCharacter, this);
    }
}

void Floor::onEnter(Character *c, Tile *fromTile) {
    if(!fromTile->hasCharacter())
        setCharacter(c);
}

Floor::Floor(char symbol) {
    setDisplaySymbol(symbol);
}
