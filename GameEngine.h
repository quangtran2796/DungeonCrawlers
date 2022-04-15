//
// Created by Tran on 4/6/2022.
//

#ifndef DUNGEONCRAWLERS_GAMEENGINE_H
#define DUNGEONCRAWLERS_GAMEENGINE_H

#include "DungeonMap.h"
#include <vector>
class GameEngine {
private:
    DungeonMap gameWorld;
    std::vector<Character*> vectorCharacter;

    DungeonMap::Position nextPlayerPosition(int direction, DungeonMap::Position currentPosition);
public:
    GameEngine(int height, int width, int numDependence, const std::vector<std::string>& data, std::vector<std::string> &switchDoor);
    ~GameEngine();

    bool finished();
    void turn();
    void run();
};


#endif //DUNGEONCRAWLERS_GAMEENGINE_H
