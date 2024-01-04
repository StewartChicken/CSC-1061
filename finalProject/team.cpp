
#include "team.h"

// Player classes
#include "player.h"
#include "wideReceiver.h"
#include "runningback.h"
#include "quarterback.h"
#include "offensiveLine.h"
#include "middleLinebacker.h"
#include "kicker.h"
#include "defensiveLine.h"
#include "defensiveBack.h"

// Constructor
Team::Team() {

    // Creating team structure within the array
    // The array is an array of Player objects. Polymorphism is
    //  used to place derived classes into the array.

    teamMembers[0] = new Quarterback();
    teamMembers[1] = new Runningback();
    teamMembers[2] = new Kicker();

    teamMembers[3] = new WideReceiver();
    teamMembers[4] = new WideReceiver();
    teamMembers[5] = new WideReceiver();

    teamMembers[6] = new OffensiveLine();
    teamMembers[7] = new OffensiveLine();
    teamMembers[8] = new OffensiveLine();
    teamMembers[9] = new OffensiveLine();

    teamMembers[10] = new DefensiveLine();
    teamMembers[11] = new DefensiveLine();
    teamMembers[12] = new DefensiveLine();

    teamMembers[13] = new MiddleLine();
    teamMembers[14] = new MiddleLine();

    teamMembers[15] = new DefensiveBack();
    teamMembers[16] = new DefensiveBack();
    teamMembers[17] = new DefensiveBack();
    teamMembers[18] = new DefensiveBack();

    // Initially, no games have been won
    score = 0;

}

// Destructor
Team::~Team() {

    // Delete dynamically allocated elements of teamMembers array
    for (int i{}; i < 19; i++) {
        delete teamMembers[i];
    }
}

// Player getter methods

Quarterback* Team::getQuarterback() const {
    // Down cast from Player pointer to Quarterback pointer 
    //  and return pointer to Quarterback object
    return dynamic_cast<Quarterback*>(teamMembers[0]);
}

Runningback* Team::getRunningback() const {
    return dynamic_cast<Runningback*>(teamMembers[1]);
}

Kicker* Team::getKicker() const {
    return dynamic_cast<Kicker*>(teamMembers[2]);
}

// Can be indexed from 0 - 2
WideReceiver* Team::getWideReceiver(int index) const {
    return dynamic_cast<WideReceiver*>(teamMembers[3 + index]);
}

// Can be indexed from 0 - 3
OffensiveLine* Team::getOffensiveLine(int index) const {
    return dynamic_cast<OffensiveLine*>(teamMembers[6 + index]);
}

// Can be indexed from 0 - 2
DefensiveLine* Team::getDefenseiveLine(int index) const {
    return dynamic_cast<DefensiveLine*>(teamMembers[10 + index]);
}

// Can be indexed from 0 - 1
MiddleLine* Team::getMiddleLine(int index) const {
    return dynamic_cast<MiddleLine*>(teamMembers[13 + index]);
}

// Can be indexed from 0 - 3
DefensiveBack* Team::getDefensiveback(int index) const {
    return dynamic_cast<DefensiveBack*>(teamMembers[15 + index]);
}

// Adder methods - TODO
void Team::addQuarterback(const Quarterback &quarterback) {
    if (getQuarterback()->getName() == "undefined_player_name") {
        

        /*
         * In order to properly assign the values fo the "quarterback" argument
         * to the values of the player within the teamMembers array, we need to
         * downcast that specific element to a Quarterback object. Initially,
         * that element is identified as a "Player" object, so any data values held
         * specifically by the Quarterback object will not be copied over.
         * To down cast to a Quarterback object, we use the dynamic_cast operator
         * to convert the value at teamMembers[0] from a pointer to a Player object
         * to a pointer to a Quarterback object. We then dereference this pointer
         * using the '*' operator and assign the 'quarterback' argument's values to
         * the dereference object.
        */

        *(dynamic_cast<Quarterback*>(teamMembers[0])) = quarterback;
    }
    else {
        std::cout << "Quarterback position filled\n";
        
    }
}

void Team::addRunningback(const Runningback &runningback) {
    if (getRunningback()->getName() == "undefined_player_name") {
        *(dynamic_cast<Runningback*>(teamMembers[1])) = runningback;
    }
    else {
        std::cout << "Runningback position filled\n";
    }
}

