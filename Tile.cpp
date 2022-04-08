//
// Created by Tran on 4/6/2022.
//

#include "Tile.h"
#include "Character.h"

Tile::Tile(Tile::KachelTypen initKachelTyp) {
    kachelTyp = initKachelTyp;
    character = nullptr;

}

Tile::KachelTypen Tile::getKachelTyp() {
    return kachelTyp;
}

Character *Tile::getCharacter() {
    return character;
}

void Tile::setCharacter(Character *newCharacter) {
    character = newCharacter;
}

bool Tile::hasCharacter() {
    if(character != nullptr)
        return true;
    else
        return false;
}

void Tile::onLeave(Tile *toTile) {
    if(this->hasCharacter() && toTile->getKachelTyp() == Tile::Floor && !toTile->hasCharacter()){
        Character* tmpCharacter = character;
        character = nullptr;
        toTile->onEnter(tmpCharacter, this);
    }
}

void Tile::onEnter(Character *c, Tile *fromTile) {
    if(!fromTile->hasCharacter())
        character = c;
}

Tile::~Tile() {

}
