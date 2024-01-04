#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <algorithm>

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

#include "team.h"
#include "players.h"

#include "userPrompts.h"

class Game {
	public:
		// Constructor/destructor
		Game();
		~Game();
		
		// Start function
		void startGame();

		// Draft functions
		void runDraft();
		void userSelection();

		void selectQuarterback();
		void selectRunningback();
		void selectKicker();
		void selectWideReceiver();
		void selectOffensiveLine();
		void selectDefensiveLine();
		void selectMiddleLine();
		void selectDefensiveback();

		void npcSelection();


		// Runs the actual games between teams
		void runSimulation();

		// Gameplay functions
		void playGame(Team &teamA, Team &teamB, bool playerGame);

		// Calculate game score for a single team (statistically determined)
		int calculateTeamGameScore(const Team &team);
		// Returns 0 if teamA wins, returns 1 if teamB wins
		int runOvertime();

		// Runs games between every team
		void runAllGames();

		void seeResults();

		// Announces the winners and any ties
		void announceWinners() const;

		void printScoreBoard() const;

		// For debugging
		void printAllScores() const;

		void gameBreakdown() const;

		void endGame() const;

		void printFinalScoreboard() const;

	private:

		// User interaction class
		Prompts prompts;

		// Player information class
		Players players;

		// Participating teams
		Team playerTeam;
		Team npc1;
		Team npc2;
		Team npc3;
		Team npc4;

		// Stores the outcomes of the games the player plays
		// Odd indeces are the players' scores, even are the opponent's
		int gameScores[8];
		// Tracks which index (week) is being updated
		int week;

};

#endif