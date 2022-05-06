//
// Created by Tran on 4/6/2022.
//

#include "GameEngine.h"
#include "DungeonMap.h"
#include "Door.h"
#include "Switch.h"
#include "ConsoleController.h"
#include <iostream>
#include <fstream>

GameEngine::GameEngine(int height, int width, int numDependence, const std::vector<std::string> &data, std::vector<std::string> &switchDoor) : gameWorld(height, width, data) {
    vectorCharacter.push_back(new Character('@', 10, 10, new ConsoleController()));
    mapParser("level2.txt");
    // Put the figur at the first floor in the map
    DungeonMap::Position searchFloorPosition = {.row=0,.column=0};
    bool stopSearch = false;
    for(int i = 0; i < height && !stopSearch; i++){
        for(int j = 0; j < width && !stopSearch; j++){
            searchFloorPosition.row = i;
            searchFloorPosition.column = j;
            if(gameWorld.findTile(searchFloorPosition)->getDisplaySymbol() == '.') {
                gameWorld.place(searchFloorPosition, vectorCharacter[0]);
                stopSearch = true;
            }
        }
    }

    int sdPosition[2];
    int sdPositionIndex = 0;
    Door *doorTile;
    Switch *switchTile;
    for(int i = 0; i < numDependence; i++){
        for(int j = 0; j < 11; j++){
            if(switchDoor[i][j] != ' ') {
                if(switchDoor[i][j] != 'D' && switchDoor[i][j] != 'S'){
                    sdPosition[sdPositionIndex] = switchDoor[i][j]-'0';
                    sdPositionIndex++;
                }
                else if(switchDoor[i][j] == 'D'){
                    DungeonMap::Position tmpPosition{sdPosition[0]-1, sdPosition[1]-1};
                    doorTile = new Door('X', false);
                    gameWorld.setTile(tmpPosition, doorTile);
                    sdPositionIndex = 0;
                }
                else if(switchDoor[i][j] == 'S'){
                    DungeonMap::Position tmpPosition{sdPosition[0]-1, sdPosition[1]-1};
                    switchTile = new Switch('?');
                    switchTile->setPassiveObject(doorTile);
                    gameWorld.setTile(tmpPosition, switchTile);
                    sdPositionIndex = 0;
                }
            }
        }
    }
}

void GameEngine::run() {
    while (!finished())
        turn();
}

void GameEngine::turn() {

    DungeonMap::Position currentPosition = gameWorld.findCharacter(vectorCharacter[0]);
    vectorCharacter[0]->showInfo();
    std::cout << "Current position: row " << currentPosition.row << " column " << currentPosition.column << std::endl;
    gameWorld.print(currentPosition);
    int moveDirection = vectorCharacter[0]->move();
    DungeonMap::Position nextPosition = nextPlayerPosition(moveDirection, currentPosition);
    Tile* currentTile = gameWorld.findTile(currentPosition);
    Tile* nextTile = gameWorld.findTile(nextPosition);
    currentTile->onLeave(nextTile);
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

void GameEngine::mapParser(std::string levelPath){
    std::string line;
    std::ifstream myFile("level2.txt");
    if(myFile.is_open()){
        while(getline(myFile, line)){
            std::cout << line << '\n';
        }
        myFile.close();
    }
    else std::cout << "Unable to open file!";
}