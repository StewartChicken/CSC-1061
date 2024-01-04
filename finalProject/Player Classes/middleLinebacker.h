#pragma once
#ifndef ML_H
#define ML_H

#include <iostream>
#include "player.h"

class MiddleLine : public Player {
private:
    int rushing;
    int coverage;

public:
    // Constructors/destructor
    MiddleLine();
    MiddleLine(std::string name, int speed, int strength, int skill, int rushing, int coverage);
    ~MiddleLine();

    // Accessors
    int getRushing() const { return rushing; }
    int getCoverage() const { return coverage; }

    // Mutators
    void setRushing(int rushing) { this->rushing = rushing; }
    void setCoverage(int coverage) { this->coverage = coverage; }

    void printStats() const override;

};

#endif