void Team::addWideReceiver(const WideReceiver &wideReceiver) {
    if (getWideReceiver(0)->getName() == "undefined_player_name") {
        *(dynamic_cast<WideReceiver*>(teamMembers[3])) = wideReceiver;
    }
    else if (getWideReceiver(1)->getName() == "undefined_player_name") {
        *(dynamic_cast<WideReceiver*>(teamMembers[4])) = wideReceiver;
    }
    else if (getWideReceiver(2)->getName() == "undefined_player_name") {
        *(dynamic_cast<WideReceiver*>(teamMembers[5])) = wideReceiver;
    }
    else {
        std::cout << "Wide Receiver position filled\n";
    }
}

void Team::addOffensiveLine(const OffensiveLine &offensiveLine) {
    if (getOffensiveLine(0)->getName() == "undefined_player_name") {
        *(dynamic_cast<OffensiveLine*>(teamMembers[6])) = offensiveLine;
    }
    else if (getOffensiveLine(1)->getName() == "undefined_player_name") {
        *(dynamic_cast<OffensiveLine*>(teamMembers[7])) = offensiveLine;
    }
    else if (getOffensiveLine(2)->getName() == "undefined_player_name") {
        *(dynamic_cast<OffensiveLine*>(teamMembers[8])) = offensiveLine;
    }
    else if (getOffensiveLine(3)->getName() == "undefined_player_name") {
        *(dynamic_cast<OffensiveLine*>(teamMembers[9])) = offensiveLine;
    }
    else {
        std::cout << "Offensive Line position filled\n";
    }
}

void Team::addDefensiveback(const DefensiveBack &defensiveback) {
    if (getDefensiveback(0)->getName() == "undefined_player_name") {
        *(dynamic_cast<DefensiveBack*>(teamMembers[15])) = defensiveback;
    }
    else if (getDefensiveback(1)->getName() == "undefined_player_name") {
        *(dynamic_cast<DefensiveBack*>(teamMembers[16])) = defensiveback;
    }
    else if (getDefensiveback(2)->getName() == "undefined_player_name") {
        *(dynamic_cast<DefensiveBack*>(teamMembers[17])) = defensiveback;
    }
    else if (getDefensiveback(3)->getName() == "undefined_player_name") {
        *(dynamic_cast<DefensiveBack*>(teamMembers[18])) = defensiveback;
    }
    else {
        std::cout << "Defensive Back position filled\n";
    }
}

void Team::addDefensiveLine(const DefensiveLine &defensiveLine) {
    if (getDefenseiveLine(0)->getName() == "undefined_player_name") {
        *(dynamic_cast<DefensiveLine*>(teamMembers[10])) = defensiveLine;
    }
    else if (getDefenseiveLine(1)->getName() == "undefined_player_name") {
        *(dynamic_cast<DefensiveLine*>(teamMembers[11])) = defensiveLine;
    }
    else if (getDefenseiveLine(2)->getName() == "undefined_player_name") {
        *(dynamic_cast<DefensiveLine*>(teamMembers[12])) = defensiveLine;
    }
    else {
        std::cout << "Defensive Line position filled\n";
    }
}

void Team::addMiddleLine(const MiddleLine &middleLine) {
    if (getMiddleLine(0)->getName() == "undefined_player_name") {
        *(dynamic_cast<MiddleLine*>(teamMembers[13])) = middleLine;
    }
    else if (getMiddleLine(1)->getName() == "undefined_player_name") {
        *(dynamic_cast<MiddleLine*>(teamMembers[14])) = middleLine;
    }
    else {
        std::cout << "Middle Line position filled\n";
    }
}

void Team::addKicker(const Kicker &kicker) {
    if (getKicker()->getName() == "undefined_player_name") {
        *(dynamic_cast<Kicker*>(teamMembers[2])) = kicker;
    }
    else {
        std::cout << "Kicker position filled\n";
    }
}

double Team::calculateAverageStrength() const {
    double sum = 0;

    for (int i{}; i < 19; i++) {
        sum += static_cast<double>(teamMembers[i]->getStrength());
    }

    return sum / 19.0;
}

double Team::calculateAverageSpeed() const {
    double sum = 0;

    for (int i{}; i < 19; i++) {
        sum += static_cast<double>(teamMembers[i]->getSpeed());
    }

    return sum / 19.0;
}

double Team::calculateAverageSkill() const {
    double sum = 0;

    for (int i{}; i < 19; i++) {
        sum += static_cast<double>(teamMembers[i]->getSkill());
    }

    return sum / 19.0;
}

