#include "wideReceiver.h"

// Constructor
WideReceiver::WideReceiver() : Player() {
    this->catching = 0;
}

// Parameterized constructor
WideReceiver::WideReceiver(std::string name, int speed, int strength, int skill, int catching)
    : Player(name, speed, strength, skill) {
    this->catching = catching;
}

// Destructor
WideReceiver::~WideReceiver() {}

void WideReceiver::printStats() const {
    std::cout << "Name: " << this->name << "\n" <<
        "Speed: " << this->speed << "\n" <<
        "Strength: " << this->strength << "\n" <<
        "Skill: " << this->skill << "\n" <<
        "Catching: " << this->catching << "\n";
}