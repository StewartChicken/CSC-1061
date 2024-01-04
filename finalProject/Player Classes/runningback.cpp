#include "runningback.h"

// Constructor
Runningback::Runningback() : Player() {
    this->elusiveness = 0;
}

// Parameterized constructor
Runningback::Runningback(std::string name, int speed, int strength, int skill, int elusiveness)
    : Player(name, speed, strength, skill) {
    this->elusiveness = elusiveness;
}

// Destructor
Runningback::~Runningback() {}

void Runningback::printStats() const {
    std::cout << "Name: " << this->name << "\n" <<
        "Speed: " << this->speed << "\n" <<
        "Strength: " << this->strength << "\n" <<
        "Skill: " << this->skill << "\n" <<
        "Elusiveness: " << this->elusiveness << "\n";
}