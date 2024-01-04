#pragma once
#ifndef DB_H
#define DB_H

#include <iostream>
#include "player.h"

class DefensiveBack : public Player {
private:
    int coverage;

public:
    // Constructors/destructor
    DefensiveBack();
    DefensiveBack(std::string name, int speed, int strength, int skill, int coverage);
    ~DefensiveBack();

    // Accessors
    int getCoverage() const { return coverage; }

    // Mutators
    void setCoverage(int coverage) { this->coverage = coverage; }

    void printStats() const override;

};

#endif