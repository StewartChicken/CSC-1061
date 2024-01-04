#include "middleLinebacker.h"

// Constructor
MiddleLine::MiddleLine() : Player() {
    this->rushing = 0;
    this->coverage = 0;
}

// Parameterized constructor
MiddleLine::MiddleLine(std::string name, int speed, int strength, int skill, int rushing, int coverage)
    : Player(name, speed, strength, skill) {
    this->rushing = rushing;
    this->coverage = coverage;
}

// Destructor
MiddleLine::~MiddleLine() {}

void MiddleLine::printStats() const {
    std::cout << "Name: " << this->name << "\n" <<
        "Speed: " << this->speed << "\n" <<
        "Strength: " << this->strength << "\n" <<
        "Skill: " << this->skill << "\n" <<
        "Rushing: " << this->rushing << "\n" <<
        "Coverage: " << this->coverage << "\n";
}