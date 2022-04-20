//
// Created by Tran on 4/20/2022.
//

#ifndef DUNGEONCRAWLERS_TRAP_H
#define DUNGEONCRAWLERS_TRAP_H
#include "Tile.h"

class Trap : public Tile{
private:
    bool m_activated;
public:
    Trap(char symbol);
    ~Trap(){};
    void setActivated(bool a);
    bool getActivated();
    virtual void onLeave(Tile *toTile);
    virtual void onEnter(Character* c, Tile* fromTile);
};


#endif //DUNGEONCRAWLERS_TRAP_H
