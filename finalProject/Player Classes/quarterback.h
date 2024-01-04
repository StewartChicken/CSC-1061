#pragma once
#ifndef QB_H
#define QB_H

#include <iostream>
#include "player.h"

class Quarterback : public Player {
private:
    int throwing;

public:
    // Constructors/destructor
    Quarterback();
    Quarterback(std::string name, int speed, int strength, int skill, int throwing);
    ~Quarterback();

    // Accessors
    int getThrowing() const { return throwing; }

    // Mutators
    void setThrowing(int throwing) { this->throwing = throwing; }

    void printStats() const override;

};

#endif