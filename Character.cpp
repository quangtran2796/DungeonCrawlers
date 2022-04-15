//
// Created by Tran on 4/6/2022.
//

#include "Character.h"
#include "iostream"

char Character::getCharacter() {
    return character;
}

Character::Character(char c) {
    character = c;
}

int Character::move() {
    char direction;
    std::cout << "Type your next move direction 1-9:";
    std::cin >> direction;
    m_controller->move();
    return direction - '0';
}

Character::~Character() {

}
