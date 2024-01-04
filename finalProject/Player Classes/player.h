#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

class Player {
protected:
    std::string name;
    int speed;
    int strength;
    int skill;

public:
    // Constructors/destructor
    Player();
    Player(std::string name, int speed, int strength, int skill);
    ~Player();

    // Accessors
    std::string getName() const { return name; }
    int getSpeed() const { return speed; }
    int getStrength() const { return strength; }
    int getSkill() const { return skill; }

    // Mutators
    void setName(std::string name) { this->name = name; }
    void setSpeed(int speed) { this->speed = speed; }
    void setStrength(int strength) { this->strength = strength; }
    void setSkill(int skill) { this->skill = skill; }

    virtual void printStats() const;

};

#endif