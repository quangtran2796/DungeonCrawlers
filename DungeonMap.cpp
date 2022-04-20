//
// Created by Tran on 4/6/2022.
//

#include "DungeonMap.h"
#include "Tile.h"
#include "Wall.h"
#include "Floor.h"
#include "Switch.h"
#include "Door.h"
#include <iostream>
#include <cmath>

DungeonMap::DungeonMap(int height, int width) : height(height), width(width) {
    gameWorld = new Tile**[height];
    for(int i = 0; i < height; i++){
        gameWorld[i] = new Tile*[width];
        for(int j = 0; j < width; j++) gameWorld[i][j] = nullptr;
    }
}

DungeonMap::DungeonMap(int height, int width, const std::vector<std::string> &data) : height(height), width(width) {
    gameWorld = new Tile**[height];
    for(int i = 0; i < height; i++){
        gameWorld[i] = new Tile*[width];
        for(int j = 0; j < width; j++){
            switch (data[i][j]) {
                case '.':
                    gameWorld[i][j] = new Floor('.');
                    break;
                case '#':
                    gameWorld[i][j] = new Wall('#');
                    break;
                case '?':
                    gameWorld[i][j] = new Switch('?');
                    break;
                case'!':
                    gameWorld[i][j] = new Switch('!');
                    break;
                case'X':
                    gameWorld[i][j] = new Door('X', false);
                    break;
                case'/':
                    gameWorld[i][j] = new Door('/', true);
                    break;
            }
        }
    }
}

DungeonMap::~DungeonMap() {
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++)
            delete gameWorld[i][j];
        delete[] gameWorld[i];
    }
    delete[] gameWorld;
}

void DungeonMap::place(DungeonMap::Position pos, Character * c) {
    gameWorld[pos.row][pos.column]->setCharacter(c);
}

DungeonMap::Position DungeonMap::findTile(Tile *t) {
    DungeonMap::Position returnPosition = {.row=0, .column=0};
    for(int i = 0; i < height; i++)
        for(int j = 0; i < width; j++){
            if(gameWorld[i][j] == t) {
                returnPosition.row=i;
                returnPosition.column=j;
            }
        }

    return returnPosition;
}

Tile *DungeonMap::findTile(DungeonMap::Position pos) {
    return gameWorld[pos.row][pos.column];
}

DungeonMap::Position DungeonMap::findCharacter(Character *c) {
    DungeonMap::Position returnPosition = {.row=0, .column=0};
    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++){
            if(gameWorld[i][j]->getCharacterPointer() == c) {
                returnPosition.row=i;
                returnPosition.column=j;
            }
        }

    return returnPosition;
}

void DungeonMap::setTile(DungeonMap::Position pos, Tile *t) {
    gameWorld[pos.row][pos.column] = t;
}

bool DungeonMap::hasLineOfSight(DungeonMap::Position from, DungeonMap::Position to) {
    bool hasLineOfSight = true;

    if(from.row == to.row && from.column == to.column){
        return true;
    }
    else if(from.row == to.row){
        int deltaX = abs(from.column - to.column);
        for(int i = 1; i <= deltaX; i++){
            int nextX = from.column;
            if(to.column > from.column)
                nextX += i;
            else
                nextX -= i;

            Position checkTransparentPos = {from.row, nextX};
            Tile* checkedTile = findTile(checkTransparentPos);
            if(!checkedTile->isTransparent()){
                hasLineOfSight = false;
                break;
            }
        }
    }
    else if(from.column == to.column){
        int deltaY = abs(from.row - to.row);
        for(int i = 1; i <= deltaY; i++){
            int nextY = from.row;
            if(to.row > from.row)
                nextY += i;
            else
                nextY -= i;

            Position checkTransparentPos = {nextY, from.column};
            Tile* checkedTile = findTile(checkTransparentPos);
            if(!checkedTile->isTransparent()){
                hasLineOfSight = false;
                break;
            }
        }
    }
    else{
        float slope = std::abs((float)(to.row - from.row) / (float)(to.column - from.column));
        int deltaX = abs(from.column - to.column);
        int deltaY = abs(from.row - to.row);
        float signX = 1;
        float signY = 1;

        if(from.column > to.column)
            signX = -1;
        if(from.row > to.row)
            signY = -1;

        if(slope <= 1) {
            for (int i = 0; i <= deltaX; i++) {
                int nextX = round(from.column + i * signX);
                int nextY = round(from.row + i * slope * signY);

                Position checkTransparentPos = {nextY, nextX};
                Tile *checkedTile = findTile(checkTransparentPos);
                if (!checkedTile->isTransparent()) {
                    hasLineOfSight = false;
                    break;
                }
            }
        }
        else{
            for (int i = 0; i <= deltaY; i++) {
                int nextX = round(from.column + 1/slope * signX);
                int nextY = round(from.row + i * signY);

                Position checkTransparentPos = {nextY, nextX};
                Tile *checkedTile = findTile(checkTransparentPos);
                if (!checkedTile->isTransparent()) {
                    hasLineOfSight = false;
                    break;
                }
            }
        }


        }
    return hasLineOfSight;
}

void DungeonMap::print(DungeonMap::Position playerPos) {
    for(int i = 0; i < height ; i++){
        for(int j = 0; j < width; j++){
            Position checkSightPos = {i,j};
            if(hasLineOfSight(playerPos, checkSightPos)){
                if(gameWorld[i][j]->getCharacterPointer() != nullptr)
                    std::cout << gameWorld[i][j]->getCharacterPointer()->getCharacter();
                else
                    std::cout << gameWorld[i][j]->getDisplaySymbol();
            }
            else{
                std::cout << '#';
            }

        }
        std::cout << "\n";
    }
}











