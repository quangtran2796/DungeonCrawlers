//
// Created by Tran on 4/9/2022.
//

#ifndef DUNGEONCRAWLERS_PASSIVE_H
#define DUNGEONCRAWLERS_PASSIVE_H
#include "Tile.h"

class Passive : public Tile{
protected:
    bool m_status;
public:
    virtual void setStatus(const bool s) = 0;
    virtual bool getStatus() = 0;
};


#endif //DUNGEONCRAWLERS_PASSIVE_H