double Team::calculateThrowing() const {
    Quarterback* qbPtr = dynamic_cast<Quarterback*>(teamMembers[0]);
    return static_cast<double>(qbPtr->getThrowing());
}

double Team::calculateElusiveness() const {
    Runningback* rbPtr = dynamic_cast<Runningback*>(teamMembers[1]);
    return static_cast<double>(rbPtr->getElusiveness());
}

double Team::calculateAverageCatching() const {
    double sum = 0;

    for (int i{ 3 }; i < 6; i++) {
        WideReceiver* wrPtr = dynamic_cast<WideReceiver*>(teamMembers[i]);
        sum += wrPtr->getCatching();
    }

    return sum / 3.0;
}

double Team::calculateKicking() const {
    Kicker* kPtr = dynamic_cast<Kicker*>(teamMembers[2]);
    return static_cast<double>(kPtr->getKicking());
}

double Team::calculateAverageCoverage() const {
    double sum = 0;

    for (int i{ 15 }; i < 19; i++) {
        DefensiveBack* dbPtr = dynamic_cast<DefensiveBack*>(teamMembers[i]);
        sum += dbPtr->getCoverage();
    }

    for (int i{ 13 }; i < 15; i++) {
        MiddleLine* mlPtr = dynamic_cast<MiddleLine*>(teamMembers[i]);
        sum += mlPtr->getCoverage();
    }

    return sum / 6.0;
}

double Team::calculateAverageRushing() const {
    double sum = 0;

    for (int i{ 10 }; i < 13; i++) {
        DefensiveLine* dlPtr = dynamic_cast<DefensiveLine*>(teamMembers[i]);
        sum += dlPtr->getRushing();
    }

    for (int i{ 13 }; i < 15; i++) {
        MiddleLine* mlPtr = dynamic_cast<MiddleLine*>(teamMembers[i]);
        sum += mlPtr->getRushing();
    }

    return sum / 5.0;

}

double Team::calculateAverageBlocking() const {
    double sum = 0;

    for (int i{ 6 }; i < 10; i++) {
        OffensiveLine* olPtr = dynamic_cast<OffensiveLine*>(teamMembers[i]);
        sum += olPtr->getBlocking();
    }

    return sum / 4.0;

}

// Set all team attributes
void Team::calculateBaseStats() {

    setTeamStrength(calculateAverageStrength());
    setTeamSpeed(calculateAverageSpeed());
    setTeamSkill(calculateAverageSkill());
    setThrowing(calculateThrowing());
    setElusiveness(calculateElusiveness());
    setCatching(calculateAverageCatching());
    setKicking(calculateKicking());
    setRushing(calculateAverageRushing());
    setBlocking(calculateAverageBlocking());
    setCoverage(calculateAverageCoverage());

}

void Team::calculateFieldGoalChance() {
    fieldGoalChance = (kicking + blocking + rushing + teamSpeed + teamSkill + teamStrength) / 600.0;
}

void Team::calculateTouchDownChance() {
    touchDownChance = (throwing + catching + coverage + elusiveness +
        teamSpeed + teamSkill + teamStrength) / 700.0;
}

void Team::calculateExtraPointChance() {
    extraPointChance = kicking / 100.0;
}

void Team::calculateAllStats() {
    calculateBaseStats();
    calculateFieldGoalChance();
    calculateTouchDownChance();
    calculateExtraPointChance();
}

// Prints all team attributes - used for debugging
void Team::printStats() const {
    std::cout << "Team Strength: " << teamStrength << "\n" <<
        "Team Speed: " << teamSpeed << "\n" <<
        "Team Skill: " << teamSkill << "\n" <<
        "Throwing: " << throwing << "\n" <<
        "Elusiveness: " << elusiveness << "\n" <<
        "Catching: " << catching << "\n" <<
        "Kicking: " << kicking << "\n" <<
        "Rushing: " << rushing << "\n" <<
        "Blocking: " << blocking << "\n" <<
        "Coverage: " << coverage << "\n" <<
        "Field Goal Chance: " << fieldGoalChance << "\n" <<
        "Touch Down Chance: " << touchDownChance << "\n" <<
        "ExtraPointChance: " << extraPointChance << "\n";
}

