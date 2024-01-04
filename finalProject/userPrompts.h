#pragma once
#ifndef PROMPTS_H
#define PROMPTS_H

#include <iostream>

#include "players.h"

class Prompts {

    public:
        Prompts();
        ~Prompts();

        // Prompts player when they are ready to continue
        void continuePrompt() const;

        // Intro text 
        void intro() const;

        // Explains rules
        void rules() const;

        // Draft text
        void beginDraft() const;

        // Player selection prompts

        void chooseQuarterback() const;
        void chooseRunningback() const;
        void chooseKicker() const;
        void chooseWide() const;
        void chooseOL() const;
        void chooseDL() const;
        void chooseML() const;
        void chooseDB() const;

        void beginGames() const;

        // Informs the player that they can view their week by week breakdown
        void weekAnalysis() const;

        // Prints a single week's stats
        void weekStats(const int week, const int playerScore, const int opponentScore) const;

        void playerWonSeason() const;

    private:
        

};

#endif