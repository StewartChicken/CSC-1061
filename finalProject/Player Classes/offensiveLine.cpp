#include "offensiveLine.h"

// Constructor
OffensiveLine::OffensiveLine() : Player() {
    this->blocking = 0;
}

// Parameterized constructor
OffensiveLine::OffensiveLine(std::string name, int speed, int strength, int skill, int blocking)
    : Player(name, speed, strength, skill) {
    this->blocking = blocking;
}

// Destructor
OffensiveLine::~OffensiveLine() {}

void OffensiveLine::printStats() const {
    std::cout << "Name: " << this->name << "\n" <<
        "Speed: " << this->speed << "\n" <<
        "Strength: " << this->strength << "\n" <<
        "Skill: " << this->skill << "\n" <<
        "Blocking: " << this->blocking << "\n";
}