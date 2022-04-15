//
// Created by Tran on 4/9/2022.
//

#include "Switch.h"

void Switch::setActivated(const bool a) {
    m_activated = a;
}

bool Switch::getActivated() {
    return m_activated;
}

void Switch::setPassiveObject(Passive *passiveObject) {
    m_passiveObject = passiveObject;
}

Switch::Switch(char symbol) {
    setDisplaySymbol(symbol);
}

void Switch::onLeave(Tile *toTile) {
    if(hasCharacter() && toTile->hasCharacter()){
        Character* tmpCharacter = getCharacterPointer();
        setCharacter(nullptr);
        toTile->onEnter(tmpCharacter, this);
    }
}

void Switch::onEnter(Character *c, Tile *fromTile) {
    if(getDisplaySymbol() == '?'){
        getPassiveObject()->setStatus(true);
        getPassiveObject()->setDisplaySymbol('/');
    }
    setCharacter(c);
}

Passive *Switch::getPassiveObject() {
    return m_passiveObject;
}



