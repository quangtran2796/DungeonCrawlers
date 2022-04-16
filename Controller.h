//
// Created by Tran on 4/15/2022.
//

#ifndef DUNGEONCRAWLERS_CONTROLLER_H
#define DUNGEONCRAWLERS_CONTROLLER_H

//#include "Character.h"
class Character;
// Ask if this is a better way
class Controller {
private:
    Character *m_character;
public:
    Controller(){
        m_character = nullptr;
    };
    void setCharacterPointer(Character *c){
        m_character = c;
    };
    Character *getCharacterPointer(){
        return m_character;
    };
    virtual int move() = 0;
};


#endif //DUNGEONCRAWLERS_CONTROLLER_H
