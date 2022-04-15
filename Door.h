//
// Created by Tran on 4/9/2022.
//

#ifndef DUNGEONCRAWLERS_DOOR_H
#define DUNGEONCRAWLERS_DOOR_H
#include "Passive.h"

class Door : public Passive{
public:
    Door(char symbol);
    ~Door(){};
    virtual void setStatus(const bool s);
    virtual bool getStatus();
    virtual void onLeave(Tile *toTile);
    virtual void onEnter(Character* c, Tile *fromTile);
};

#endif //DUNGEONCRAWLERS_DOOR_H
