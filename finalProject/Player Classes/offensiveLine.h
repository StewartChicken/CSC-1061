#pragma once
#ifndef OL_H
#define OL_H

#include <iostream>
#include "player.h"

class OffensiveLine : public Player {
private:
    int blocking;

public:
    // Constructors/destructor
    OffensiveLine();
    OffensiveLine(std::string name, int speed, int strength, int skill, int blocking);
    ~OffensiveLine();

    // Accessors
    int getBlocking() const { return blocking; }

    // Mutators
    void setBlocking(int blocking) { this->blocking = blocking; }

    void printStats() const override;

};

#endif