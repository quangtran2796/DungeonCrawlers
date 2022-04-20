//
// Created by Tran on 4/20/2022.
//

#include "Trap.h"

Trap::Trap(char symbol) {
    setDisplaySymbol(symbol);
    setActivated(false);
}

void Trap::onLeave(Tile *toTile) {
    if(hasCharacter() && !toTile->hasCharacter()){
        Character* tmpCharacter = getCharacterPointer();
        setCharacter(nullptr);
        toTile->onEnter(tmpCharacter, this);
    }
}

void Trap::onEnter(Character *c, Tile *fromTile) {
    if(!fromTile->hasCharacter()){
        if(!getActivated()){
            c->subtractHP(20);
            setDisplaySymbol('T');
        }
        setCharacter(c);
    }

}

void Trap::setActivated(bool a) {
    m_activated = a;
}

bool Trap::getActivated() {
    return m_activated;
}


