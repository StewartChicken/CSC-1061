#include "quarterback.h"

// Constructor
Quarterback::Quarterback() : Player() {
    this->throwing = 0;
}

// Parameterized constructor
Quarterback::Quarterback(std::string name, int speed, int strength, int skill, int throwing)
    : Player(name, speed, strength, skill) {
    this->throwing = throwing;
}

// Destructor
Quarterback::~Quarterback() {}

void Quarterback::printStats() const {
    std::cout << "Name: " << this->name << "\n" <<
        "Speed: " << this->speed << "\n" <<
        "Strength: " << this->strength << "\n" <<
        "Skill: " << this->skill << "\n" <<
        "Throwing: " << this->throwing << "\n";
}