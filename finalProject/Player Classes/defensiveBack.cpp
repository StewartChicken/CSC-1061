#include "defensiveBack.h"

// Constructor
DefensiveBack::DefensiveBack() : Player() {
    this->coverage = 0;
}

// Parameterized constructor
DefensiveBack::DefensiveBack(std::string name, int speed, int strength, int skill, int coverage)
    : Player(name, speed, strength, skill)
{
    this->coverage = coverage;
}

// Destructor
DefensiveBack::~DefensiveBack() {}

void DefensiveBack::printStats() const {
    std::cout << "Name: " << this->name << "\n" <<
        "Speed: " << this->speed << "\n" <<
        "Strength: " << this->strength << "\n" <<
        "Skill: " << this->skill << "\n" <<
        "Coverage: " << this->coverage << "\n";
}
