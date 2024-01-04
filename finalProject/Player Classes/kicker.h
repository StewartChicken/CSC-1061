#pragma once
#ifndef K_H
#define K_H

#include <iostream>
#include "player.h"

class Kicker : public Player {
private:
    int kicking;

public:
    // Constructors/destructor
    Kicker();
    Kicker(std::string name, int speed, int strength, int skill, int kicking);
    ~Kicker();

    // Accessors
    int getKicking() const { return kicking; }

    // Mutators
    void setKicking(int kicking) { this->kicking = kicking; }

    void printStats() const override;

};

#endif