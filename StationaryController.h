//
// Created by Tran on 4/20/2022.
//

#ifndef DUNGEONCRAWLERS_STATIONARYCONTROLLER_H
#define DUNGEONCRAWLERS_STATIONARYCONTROLLER_H
#include "Controller.h"

class StationaryController : public Controller{
public:
    virtual int move(){
        return 5;
    }
};


#endif //DUNGEONCRAWLERS_STATIONARYCONTROLLER_H
