//
// Created by Tran on 4/20/2022.
//

#include "Lever.h"

Lever::Lever(char symbol) {
    setDisplaySymbol(symbol);
}

void Lever::setActivated(const bool a) {
    m_activated = a;
}

bool Lever::getActivated() {
    return m_activated;
}

void Lever::setPassiveObject(Passive *passiveObject) {
    m_passiveObject = passiveObject;
}

void Lever::onLeave(Tile *toTile) {
    if(hasCharacter() && !toTile->hasCharacter()){
        Character* tmpCharacter = getCharacterPointer();
        setCharacter(nullptr);
        toTile->onEnter(tmpCharacter, this);
    }
}

void Lever::onEnter(Character *c, Tile *fromTile) {
    if(getDisplaySymbol() == 'L'){
        getPassiveObject()->setStatus(true);
        getPassiveObject()->setDisplaySymbol('/');
        setDisplaySymbol('!');
    }
    else{
        getPassiveObject()->setStatus(false);
        getPassiveObject()->setDisplaySymbol('X');
        setDisplaySymbol('L');
    }
    setCharacter(c);
}






