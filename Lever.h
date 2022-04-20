//
// Created by Tran on 4/20/2022.
//

#ifndef DUNGEONCRAWLERS_LEVER_H
#define DUNGEONCRAWLERS_LEVER_H
#include "Active.h"

class Lever : public Active{
public:
    Lever(char symbol);
    ~Lever(){}
    virtual void setActivated(const bool a);
    virtual bool getActivated();
    virtual void setPassiveObject(Passive *passiveObject);
    virtual Passive *getPassiveObject();
    virtual void onLeave(Tile *toTile);
    virtual void onEnter(Character* c, Tile *fromTile);
};


#endif //DUNGEONCRAWLERS_LEVER_H
