//
// Created by Tran on 4/6/2022.
//

#include "Character.h"
#include "iostream"

char Character::getCharacter() {
    return m_character;
}


int Character::move() {
    return getController()->move();
}

Character::~Character() {
    m_itemList.clear();
}

int Character::getMaxHP() {
    return 20 + (getStamina()*5);
}

Character::Character(char c, int stamina, int strength, Controller *controller) {
    m_character = c;
    m_stamina = stamina;
    m_strength = strength;
    m_hitpoints = getMaxHP();
    m_controller = controller;
}

void Character::showInfo() {
    std::cout << "Character: " << getCharacter()
              << ", Stamina: " << getStamina()
              << ", Strength: "<< getStrength()
              << ", Max HP: "<< getMaxHP() << "\n";
}

int Character::getStrength() {
    int sumStrength = m_strength;
    for(Item* i : m_itemList){
        sumStrength = sumStrength + i->modifyStrength(sumStrength);
    }
    return sumStrength;
}

void Character::addItem(Item *item) {
    m_itemList.push_back(item);
}

int Character::getStamina() {
    int sumStamina = m_stamina;
    for(Item *i: m_itemList){
        sumStamina = sumStamina + i->modifyStamina(sumStamina);
    }
    return sumStamina;
}

void Character::setHP(int newHP) {
    m_hitpoints = newHP;
}

void Character::subtractHP(int amountHP) {
    setHP(getHP() - amountHP);
}

int Character::getHP() {
    return m_hitpoints;
}

Controller *Character::getController() {
    return m_controller;
}





