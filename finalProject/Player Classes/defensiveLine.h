#ifndef DL_H
#define DL_H

#include <iostream>
#include "player.h"

class DefensiveLine : public Player {
private:
    int rushing;

public:
    // Constructors/destructor
    DefensiveLine();
    DefensiveLine(std::string name, int speed, int strength, int skill, int rushing);
    ~DefensiveLine();

    // Accessors
    int getRushing() const { return rushing; }

    // Mutators
    void setRushing(int rushing) { this->rushing = rushing; }

    void printStats() const override;

};

#endif