
#include <fstream>
#include <cassert>
#include <string>
#include <iostream>
#include <algorithm>
#include <random>
#include <unordered_map>
#include "players.h"

// Constructor definition
Players::Players() {

    // Assigns names to each of the players
    loadPlayerNames();
    assignPlayerNames();

    // Assigns ratings to each of the players' attributes. Also deactivates all players
    assignAttributes();

    // Number of each player type that the user can choose from
    playerNumbers["QB"] = 3;
    playerNumbers["RB"] = 3;
    playerNumbers["K"] = 3;
    playerNumbers["WR"] = 6;
    playerNumbers["OL"] = 7;
    playerNumbers["DL"] = 6;
    playerNumbers["MLB"] = 4;
    playerNumbers["DB"] = 7;
}

// Destructor definition
Players::~Players() {}

// Load names from text file
void Players::loadPlayerNames() {

    // Load files for random names
    std::ifstream firstNamesFile("firstNames.txt");
    std::ifstream lastNamesFile("lastNames.txt");


    if (!firstNamesFile) {
        std::cout << "Failed to open first names file.\n";
        assert(false);
    }

    if (!lastNamesFile) {
        std::cout << "Failed to open last names file.\n";
        assert(false);
    }

    std::string line;

    int i = 0;

    while (std::getline(firstNamesFile, line) && i < 50) {
        firstNames[i] = line;
        i++;
    }

    i = 0;

    while (std::getline(lastNamesFile, line) && i < 50) {
        lastNames[i] = line;
        i++;
    }

}

// Assign loaded names to array of player names - shuffles loaded names prior to assignment
void Players::assignPlayerNames() {

    // Random number generator
    std::random_device rand;
    std::mt19937 generator(rand());

    // Shuffle names
    std::shuffle(firstNames, firstNames + 50, generator);
    std::shuffle(lastNames, lastNames + 50, generator);

    // Assign quarterback names
    for (int i{}; i < 3; i++) {
        quarterbacks[i].name = firstNames[i] + " " + lastNames[i];
    }

    // Assign runningback names
    for (int i{}; i < 3; i++) {
        runningbacks[i].name = firstNames[i + 3] + " " + lastNames[i + 3];
    }

    // Assign kicker names
    for (int i{}; i < 3; i++) {
        kickers[i].name = firstNames[i + 6] + " " + lastNames[i + 6];
    }

    // Assign wide receiver names
    for (int i{}; i < 6; i++) {
        wideReceivers[i].name = firstNames[i + 9] + " " + lastNames[i + 9];
    }

    // Assign offensive line names
    for (int i{}; i < 7; i++) {
        offensiveLinebackers[i].name = firstNames[i + 15] + " " + lastNames[i + 15];
    }

    // Assign defensive line names
    for (int i{}; i < 6; i++) {
        defensiveLinebackers[i].name = firstNames[i + 21] + " " + lastNames[i + 21];
    }

    // Assign middle line names
    for (int i{}; i < 4; i++) {
        middleLinebackers[i].name = firstNames[i + 27] + " " + lastNames[i + 27];
    }

    // Assign defensiveback names
    for (int i{}; i < 7; i++) {
        defensivebacks[i].name = firstNames[i + 31] + " " + lastNames[i + 31];
    }
}

// Generate ratings for players
// Ratings will be weighted towards higher ratings (mid 80's to high 90's)
// Ratings below 70 will be very rare. 
// Will use a normal distribution algorith for this 
//     - mean rating will be 86 with a standard deviation of 5
// Minimum rating is 65. Max is 99
int Players::generateRating() {

    // Random number generator
    std::random_device rand;
    std::mt19937 generator(rand());

    // Normal distribution
    std::normal_distribution<float> nDistribution(60.0, 20);

    // Generates rating with nDistribution
    double rating = nDistribution(generator);

    // Truncates decimal portion
    int roundedRating = static_cast<int>(rating);

    // Set max and min values for rating
    if (roundedRating < 30) {
        roundedRating = 30;
    }

    if (roundedRating > 99) {
        roundedRating = 99;
    }

    return roundedRating;

}

