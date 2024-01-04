#include <iostream>
#include "userPrompts.h"

using std::cout;

Prompts::Prompts() {}
Prompts::~Prompts() {}

void Prompts::continuePrompt() const {
	cout << "\nPress (y) to continue.\n";
}

// Prints the introduction to the fantasy football simulation
void Prompts::intro() const {
	cout << "\nWelcome to Fantasy Football!\n";

	continuePrompt();
}

// Explains all the rules to the player
void Prompts::rules() const {

	cout << "\nRULES\n\n";
	cout << "You are playing Fantasy Football.\n";
	cout << "You and four other teams will compete to see who can create the best football team.\n";
	cout << "\nThe game starts with a draft where each team gets to choose players for their team.\n";
	cout << "Each team will select a quarterback, a kicker, a runningback,\n" <<
		"Three wide receivers, four offensive linebackers, three defensive linebackers,\n" <<
		"Two middle linebackers, and four defensivebacks.\n\n";
	cout << "Each player has certain skills that contribute to the overall team rating.\n";
	cout << "During the draft, your goal is to create the best possible starting lineup.\n\n";
	cout << "Once the draft ends, each team will play every other team exactly once.\n";
	cout << "Teams can score touchdowns, field goals, and extra points (following the touchdowns).\n";
	cout << "Touchdowns are worth 6 points, fieldgoals 3, and extra points 1\n";
	cout << "\nWithin any particular game, the team which scores the most points wins.\n";
	cout << "At the end of the season, the scoreboard will be presented.\n";
	cout << "The team with the most wins will win the tournament. Ties are possible!\n\n";
}

// Starts the drafting process
// Will use the print methods from the "Players" class
void Prompts::beginDraft() const {
	cout << "\nYou are now starting the draft!\n";
	cout << "Each team will have a chance to" <<
		" pick a full roster of players.\nYou will be the first to pick.\n";
	
	continuePrompt();
}

// Player position selection prompts
void Prompts::chooseQuarterback() const {
	cout << "\nPlease select a quarterback\n\n";
}

void Prompts::chooseRunningback() const {
	cout << "\nPlease select a runningback\n\n";
}

void Prompts::chooseKicker() const {
	cout << "\nPlease select a kicker\n\n";
}

void Prompts::chooseWide() const {
	cout << "\nPlease select three wide receivers\n\n";
}

void Prompts::chooseOL() const {
	cout << "\nPlease select four offensive linebackers\n\n";
}

void Prompts::chooseDL() const {
	cout << "\nPlease select three defensive linebackers\n\n";
}

void Prompts::chooseML() const {
	cout << "\nPlease select two middle linebackers\n\n";
}

void Prompts::chooseDB() const {
	cout << "\nPlease select four defensivebacks\n\n";
}

// End player position selection prompts


// Informs the player that the games have begun
void Prompts::beginGames() const{
	std::cout << "\nThe games are about to begin!\nAdvance the simulation" <<
		" to see how your team performed at the end of the season!\n";

	continuePrompt();
}

// Informs the player that they can view the score break down for each week 
//  they played.
void Prompts::weekAnalysis() const {
	std::cout << "\nPress (y) to view a week by week breakdown of your games.\n";

}

// Given a week number, a player score, and an opponent score, will print the
// outcome of that specific week to the console. 
void Prompts::weekStats(const int week, const int playerScore, const int opponentScore) const{
	
	// Print week number
	std::cout << "\nWEEK " << week << "\n\n";

	if (playerScore > opponentScore) {
		std::cout << "You won this week. The score was " << playerScore <<
			" - " << opponentScore << "\n\n";
	}
	else {
		std::cout << "You lost this week. The score was " << playerScore <<
			" - " << opponentScore << "\n\n";
	}
}

void Prompts::playerWonSeason() const {
	cout << "\nCongratulations! You came in first place!\n";
}

