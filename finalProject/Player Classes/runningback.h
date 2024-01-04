#pragma once
#ifndef RB_H
#define RB_H

#include <iostream>
#include "player.h"

class Runningback : public Player {
private:
    int elusiveness;

public:
    // Constructors/destructor
    Runningback();
    Runningback(std::string name, int speed, int strength, int skill, int elusiveness);
    ~Runningback();

    // Accessors
    int getElusiveness() const { return elusiveness; }

    // Mutators
    void setElusiveness(int elusiveness) { this->elusiveness = elusiveness; }

    void printStats() const override;

};

#endif