// Generates ratings for each player and their attributes
void Players::assignAttributes() {

    for (int i = 0; i < 3; i++) {
        quarterbacks[i].speed = generateRating();
        quarterbacks[i].strength = generateRating();
        quarterbacks[i].skill = generateRating();
        quarterbacks[i].throwing = generateRating();
        quarterbacks[i].active = false;
    }

    for (int i = 0; i < 3; i++) {
        runningbacks[i].speed = generateRating();
        runningbacks[i].strength = generateRating();
        runningbacks[i].skill = generateRating();
        runningbacks[i].elusiveness = generateRating();
        runningbacks[i].active = false;
    }

    for (int i = 0; i < 3; i++) {
        kickers[i].speed = generateRating();
        kickers[i].strength = generateRating();
        kickers[i].skill = generateRating();
        kickers[i].kicking = generateRating();
        kickers[i].active = false;
    }

    for (int i = 0; i < 6; i++) {
        wideReceivers[i].speed = generateRating();
        wideReceivers[i].strength = generateRating();
        wideReceivers[i].skill = generateRating();
        wideReceivers[i].catching = generateRating();
        wideReceivers[i].active = false;
    }

    for (int i = 0; i < 7; i++) {
        offensiveLinebackers[i].speed = generateRating();
        offensiveLinebackers[i].strength = generateRating();
        offensiveLinebackers[i].skill = generateRating();
        offensiveLinebackers[i].blocking = generateRating();
        offensiveLinebackers[i].active = false;
    }

    for (int i = 0; i < 6; i++) {
        defensiveLinebackers[i].speed = generateRating();
        defensiveLinebackers[i].strength = generateRating();
        defensiveLinebackers[i].skill = generateRating();
        defensiveLinebackers[i].rushing = generateRating();
        defensiveLinebackers[i].active = false;
    }

    for (int i = 0; i < 4; i++) {
        middleLinebackers[i].speed = generateRating();
        middleLinebackers[i].strength = generateRating();
        middleLinebackers[i].skill = generateRating();
        middleLinebackers[i].rushing = generateRating();
        middleLinebackers[i].coverage = generateRating();
        middleLinebackers[i].active = false;
    }

    for (int i = 0; i < 7; i++) {
        defensivebacks[i].speed = generateRating();
        defensivebacks[i].strength = generateRating();
        defensivebacks[i].skill = generateRating();
        defensivebacks[i].coverage = generateRating();
        defensivebacks[i].active = false;
    }

}

// Types are 
// QB
// RB
// K
// WR
// OL
// DL
// MLB
// DB

int Players::getRandomPlayerIndex(std::string type) const {

    // Checks for valid type argument
    if (!isPlayerType(type)){
        std::cout << "Invalid player type requested - getRandomPlayerIndex\n";
        
        // Error code
        return -1;
    }


    // Number of players of type 'type'
    const int size = playerNumbers.at(type);

    // Random number generator
    std::random_device rand;
    std::mt19937 generator(rand());

    std::uniform_int_distribution<int> numberDistribution(0, size - 1);

    // Has a non-active player been found
    bool found = false;

    int randNum;


    // Infinite loop check - have all quarterbacks been checked?
    // (This should never be needed but it's precautionary)
    int iterations = 0;

    while (!found) {

        //std::cout << iterations << " " << size << std::endl;

        if (iterations == size) {
            //Throw error/terminate program
            std::cout << "Error - Players::getRandomPlayerIndex() - exceed max iterations\n";
            assert(false);
        }

        randNum = numberDistribution(generator);

        if (quarterbacks[randNum].active == false) {
            return randNum;
        }

        iterations++;
        
    }
    
}

// Gets random index for NPC player selections - does not check for player
//  activity because NPC's only need the overall ratings
int Players::getRandomNPCIndex(std::string type) const {
    
    // Checks for valid type argument
    if (!isPlayerType(type)) {
        std::cout << "Invalid player type requested - getRandomPlayerIndex\n";

        // Error code
        return -1;
    }


    // Number of players of type 'type'
    const int size = playerNumbers.at(type);

    // Random number generator
    std::random_device rand;
    std::mt19937 generator(rand());

    std::uniform_int_distribution<int> numberDistribution(0, size - 1);

    int randNum = numberDistribution(generator);

    return randNum;
}

// Get random players from available

QB Players::getRandomQuarterback(const bool& npc) {

    // Get index to be selected
    int index;

    if (!npc) {
        index = getRandomPlayerIndex("QB");
    }
    else {
        index = getRandomNPCIndex("QB");
    }
    
    quarterbacks[index].active = true;

    return quarterbacks[index];
}

RB Players::getRandomRunningback(const bool& npc) {
    
    // Get index to be selected
    int index;

    if (!npc) {
        index = getRandomPlayerIndex("RB");
    }
    else {
        index = getRandomNPCIndex("RB");
    }

    runningbacks[index].active = true;

    return runningbacks[index];
}

K Players::getRandomKicker(const bool& npc) {

    // Get index to be selected
    int index;

    if (!npc) {
        index = getRandomPlayerIndex("K");
    }
    else {
        index = getRandomNPCIndex("K");
    }

    kickers[index].active = true;

    return kickers[index];
}

WR Players::getRandomWideReceiver(const bool& npc) {
    
    // Get index to be selected
    int index;

    if (!npc) {
        index = getRandomPlayerIndex("WR");
    }
    else {
        index = getRandomNPCIndex("WR");
    }

    wideReceivers[index].active = true;

    return wideReceivers[index];
}

