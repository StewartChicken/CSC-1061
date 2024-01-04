#pragma once
/*
 * This class will contain the data and information of each of the players that can be selected within the game.
 * This class will only contain the information of the players, not any actual player objects themselves.
 * The data will be stored in a set of arrays, each of which contains all the players of a specific type.
 * Each player within each array will be represented with a struct that contains his information. The struct
 *  will also contain a variable called "selected" which indicates whether or not the player is already on a team.
*/
#ifndef players_h
#define players_h

#include <iostream>
#include <unordered_map>
#include <string>

#include "PlayerStructs.h"

class Players {

private:

    // Array of random player names
    std::string firstNames[50];
    std::string lastNames[50];

    QB quarterbacks[3];
    RB runningbacks[3];
    K kickers[3];
    WR wideReceivers[6];
    OL offensiveLinebackers[7];
    DL defensiveLinebackers[6];
    MLB middleLinebackers[4];
    DB defensivebacks[7];

    // Array which holds the 8 player type abbreviations
    const std::string playerTypes[8] = { "QB", "RB", "K", "WR", "OL", "DL", "MLB", "DB" };

    // Hashmap which stores the number of each type of player that exists
    std::unordered_map<std::string, int> playerNumbers;

public:

    // Constructor
    Players();

    // Destructor
    ~Players();

    // Loads player names into array from txt file
    void loadPlayerNames();
    void assignPlayerNames();

    // Randomly generate ratings for player attributes
    int generateRating();

    // Assign randomly generated ratings for each player attribute - deactivates all players
    void assignAttributes();

    // Get a random index for player selection based on the type of player entered
    int getRandomPlayerIndex(std::string type) const;
    
    // Get random index for NPC player selection
    int getRandomNPCIndex(std::string type) const;

    // Get random players from available players
    // If npc = true, does not check whether or not a 
    //  sselected player is active before returning an index
    QB getRandomQuarterback(const bool &npc);
    RB getRandomRunningback(const bool& npc);
    K getRandomKicker(const bool& npc);
    WR getRandomWideReceiver(const bool& npc);
    OL getRandomOffensiveLine(const bool& npc);
    DL getRandomDefensiveLine(const bool& npc);
    MLB getRandomMiddleLine(const bool& npc);
    DB getRandomDefensiveBack(const bool& npc);

    // Get specific position data given an index (1-6). 
    QB getQuarterbackStats(int index);
    RB getRunningbackStats(int index);
    K getKickerStats(int index);
    WR getWideReceiverStats(int index);
    OL getOffensiveLineStats(int index);
    DL getDefensiveLineStats(int index);
    MLB getMiddleLineStats(int index);
    DB getDefensivebackStats(int index);

    // Prints players within positions functions
    void printQuarterbacks() const;
    void printRunningbacks() const;
    void printKickers() const;
    void printWideReceivers() const;
    void printOffensiveLinebackers() const;
    void printDefensiveLinebackers() const;
    void printMiddleLinebackers() const;
    void printDefensivebacks() const;

    // Deactivates player types
    void activateQuarterback(int index);
    void activateRunningback(int index);
    void activateKicker(int index);
    void activateWideReceiver(int index);
    void activateOffensiveLine(int index);
    void activateDefensiveLine(int index);
    void activateMiddleLine(int index);
    void activateDefensiveback(int index);

    // Checks if a given string is one of the player types
    bool isPlayerType(std::string string) const;

    // Checks for equality of two strings
    bool compareStrings(std::string a, std::string b)const;

};

#endif