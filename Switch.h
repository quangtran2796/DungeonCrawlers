//
// Created by Tran on 4/9/2022.
//

#ifndef DUNGEONCRAWLERS_SWITCH_H
#define DUNGEONCRAWLERS_SWITCH_H
#include "Active.h"

class Switch : public Active{
public:
    Switch(char symbol);
    ~Switch(){};
    virtual void setActivated(const bool a);
    virtual bool getActivated();
    virtual void setPassiveObject(Passive *passiveObject);
    virtual Passive *getPassiveObject();
    virtual void onLeave(Tile *toTile);
    virtual void onEnter(Character* c, Tile *fromTile);
};


#endif //DUNGEONCRAWLERS_SWITCH_H