OL Players::getRandomOffensiveLine(const bool& npc) {
    
    // Get index to be selected
    int index;

    if (!npc) {
        index = getRandomPlayerIndex("OL");
    }
    else {
        index = getRandomNPCIndex("OL");
    }

    offensiveLinebackers[index].active = true;

    return offensiveLinebackers[index];
}

DL Players::getRandomDefensiveLine(const bool& npc) {
    
    // Get index to be selected
    int index;

    if (!npc) {
        index = getRandomPlayerIndex("DL");
    }
    else {
        index = getRandomNPCIndex("DL");
    }

    defensiveLinebackers[index].active = true;

    return defensiveLinebackers[index];
}

MLB Players::getRandomMiddleLine(const bool& npc) {
    
    // Get index to be selected
    int index;

    if (!npc) {
        index = getRandomPlayerIndex("MLB");
    }
    else {
        index = getRandomNPCIndex("MLB");
    }

    middleLinebackers[index].active = true;

    return middleLinebackers[index];
}

DB Players::getRandomDefensiveBack(const bool& npc) {
    
    // Get index to be selected
    int index;

    if (!npc) {
        index = getRandomPlayerIndex("DB");
    }
    else {
        index = getRandomNPCIndex("DB");
    }

    defensivebacks[index].active = true;

    return defensivebacks[index];
}

QB Players::getQuarterbackStats(int index) {
    return quarterbacks[index - 1];
}

RB Players::getRunningbackStats(int index) {
    return runningbacks[index - 1];
}

K Players::getKickerStats(int index) {
    return kickers[index - 1];
}

WR Players::getWideReceiverStats(int index) {
    return wideReceivers[index - 1];
}

OL Players::getOffensiveLineStats(int index) {
    return offensiveLinebackers[index - 1];
}

DL Players::getDefensiveLineStats(int index) {
    return defensiveLinebackers[index - 1];
}

MLB Players::getMiddleLineStats(int index) {
    return middleLinebackers[index - 1];
}

DB Players::getDefensivebackStats(int index) {
    return defensivebacks[index - 1];
}

void Players::printQuarterbacks() const {
    
    std::cout << "\nQUARTERBACKS\n\n";

    // Which use choice corresponds with the current player being printed
    int userChoice = 1;

    for(int i{}; i < 3; i++) {
        
        // If quarterback has already been chosen
        if (quarterbacks[i].active) {
            continue;
        }

        // Prints option for user input
        std::cout << userChoice << ").\n";

        std::cout << "Name: " << quarterbacks[i].name << "\n";
        std::cout << "Speed: " << quarterbacks[i].speed << "\n";
        std::cout << "Strength: " << quarterbacks[i].strength << "\n";
        std::cout << "Skill: " << quarterbacks[i].skill << "\n";
        std::cout << "Throwing: " << quarterbacks[i].throwing << "\n\n";

        userChoice++;
    }
}

void Players::printRunningbacks() const {

    std::cout << "\nRunningbacks\n\n";

    // Which use choice corresponds with the current player being printed
    int userChoice = 1;

    for (int i{}; i < 3; i++) {

        if (runningbacks[i].active) {
            continue;
        }

        // Prints option for user input
        std::cout << userChoice << ").\n";

        std::cout << "Name: " << runningbacks[i].name << "\n";
        std::cout << "Speed: " << runningbacks[i].speed << "\n";
        std::cout << "Strength: " << runningbacks[i].strength << "\n";
        std::cout << "Skill: " << runningbacks[i].skill << "\n";
        std::cout << "Elusiveness: " << runningbacks[i].elusiveness << "\n\n";

        userChoice++;
    }
}

void Players::printKickers() const {

    std::cout << "\nKickers\n\n";

    // Which use choice corresponds with the current player being printed
    int userChoice = 1;

    for (int i{}; i < 3; i++) {

        if (kickers[i].active) {
            continue;
        }

        // Print option for user input
        std::cout << userChoice << ").\n";

        std::cout << "Name: " << kickers[i].name << "\n";
        std::cout << "Speed: " << kickers[i].speed << "\n";
        std::cout << "Strength: " << kickers[i].strength << "\n";
        std::cout << "Skill: " << kickers[i].skill << "\n";
        std::cout << "Kicking: " << kickers[i].kicking << "\n\n";

        userChoice++;
    }
}

void Players::printWideReceivers() const {

    std::cout << "\nWide Receivers\n\n";

    // Which use choice corresponds with the current player being printed
    int userChoice = 1;

    for (int i{}; i < 6; i++) {

        if (wideReceivers[i].active) {
            continue;
        }

        // Print option for user input
        std::cout << userChoice << ").\n";

        std::cout << "Name: " << wideReceivers[i].name << "\n";
        std::cout << "Speed: " << wideReceivers[i].speed << "\n";
        std::cout << "Strength: " << wideReceivers[i].strength << "\n";
        std::cout << "Skill: " << wideReceivers[i].skill << "\n";
        std::cout << "Catching: " << wideReceivers[i].catching << "\n\n";

        userChoice++;
    }
}

