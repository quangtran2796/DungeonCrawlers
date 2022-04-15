//
// Created by Tran on 4/9/2022.
//

#include "Door.h"

Door::Door(char symbol) {
    setDisplaySymbol(symbol);
}

void Door::setStatus(const bool s) {
    m_status = s;
}

bool Door::getStatus() {
    return m_status;
}

void Door::onLeave(Tile *toTile) {
    if(hasCharacter() && !toTile->hasCharacter()){
        Character* tmpCharacter = getCharacterPointer();
        setCharacter(nullptr);
        toTile->onEnter(tmpCharacter, this);
    }
}

void Door::onEnter(Character *c, Tile *fromTile) {
    if(!fromTile->hasCharacter()){
        if(getStatus())
            setCharacter(c);
        else
            fromTile->setCharacter(c);
    }
}

