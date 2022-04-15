//
// Created by Tran on 4/6/2022.
//

#ifndef DUNGEONCRAWLERS_CHARACTER_H
#define DUNGEONCRAWLERS_CHARACTER_H
#include "Controller.h"

class Character {
private:
    char character;
    Controller *m_controller;
public:
    Character(char c);
    ~Character();
    char getCharacter();
    int move();

};


#endif //DUNGEONCRAWLERS_CHARACTER_H
