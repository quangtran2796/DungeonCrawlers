//
// Created by Tran on 4/6/2022.
//

#include "Tile.h"
#include "Character.h"

Character *Tile::getCharacterPointer(){
    return m_character;
}

void Tile::setCharacter(Character *newCharacter) {
    m_character = newCharacter;
}

bool Tile::hasCharacter() {
    if(getCharacterPointer() != nullptr)
        return true;
    else
        return false;
}



void Tile::setDisplaySymbol(char s) {
    m_displaySymbol = s;
}

char Tile::getDisplaySymbol() {
    return m_displaySymbol;
}

Tile::Tile() {
    m_character = nullptr;
}

Tile::~Tile() {
    m_character = nullptr;
}

bool Tile::isTransparent() {
    return true;
}
