#include "player.h"

// Default constructor
Player::Player() {
    this->name = "undefined_player_name";
    this->speed = 0;
    this->strength = 0;
    this->skill = 0;
}

// Parameterized constructor
Player::Player(std::string name, int speed, int strength, int skill) {
    this->name = name;
    this->speed = speed;
    this->strength = strength;
    this->skill = skill;
}

// Destructor
Player::~Player() {}

void Player::printStats() const {
    std::cout << "Name: " << this->name << "\n" <<
        "Speed: " << this->speed << "\n" <<
        "Strength: " << this->strength << "\n" <<
        "Skill: " << this->skill << "\n";
}