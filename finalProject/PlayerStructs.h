#ifndef PLAYER_STRUCTS_H
#define PLAYER_STRUCTS_H

#include <iostream>

// Football position struct declarations

struct QB {
    std::string name;
    int speed;
    int strength;
    int skill;
    int throwing;

    // Is player actively on a team's roster
    bool active;
};

struct WR {
    std::string name;
    int speed;
    int strength;
    int skill;
    int catching;
    bool active;
};

struct RB {
    std::string name;
    int speed;
    int strength;
    int skill;
    int elusiveness;
    bool active;
};

struct OL {
    std::string name;
    int speed;
    int strength;
    int skill;
    int blocking;
    bool active;
};

struct MLB {
    std::string name;
    int speed;
    int strength;
    int skill;
    int rushing;
    int coverage;
    bool active;
};

struct K {
    std::string name;
    int speed;
    int strength;
    int skill;
    int kicking;
    bool active;
};

struct DL {
    std::string name;
    int speed;
    int strength;
    int skill;
    int rushing;
    bool active;
};

struct DB {
    std::string name;
    int speed;
    int strength;
    int skill;
    int coverage;
    bool active;
};


#endif