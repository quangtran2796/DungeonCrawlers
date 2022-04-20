//
// Created by Tran on 4/9/2022.
//

#include "Wall.h"
#include "Tile.h"

void Wall::onLeave(Tile *toTile) {

}

void Wall::onEnter(Character *c, Tile *fromTile) {
    fromTile->setCharacter(c);
}

Wall::Wall(char symbol) {
    setDisplaySymbol(symbol);
}

bool Wall::isTransparent() {
    return false;
}
