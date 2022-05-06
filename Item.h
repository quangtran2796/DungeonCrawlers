//
// Created by Tran on 4/20/2022.
//

#ifndef DUNGEONCRAWLERS_ITEM_H
#define DUNGEONCRAWLERS_ITEM_H


class Item {
private:
public:
    // Do we need constructor and destructor for abstract class
    // Put constructor and destructor to private -> it will throw error -> How to solve??
    Item(){}
    ~Item(){}
    virtual int modifyStrength(int strength) = 0;
    virtual int modifyStamina(int stamina) = 0;

};

class ArmingSword : public Item{
public:
    ArmingSword(){}
    ~ArmingSword(){}
    virtual int modifyStrength(int strength){
        return strength + 3;
    }
    virtual int modifyStamina(int stamina){
        return stamina;
    }
};

class GreatSword : public Item{
public:
    GreatSword(){}
    ~GreatSword(){}
    virtual int modifyStrength(int strength){
        return strength + 5;
    }
    virtual int modifyStamina(int stamina){
        return stamina - 1;
    }
};

class Club : public Item{
public:
    Club(){}
    ~Club(){}
    virtual int modifyStrength(int strength){
        return strength + 0.5*strength;
    }
    virtual int modifyStamina(int stamina){
        return stamina;
    }
};

class RapierAndDagger : public Item{
public:
    RapierAndDagger(){}
    ~RapierAndDagger(){}
    virtual int modifyStrength(int strength){
        return strength + 2;
    }
    virtual int modifyStamina(int stamina){
        return stamina + 1;
    }
};

class Gambeson : public Item{
public:
    Gambeson(){}
    ~Gambeson(){}
    virtual int modifyStrength(int strength){
        return strength;
    }
    virtual int modifyStamina(int stamina){
        return stamina + 1;
    }
};

class MailArmour : public Item{
public:
    MailArmour(){}
    ~MailArmour(){}
    virtual int modifyStrength(int strength){
        return strength;
    }
    virtual int modifyStamina(int stamina){
        return stamina + 3;
    }
};

class Shield : public Item{
public:
    Shield(){}
    ~Shield(){}
    virtual int modifyStrength(int strength){
        return strength - 1;
    }
    virtual int modifyStamina(int stamina){
        return stamina + stamina;
    }
};

class FullPlateArmour : public Item{
public:
    FullPlateArmour(){}
    ~FullPlateArmour(){}
    virtual int modifyStrength(int strength){
        return strength - 2;
    }
    virtual int modifyStamina(int stamina){
        return stamina + 6;
    }
};
#endif //DUNGEONCRAWLERS_ITEM_H
