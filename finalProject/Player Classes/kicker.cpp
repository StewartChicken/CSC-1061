#include "kicker.h"

// Constructor
Kicker::Kicker() : Player() {
    this->kicking = 0;
}

// Parameterized constructor
Kicker::Kicker(std::string name, int speed, int strength, int skill, int kicking)
    : Player(name, speed, strength, skill) {
    this->kicking = kicking;
}

// Destructor
Kicker::~Kicker() {}

void Kicker::printStats() const {
    std::cout << "Name: " << this->name << "\n" <<
        "Speed: " << this->speed << "\n" <<
        "Strength: " << this->strength << "\n" <<
        "Skill: " << this->skill << "\n" <<
        "Kicking: " << this->kicking << "\n";
}