#include "defensiveLine.h"

// Constructor
DefensiveLine::DefensiveLine() : Player() {
    this->rushing = 0;
}

// Parameterized constructor
DefensiveLine::DefensiveLine(std::string name, int speed, int strength, int skill, int rushing)
    : Player(name, speed, strength, skill) {
    this->rushing = rushing;
}

// Destructor
DefensiveLine::~DefensiveLine() {}

void DefensiveLine::printStats() const {
    std::cout << "Name: " << this->name << "\n" <<
        "Speed: " << this->speed << "\n" <<
        "Strength: " << this->strength << "\n" <<
        "Skill: " << this->skill << "\n" <<
        "Rushing: " << this->rushing << "\n";
}