// Prints all team member names and positions
void Team::printTeamMemberNames() const {
    std::cout << "Quarterback: " << getQuarterback()->getName() << std::endl;
    std::cout << "Runningback: " << getRunningback()->getName() << std::endl;
    std::cout << "Kicker: " << getKicker()->getName() << std::endl;
    std::cout << "Wide Receiver: " << getWideReceiver(0)->getName() << std::endl;
    std::cout << "Wide Receiver: " << getWideReceiver(1)->getName() << std::endl;
    std::cout << "Wide Receiver: " << getWideReceiver(2)->getName() << std::endl;
    std::cout << "Offensive Line: " << getOffensiveLine(0)->getName() << std::endl;
    std::cout << "Offensive Line: " << getOffensiveLine(1)->getName() << std::endl;
    std::cout << "Offensive Line: " << getOffensiveLine(2)->getName() << std::endl;
    std::cout << "Offensive Line: " << getOffensiveLine(3)->getName() << std::endl;
    std::cout << "Defensive Line: " << getDefenseiveLine(0)->getName() << std::endl;
    std::cout << "Defensive Line: " << getDefenseiveLine(1)->getName() << std::endl;
    std::cout << "Defensive Line: " << getDefenseiveLine(2)->getName() << std::endl;
    std::cout << "Middle Line: " << getMiddleLine(0)->getName() << std::endl;
    std::cout << "Middle Line: " << getMiddleLine(1)->getName() << std::endl;
    std::cout << "Defensive Back: " << getDefensiveback(0)->getName() << std::endl;
    std::cout << "Defensive Back: " << getDefensiveback(1)->getName() << std::endl;
    std::cout << "Defensive Back: " << getDefensiveback(2)->getName() << std::endl;
    std::cout << "Defensive Back: " << getDefensiveback(3)->getName() << std::endl;

}

// Create random instances of players

Quarterback Team::createRandomQuarterback(const bool& npc) {
    
    // Struct containing all the information of the random player
    QB randomQBInfo = allPlayers.getRandomQuarterback(npc);

    // Quarterback object that will be returned
    Quarterback randomQB;

    randomQB.setName(randomQBInfo.name);
    randomQB.setSkill(randomQBInfo.skill);
    randomQB.setSpeed(randomQBInfo.speed);
    randomQB.setStrength(randomQBInfo.strength);
    randomQB.setThrowing(randomQBInfo.throwing);

    return randomQB;

}

Runningback Team::createRandomRunningback(const bool& npc) {
    // Struct containing all the information of the random player
    RB randomRBInfo = allPlayers.getRandomRunningback(npc);

    // Quarterback object that will be returned
    Runningback randomRB;

    randomRB.setName(randomRBInfo.name);
    randomRB.setSkill(randomRBInfo.skill);
    randomRB.setSpeed(randomRBInfo.speed);
    randomRB.setStrength(randomRBInfo.strength);
    randomRB.setElusiveness(randomRBInfo.elusiveness);

    return randomRB;
}

Kicker Team::createRandomKicker(const bool& npc) {
    // Struct containing all the information of the random player
    K randomKInfo = allPlayers.getRandomKicker(npc);

    // Quarterback object that will be returned
    Kicker randomK;

    randomK.setName(randomKInfo.name);
    randomK.setSkill(randomKInfo.skill);
    randomK.setSpeed(randomKInfo.speed);
    randomK.setStrength(randomKInfo.strength);
    randomK.setKicking(randomKInfo.kicking);

    return randomK;
}

WideReceiver Team::createRandomWideReceiver(const bool& npc) {
    // Struct containing all the information of the random player
    WR randomWRInfo = allPlayers.getRandomWideReceiver(npc);

    // Quarterback object that will be returned
    WideReceiver randomWR;

    randomWR.setName(randomWRInfo.name);
    randomWR.setSkill(randomWRInfo.skill);
    randomWR.setSpeed(randomWRInfo.speed);
    randomWR.setStrength(randomWRInfo.strength);
    randomWR.setCatching(randomWRInfo.catching);

    return randomWR;
}

OffensiveLine Team::createRandomOffensiveLine(const bool& npc) {
    // Struct containing all the information of the random player
    OL randomOLInfo = allPlayers.getRandomOffensiveLine(npc);

    // Quarterback object that will be returned
    OffensiveLine randomOL;

    randomOL.setName(randomOLInfo.name);
    randomOL.setSkill(randomOLInfo.skill);
    randomOL.setSpeed(randomOLInfo.speed);
    randomOL.setStrength(randomOLInfo.strength);
    randomOL.setBlocking(randomOLInfo.blocking);

    return randomOL;
}