void Players::printOffensiveLinebackers() const {

    std::cout << "\nOffensive Linebackers\n\n";

    // Which use choice corresponds with the current player being printed
    int userChoice = 1;

    for (int i{}; i < 7; i++) {

        if (offensiveLinebackers[i].active) {
            continue;
        }

        // Print option for user input
        std::cout << userChoice << ").\n";

        std::cout << "Name: " << offensiveLinebackers[i].name << "\n";
        std::cout << "Speed: " << offensiveLinebackers[i].speed << "\n";
        std::cout << "Strength: " << offensiveLinebackers[i].strength << "\n";
        std::cout << "Skill: " << offensiveLinebackers[i].skill << "\n";
        std::cout << "Blocking: " << offensiveLinebackers[i].blocking << "\n\n";

        userChoice++;
    }
}

void Players::printDefensiveLinebackers() const {

    std::cout << "\nDefensive Linebackers\n\n";

    // Which use choice corresponds with the current player being printed
    int userChoice = 1;

    for (int i{}; i < 6; i++) {

        if (defensiveLinebackers[i].active) {
            continue;
        }

        // Print option for user input
        std::cout << userChoice << ").\n";

        std::cout << "Name: " << defensiveLinebackers[i].name << "\n";
        std::cout << "Speed: " << defensiveLinebackers[i].speed << "\n";
        std::cout << "Strength: " << defensiveLinebackers[i].strength << "\n";
        std::cout << "Skill: " << defensiveLinebackers[i].skill << "\n";
        std::cout << "Rushing: " << defensiveLinebackers[i].rushing << "\n\n";

        userChoice++;
    }
}

void Players::printMiddleLinebackers() const {

    std::cout << "\nMiddle Linebackers\n\n";

    // Which use choice corresponds with the current player being printed
    int userChoice = 1;

    for (int i{}; i < 4; i++) {

        if (middleLinebackers[i].active) {
            continue;
        }

        // Print option for user input
        std::cout << userChoice << ").\n";

        std::cout << "Name: " << middleLinebackers[i].name << "\n";
        std::cout << "Speed: " << middleLinebackers[i].speed << "\n";
        std::cout << "Strength: " << middleLinebackers[i].strength << "\n";
        std::cout << "Skill: " << middleLinebackers[i].skill << "\n";
        std::cout << "Rushing: " << middleLinebackers[i].rushing << "\n";
        std::cout << "Coverage: " << middleLinebackers[i].coverage << "\n\n";

        userChoice++;
    }
}

void Players::printDefensivebacks() const {

    std::cout << "\nDefensivebacks\n\n";

    // Which use choice corresponds with the current player being printed
    int userChoice = 1;

    for (int i{}; i < 7; i++) {

        if (defensivebacks[i].active) {
            continue;
        }

        // Print option for user input
        std::cout << userChoice << ").\n";

        std::cout << "Name: " << defensivebacks[i].name << "\n";
        std::cout << "Speed: " << defensivebacks[i].speed << "\n";
        std::cout << "Strength: " << defensivebacks[i].strength << "\n";
        std::cout << "Skill: " << defensivebacks[i].skill << "\n";
        std::cout << "Coverage: " << defensivebacks[i].coverage << "\n\n";

        userChoice++;
    }
}


// Deactivate specific players (this means that they are in use by the player)
void Players::activateQuarterback(int index) {
    quarterbacks[index - 1].active = true;
}

void Players::activateRunningback(int index) {
    runningbacks[index - 1].active = true;
}

void Players::activateKicker(int index) {
    kickers[index - 1].active = true;
}

void Players::activateWideReceiver(int index) {
    wideReceivers[index - 1].active = true;
}

void Players::activateOffensiveLine(int index) {
    offensiveLinebackers[index - 1].active = true;
}

void Players::activateDefensiveLine(int index) {
    defensiveLinebackers[index - 1].active = true;
}

void Players::activateMiddleLine(int index) {
    middleLinebackers[index - 1].active = true;
}

void Players::activateDefensiveback(int index) {
    defensivebacks[index - 1].active = true;
}

// Checks if a given string is one of the 8 player types defined in the header file
bool Players::isPlayerType(std::string string) const {
    for (int i{}; i < 8; i++) {
        if (compareStrings(string, playerTypes[i])) {
            return true;
        }
    }

    return false;
}

// Checks for equality between two strings
bool Players::compareStrings(std::string a, std::string b) const {
    if (a.length() != b.length()) {
        return false;
    }

    for (int i{}; i < a.length(); i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }

    return true;
}
