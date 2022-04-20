//
// Created by Tran on 4/6/2022.
//

#ifndef DUNGEONCRAWLERS_CHARACTER_H
#define DUNGEONCRAWLERS_CHARACTER_H
#include "Controller.h"
#include <vector>
#include "Item.h"

class Character {
private:
    char m_character;
    Controller *m_controller;
    int m_strength;
    int m_stamina;
    int m_hitpoints;
    std::vector<Item*> m_itemList;
public:
    Character(char c, int stamina, int strength);
    ~Character();
    char getCharacter();
    int move();
    int getMaxHP();
    void setHP(int newHP);
    int getHP();
    void showInfo();
    void addItem(Item *item);
    int getStrength();
    int getStamina();
    void subtractHP(int amountHP);

};


#endif //DUNGEONCRAWLERS_CHARACTER_H
