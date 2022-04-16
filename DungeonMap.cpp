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
                    gameWorld[i][j] = new Door('X');
                    break;
                case'/':
                    gameWorld[i][j] = new Door('/');
                    break;
            }
        }
    }
}

DungeonMap::~DungeonMap() {
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++)
            delete[] gameWorld[i][j];
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

void DungeonMap::print() {
    for(int i = 0; i < height ; i++){
        for(int j = 0; j < width; j++){
            if(gameWorld[i][j]->getCharacterPointer() != nullptr)
                std::cout << gameWorld[i][j]->getCharacterPointer()->getCharacter();
            else
                std::cout << gameWorld[i][j]->getDisplaySymbol();
        }
        std::cout << std::endl;
    }
}

void DungeonMap::setTile(DungeonMap::Position pos, Tile *t) {
    gameWorld[pos.row][pos.column] = t;
}