DefensiveLine Team::createRandomDefensiveLine(const bool& npc) {
    // Struct containing all the information of the random player
    DL randomDLInfo = allPlayers.getRandomDefensiveLine(npc);

    // Quarterback object that will be returned
    DefensiveLine randomDL;

    randomDL.setName(randomDLInfo.name);
    randomDL.setSkill(randomDLInfo.skill);
    randomDL.setSpeed(randomDLInfo.speed);
    randomDL.setStrength(randomDLInfo.strength);
    randomDL.setRushing(randomDLInfo.rushing);

    return randomDL;
}

MiddleLine Team::createRandomMiddleLine(const bool& npc) {
    // Struct containing all the information of the random player
    MLB randomMLBInfo = allPlayers.getRandomMiddleLine(npc);

    // Quarterback object that will be returned
    MiddleLine randomMLB;

    randomMLB.setName(randomMLBInfo.name);
    randomMLB.setSkill(randomMLBInfo.skill);
    randomMLB.setSpeed(randomMLBInfo.speed);
    randomMLB.setStrength(randomMLBInfo.strength);
    randomMLB.setRushing(randomMLBInfo.rushing);
    randomMLB.setCoverage(randomMLBInfo.coverage);

    return randomMLB;
}

DefensiveBack Team::createRandomDefensiveBack(const bool& npc) {
    // Struct containing all the information of the random player
    DB randomDBInfo = allPlayers.getRandomDefensiveBack(npc);

    // Quarterback object that will be returned
    DefensiveBack randomDB;

    randomDB.setName(randomDBInfo.name);
    randomDB.setSkill(randomDBInfo.skill);
    randomDB.setSpeed(randomDBInfo.speed);
    randomDB.setStrength(randomDBInfo.strength);
    randomDB.setCoverage(randomDBInfo.coverage);

    return randomDB;
}

// Construct a team of random team members
void Team::createRandomTeam() {

    addQuarterback(createRandomQuarterback(false));
    addRunningback(createRandomRunningback(false));
    addKicker(createRandomKicker(false));

    addWideReceiver(createRandomWideReceiver(false));
    addWideReceiver(createRandomWideReceiver(false));
    addWideReceiver(createRandomWideReceiver(false));

    addOffensiveLine(createRandomOffensiveLine(false));
    addOffensiveLine(createRandomOffensiveLine(false));
    addOffensiveLine(createRandomOffensiveLine(false));
    addOffensiveLine(createRandomOffensiveLine(false));

    addDefensiveLine(createRandomDefensiveLine(false));
    addDefensiveLine(createRandomDefensiveLine(false));
    addDefensiveLine(createRandomDefensiveLine(false));

    addMiddleLine(createRandomMiddleLine(false));
    addMiddleLine(createRandomMiddleLine(false));

    addDefensiveback(createRandomDefensiveBack(false));
    addDefensiveback(createRandomDefensiveBack(false));
    addDefensiveback(createRandomDefensiveBack(false));
    addDefensiveback(createRandomDefensiveBack(false));

    calculateAllStats();

}

// Creates a random assortment of players for the NPC team
void Team::createNPCTeam() {

    addQuarterback(createRandomQuarterback(true));
    addRunningback(createRandomRunningback(true));
    addKicker(createRandomKicker(true));

    addWideReceiver(createRandomWideReceiver(true));
    addWideReceiver(createRandomWideReceiver(true));
    addWideReceiver(createRandomWideReceiver(true));

    addOffensiveLine(createRandomOffensiveLine(true));
    addOffensiveLine(createRandomOffensiveLine(true));
    addOffensiveLine(createRandomOffensiveLine(true));
    addOffensiveLine(createRandomOffensiveLine(true));

    addDefensiveLine(createRandomDefensiveLine(true));
    addDefensiveLine(createRandomDefensiveLine(true));
    addDefensiveLine(createRandomDefensiveLine(true));

    addMiddleLine(createRandomMiddleLine(true));
    addMiddleLine(createRandomMiddleLine(true));

    addDefensiveback(createRandomDefensiveBack(true));
    addDefensiveback(createRandomDefensiveBack(true));
    addDefensiveback(createRandomDefensiveBack(true));
    addDefensiveback(createRandomDefensiveBack(true));

    calculateAllStats();
}

// Increases games won by 1
void Team::incrementScore() {
    score++;
}

// Return score
int Team::getScore() const {
    return score;
}



