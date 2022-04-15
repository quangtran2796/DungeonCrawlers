//
// Created by Tran on 4/9/2022.
//

#ifndef DUNGEONCRAWLERS_ACTIVE_H
#define DUNGEONCRAWLERS_ACTIVE_H
#include "Tile.h"
#include "Passive.h"
// Ask what is the abstract here
class Active : public Tile{
protected:
    bool m_activated;
    // Ask why pointer works, but object doesn't work.
    Passive *m_passiveObject;
public:
    virtual void setActivated(const bool a) = 0;
    virtual bool getActivated() = 0;
    virtual void setPassiveObject(Passive *passiveObject) = 0;
    virtual Passive *getPassiveObject() = 0;
};


#endif //DUNGEONCRAWLERS_ACTIVE_H
