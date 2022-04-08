//
// Created by Tran on 4/6/2022.
//

#include "GameEngine.h"
#include "DungeonMap.h"
#include <iostream>

GameEngine::GameEngine(int height, int width, const std::vector<std::string> &data) : gameWorld(height, width, data) {
    vectorCharacter.push_back(new Character('@'));

    // Put the figur at the first floor in the map
    DungeonMap::Position searchFloorPosition = {.row=0,.column=0};
    bool stopSearch = false;
    for(int i = 0; i < height && !stopSearch; i++)
        for(int j = 0; j < width && !stopSearch; j++){
            searchFloorPosition.row = i;
            searchFloorPosition.column = j;
            if(gameWorld.findTile(searchFloorPosition)->getKachelTyp() == Tile::Floor) {
                gameWorld.place(searchFloorPosition, vectorCharacter[0]);
                stopSearch = true;
            }
        }
}

void GameEngine::run() {
    while (!finished())
        turn();
}

void GameEngine::turn() {

    DungeonMap::Position currentPosition = gameWorld.findCharacter(vectorCharacter[0]);
    std::cout << "Current position: row " << currentPosition.row << " column " << currentPosition.column << std::endl;
    int moveDirection = vectorCharacter[0]->move();
    DungeonMap::Position nextPosition = nextPlayerPosition(moveDirection, currentPosition);
    Tile* currentTile = gameWorld.findTile(currentPosition);
    Tile* nextTile = gameWorld.findTile(nextPosition);
    currentTile->onLeave(nextTile);
    gameWorld.print();
}

DungeonMap::Position GameEngine::nextPlayerPosition(int direction, DungeonMap::Position currentPosition) {
    DungeonMap::Position nextPosition = {.row=0, .column=0};
    switch (direction) {
        case 1:
            nextPosition.row = currentPosition.row + 1;
            nextPosition.column = currentPosition.column - 1;
            break;
        case 2:
            nextPosition.row = currentPosition.row + 1;
            nextPosition.column = currentPosition.column;
            break;
        case 3:
            nextPosition.row = currentPosition.row + 1;
            nextPosition.column = currentPosition.column + 1;
            break;
        case 4:
            nextPosition.row = currentPosition.row;
            nextPosition.column = currentPosition.column - 1;
            break;
        case 5:
            nextPosition.row = currentPosition.row;
            nextPosition.column = currentPosition.column;
            break;
        case 6:
            nextPosition.row = currentPosition.row;
            nextPosition.column = currentPosition.column + 1;
            break;
        case 7:
            nextPosition.row = currentPosition.row - 1;
            nextPosition.column = currentPosition.column - 1;
            break;
        case 8:
            nextPosition.row = currentPosition.row - 1;
            nextPosition.column = currentPosition.column;
            break;
        case 9:
            nextPosition.row = currentPosition.row - 1;
            nextPosition.column = currentPosition.column + 1;
            break;
    }
    return nextPosition;
}

GameEngine::~GameEngine() {

}

bool GameEngine::finished() {
    DungeonMap::Position currentPosition = gameWorld.findCharacter(vectorCharacter[0]);
    if(currentPosition.row == 5 && currentPosition.column == 5){
        std::cout << "Game over!!!" << std::endl;
        return true;
    }


    return false;
}


