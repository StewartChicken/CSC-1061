#pragma once
#ifndef WR_H
#define WR_H

#include <iostream>
#include "player.h"

class WideReceiver : public Player {
private:
    int catching;

public:
    // Constructors/destructor
    WideReceiver();
    WideReceiver(std::string name, int speed, int strength, int skill, int catching);
    ~WideReceiver();

    // Accessors
    int getCatching() const { return catching; }

    // Mutators
    void setCatching(int catching) { this->catching = catching; }

    void printStats() const override;

};

#endif