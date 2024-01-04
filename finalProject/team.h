#pragma once
#ifndef TEAM_H
#define TEAM_H

#include <iostream>

// Player base and derived classes
#include "player.h"
#include "wideReceiver.h"
#include "runningback.h"
#include "quarterback.h"
#include "offensiveLine.h"
#include "middleLinebacker.h"
#include "kicker.h"
#include "defensiveLine.h"
#include "defensiveBack.h"

#include "PlayerStructs.h"
#include "players.h"

class Team {
private:

    std::string teamName;

    // Default team names
    const std::string teamNames[10] = { "Patriots",
                                    "Eagles",
                                    "Broncos",
                                    "Dolphins",
                                    "Steelers",
                                    "Falcons",
                                    "Panthers",
                                    "Jaguars",
                                    "Bengals",
                                    "Lions" };

    // Create the object from which all player information is retrieved
    Players allPlayers;

    // Array of team members
    // Order of index: 
    // 
    // 0: Quarterback
    // 1: Runningback
    // 2: Kicker
    // 3-5: Wide Receivers
    // 6-9: Offensive Linebackers
    // 10-12: Defensive Linebackers
    // 13-14: Middle Linebackers
    // 15-18: Defensive Backs
    Player* teamMembers[19];

    // Base team stats
    double teamStrength;
    double teamSpeed;
    double teamSkill;
    double throwing;
    double elusiveness;
    double catching;
    double kicking;
    double rushing;
    double blocking;
    double coverage;

    // Probability values
    double fieldGoalChance;
    double touchDownChance;
    double extraPointChance;

    //Current score of team (games won)
    int score;

public:

    // Constructor
    Team();

    // Destructor
    ~Team();

    // Player accessor methods
    Quarterback* getQuarterback() const;
    WideReceiver* getWideReceiver(int index) const;
    Runningback* getRunningback() const;
    OffensiveLine* getOffensiveLine(int index) const;
    DefensiveBack* getDefensiveback(int index) const;
    DefensiveLine* getDefenseiveLine(int index) const;
    MiddleLine* getMiddleLine(int index) const;
    Kicker* getKicker() const;

    // Player setter methods
    void addQuarterback(const Quarterback &quarterback);
    void addWideReceiver(const WideReceiver &wideReceiver);
    void addRunningback(const Runningback &runningback);
    void addOffensiveLine(const OffensiveLine &offensiveLine);
    void addDefensiveback(const DefensiveBack &defensiveback);
    void addDefensiveLine(const DefensiveLine &defensiveLine);
    void addMiddleLine(const MiddleLine &middleLine);
    void addKicker(const Kicker &kicker);

    // Team stats accessor methods
    double getTeamStrength() const { return teamStrength; }
    double getTeamSpeed() const { return teamSpeed; }
    double getTeamSkill() const { return teamSkill; }
    double getThrowing() const { return throwing; }
    double getElusiveness() const { return elusiveness; }
    double getCatching() const { return catching; }
    double getKicking() const { return kicking; }
    double getRushing() const { return rushing; }
    double getBlocking() const { return blocking; }
    double getCoverage() const { return coverage; }

    // Team stats setter methods
    void setTeamStrength(double teamStrength) { this->teamStrength = teamStrength; }
    void setTeamSpeed(double teamSpeed) { this->teamSpeed = teamSpeed; }
    void setTeamSkill(double teamSkill) { this->teamSkill = teamSkill; }
    void setThrowing(double throwing) { this->throwing = throwing; }
    void setElusiveness(double elusiveness) { this->elusiveness = elusiveness; }
    void setCatching(double catching) { this->catching = catching; }
    void setKicking(double kicking) { this->kicking = kicking; }
    void setRushing(double rushing) { this->rushing = rushing; }
    void setBlocking(double blocking) { this->blocking = blocking; }
    void setCoverage(double coverage) { this->coverage = coverage; }

    // Probability accessor methods
    double getFieldGoalChance() const { return fieldGoalChance; }
    double getTouchDownChance() const { return touchDownChance; }
    double getExtraPointChance() const { return extraPointChance; }

    // Probability setter methods
    void setFieldGoalChance(double fieldGoalChance) { this->fieldGoalChance = fieldGoalChance; }
    void setTouchDownChance(double touchDownChance) { this->touchDownChance = touchDownChance; }
    void setExtraPointChance(double extraPointChance) { this->extraPointChance = extraPointChance; }

    // Average calculations 

    double calculateAverageStrength() const;
    double calculateAverageSpeed() const;
    double calculateAverageSkill() const;
    double calculateThrowing() const;
    double calculateElusiveness() const;
    double calculateAverageCatching() const;
    double calculateKicking() const;
    double calculateAverageCoverage() const;
    double calculateAverageRushing() const;
    double calculateAverageBlocking() const;

    // Base team stats
    void calculateBaseStats();

    // Probability calculations
    void calculateFieldGoalChance();
    void calculateTouchDownChance();
    void calculateExtraPointChance();

    // Perform all calculations - do not call in constructor - needs to update values after
    // user and NPC's make player selections
    void calculateAllStats();

    // Print team attributes
    void printStats() const;

    // Prints team member names and positions
    void printTeamMemberNames() const;

    Quarterback createRandomQuarterback(const bool &npc);
    Runningback createRandomRunningback(const bool &npc);
    Kicker createRandomKicker(const bool &npc);
    WideReceiver createRandomWideReceiver(const bool &npc);
    OffensiveLine createRandomOffensiveLine(const bool &npc);
    DefensiveLine createRandomDefensiveLine(const bool &npc);
    MiddleLine createRandomMiddleLine(const bool &npc);
    DefensiveBack createRandomDefensiveBack(const bool &npc);
    

    // Creates a random team of players - this is for debugging and
    //  won't be used for actual functionality
    void createRandomTeam();

    // Creates NPC team randomly - independent from user team
    void createNPCTeam();

    // Increases games won by 1
    void incrementScore();

    int getScore() const;

};

#endif