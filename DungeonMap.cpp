//
// Created by Tran on 4/6/2022.
//

#include "DungeonMap.h"
#include "Tile.h"
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
            if(data[i][j]=='.')
                gameWorld[i][j] = new Tile(Tile::Floor);
            else
                gameWorld[i][j] = new Tile(Tile::Wall);
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
            if(gameWorld[i][j]->getCharacter() == c) {
                returnPosition.row=i;
                returnPosition.column=j;
            }
        }

    return returnPosition;
}

void DungeonMap::print() {
    for(int i = 0; i < height ; i++){
        for(int j = 0; j < width; j++){
            if(gameWorld[i][j]->getKachelTyp() == Tile::Floor) {
                if(gameWorld[i][j]->hasCharacter())
                    std::cout << gameWorld[i][j]->getCharacter()->getCharacter();

                std::cout << '.';
            }
            else
                std::cout << '#';
        }
        std::cout << std::endl;
    }
}








