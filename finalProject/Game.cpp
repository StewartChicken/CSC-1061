// TODO - exception handling for user input

#include "Game.h"

// Construtor
Game::Game() {
	week = 0;
}

// Destructor
Game::~Game() {}

// Starts initial game
void Game::startGame() {
	std::string userInput = "";

	while (userInput != "y") {
		prompts.intro();

		std::cin >> userInput;
	}

	// Clear console
	system("cls");

	userInput = "";

	while (userInput != "y") {
		prompts.rules();
		prompts.continuePrompt();

		std::cin >> userInput;
	}

	// Clear console
	system("cls");
}

void Game::runDraft() {
	std::string userInput = "";

	while (userInput != "y") {
		prompts.beginDraft();

		std::cin >> userInput;
	}

	// The user selects their players first. Then the npc's
	// get random players assigned to their team to simulate
	// their "draft" phase
	// 
	userSelection();
	//playerTeam.createRandomTeam();
	
	npcSelection();

	// For Debugging
	/*playerTeam.printStats();
	npc1.printStats();
	npc2.printStats();
	npc3.printStats();
	npc4.printStats();*/

	// Clear Console
	system("cls");

}

// Function that runs the entire user draft process
void Game::userSelection() {

	system("cls");

	prompts.chooseQuarterback();
	selectQuarterback();
	system("cls");

	prompts.chooseRunningback();
	selectRunningback();
	system("cls");

	prompts.chooseKicker();
	selectKicker();
	system("cls");

	prompts.chooseWide();
	selectWideReceiver();
	system("cls");

	prompts.chooseWide();
	selectWideReceiver();
	system("cls");

	prompts.chooseWide();
	selectWideReceiver();
	system("cls");

	prompts.chooseOL();
	selectOffensiveLine();
	system("cls");

	prompts.chooseOL();
	selectOffensiveLine();
	system("cls");

	prompts.chooseOL();
	selectOffensiveLine();
	system("cls");

	prompts.chooseOL();
	selectOffensiveLine();
	system("cls");

	prompts.chooseDL();
	selectDefensiveLine();
	system("cls");

	prompts.chooseDL();
	selectDefensiveLine();
	system("cls");

	prompts.chooseDL();
	selectDefensiveLine();
	system("cls");

	prompts.chooseML();
	selectMiddleLine();
	system("cls");

	prompts.chooseML();
	selectMiddleLine();
	system("cls");

	prompts.chooseDB();
	selectDefensiveback();
	system("cls");

	prompts.chooseDB();
	selectDefensiveback();
	system("cls");

	prompts.chooseDB();
	selectDefensiveback();
	system("cls");

	prompts.chooseDB();
	selectDefensiveback();
	system("cls");

	playerTeam.calculateAllStats();
}

// * Individual position selection functions
// -------------------------------------------
// *

void Game::selectQuarterback() {
	int userInput = 10;

	// Temporary conditional - will replace with exception handling later
	while (userInput > 4) {
		players.printQuarterbacks();

		std::cin >> userInput;
	}

	// Add new quarterback
	QB tempQBStats = players.getQuarterbackStats(userInput);
	Quarterback tempQuarterback;

	tempQuarterback.setName(tempQBStats.name);
	tempQuarterback.setSkill(tempQBStats.skill);
	tempQuarterback.setSpeed(tempQBStats.speed);
	tempQuarterback.setStrength(tempQBStats.strength);
	tempQuarterback.setThrowing(tempQBStats.throwing);

	playerTeam.addQuarterback(tempQuarterback);
	players.activateQuarterback(userInput);
}

void Game::selectRunningback() {
	int userInput = 10;

	while (userInput > 4) {
		players.printRunningbacks();

		std::cin >> userInput;
	}

	// Add new runningback
	RB tempRBStats = players.getRunningbackStats(userInput);
	Runningback tempRunningback;

	tempRunningback.setName(tempRBStats.name);
	tempRunningback.setSkill(tempRBStats.skill);
	tempRunningback.setSpeed(tempRBStats.speed);
	tempRunningback.setStrength(tempRBStats.strength);
	tempRunningback.setElusiveness(tempRBStats.elusiveness);

	playerTeam.addRunningback(tempRunningback);
	players.activateRunningback(userInput);

}

void Game::selectKicker() {
	int userInput = 10;

	while (userInput > 4) {
		players.printKickers();

		std::cin >> userInput;
	}

	// Add new kicker
	K tempKstats = players.getKickerStats(userInput);
	Kicker tempKicker;

	tempKicker.setName(tempKstats.name);
	tempKicker.setSkill(tempKstats.skill);
	tempKicker.setSpeed(tempKstats.speed);
	tempKicker.setStrength(tempKstats.strength);
	tempKicker.setKicking(tempKstats.kicking);

	playerTeam.addKicker(tempKicker);
	players.activateKicker(userInput);

}

void Game::selectWideReceiver() {
	int userInput = 10;

	while (userInput > 7) {
		players.printWideReceivers();

		std::cin >> userInput;
	}

	// Add new wide receiver

	// These two variables were added to fix an offset issue I was having
	//  in regards to the user input. The wide receiver was selected by directly
	//	indexing the wideReceivers array from the user input. This resulted in
	//	the same receivers being selected, should the user make the same selection.
	//	(the screen would update which positions available but the indexing would not update).
	//	I fixed this by plastd::cing the indexing within a while loop that increments
	//	an offset until a non-active player is found. 
	bool nonActiveReceiverFound = false;
	int offset = 0;

	WR tempWRstats;
	WideReceiver tempWideReceiver;

	while (!nonActiveReceiverFound) {
		tempWRstats = players.getWideReceiverStats(userInput + offset);

		if (tempWRstats.active) {
			offset++;
			continue;
		}
		break;
	}

	tempWideReceiver.setName(tempWRstats.name);
	tempWideReceiver.setSkill(tempWRstats.skill);
	tempWideReceiver.setSpeed(tempWRstats.speed);
	tempWideReceiver.setStrength(tempWRstats.strength);
	tempWideReceiver.setCatching(tempWRstats.catching);

	playerTeam.addWideReceiver(tempWideReceiver);
	players.activateWideReceiver(userInput + offset);
}

void Game::selectOffensiveLine() {
	int userInput = 10;

	while (userInput > 8) {
		players.printOffensiveLinebackers();

		std::cin >> userInput;
	}

	bool nonActiveReceiverFound = false;
	int offset = 0;

	// Add new offensive linebacker
	OL tempOLstats;
	OffensiveLine tempOffensiveLine;

	while (!nonActiveReceiverFound) {
		tempOLstats = players.getOffensiveLineStats(userInput + offset);

		if (tempOLstats.active) {
			offset++;
			continue;
		}
		break;
	}

	tempOffensiveLine.setName(tempOLstats.name);
	tempOffensiveLine.setSkill(tempOLstats.skill);
	tempOffensiveLine.setSpeed(tempOLstats.speed);
	tempOffensiveLine.setStrength(tempOLstats.strength);
	tempOffensiveLine.setBlocking(tempOLstats.blocking);

	playerTeam.addOffensiveLine(tempOffensiveLine);
	players.activateOffensiveLine(userInput + offset);
}

void Game::selectDefensiveLine() {
	int userInput = 10;

	while (userInput > 7) {
		players.printDefensiveLinebackers();

		std::cin >> userInput;
	}

	// Add new defensive linebacker
	bool nonActiveReceiverFound = false;
	int offset = 0;

	DL tempDLstats;
	DefensiveLine tempDefensiveLine;

	while (!nonActiveReceiverFound) {
		tempDLstats = players.getDefensiveLineStats(userInput + offset);

		if (tempDLstats.active) {
			offset++;
			continue;
		}
		break;
	}

	tempDefensiveLine.setName(tempDLstats.name);
	tempDefensiveLine.setSkill(tempDLstats.skill);
	tempDefensiveLine.setSpeed(tempDLstats.speed);
	tempDefensiveLine.setStrength(tempDLstats.strength);
	tempDefensiveLine.setRushing(tempDLstats.rushing);

	playerTeam.addDefensiveLine(tempDefensiveLine);
	players.activateDefensiveLine(userInput + offset);
}

void Game::selectMiddleLine() {
	int userInput = 10;

	while (userInput > 5) {
		players.printMiddleLinebackers();

		std::cin >> userInput;
	}

	// Add new middle linebacker
	bool nonActiveReceiverFound = false;
	int offset = 0;

	MLB tempMLBstats;
	MiddleLine tempMiddleLine;

	while (!nonActiveReceiverFound) {
		tempMLBstats = players.getMiddleLineStats(userInput + offset);

		if (tempMLBstats.active) {
			offset++;
			continue;
		}
		break;
	}

	tempMiddleLine.setName(tempMLBstats.name);
	tempMiddleLine.setSkill(tempMLBstats.skill);
	tempMiddleLine.setSpeed(tempMLBstats.speed);
	tempMiddleLine.setStrength(tempMLBstats.strength);
	tempMiddleLine.setRushing(tempMLBstats.rushing);
	tempMiddleLine.setCoverage(tempMLBstats.coverage);

	playerTeam.addMiddleLine(tempMiddleLine);
	players.activateMiddleLine(userInput + offset);
}

void Game::selectDefensiveback() {
	int userInput = 10;

	while (userInput > 8) {
		players.printDefensivebacks();

		std::cin >> userInput;
	}

	// Add new middle linebacker
	bool nonActiveReceiverFound = false;
	int offset = 0;

	DB tempDBstats;
	DefensiveBack tempDefensiveBack;

	while (!nonActiveReceiverFound) {
		tempDBstats = players.getDefensivebackStats(userInput + offset);

		if (tempDBstats.active) {
			offset++;
			continue;
		}
		break;
	}

	tempDefensiveBack.setName(tempDBstats.name);
	tempDefensiveBack.setSkill(tempDBstats.skill);
	tempDefensiveBack.setSpeed(tempDBstats.speed);
	tempDefensiveBack.setStrength(tempDBstats.strength);
	tempDefensiveBack.setCoverage(tempDBstats.coverage);
	
	playerTeam.addDefensiveback(tempDefensiveBack);
	players.activateDefensiveback(userInput + offset);
}


// *
// -------------------------------------------
// *

// Generates random teams for the npcs
void Game::npcSelection() {
	npc1.createNPCTeam();
	npc2.createNPCTeam();
	npc3.createNPCTeam();
	npc4.createNPCTeam();
}

void Game::runSimulation() {

	// Run every possible combination of game between teams
	runAllGames();

	// Prints the number of games won by each team
	//printAllScores();

	seeResults();
}

// After all games are run, prompts the user to press (y) to
//  see the results of the season. 
void Game::seeResults() {

	system("cls");

	std::string userInput = "";

	while (userInput != "y") {
		std::cout << "All games have been completed!\n\n";
		std::cout << "Press (y) to see the results!\n";

		std::cin >> userInput;
	}

	system("cls");
}

// Runs a game between two teams and updates the number 
// of games won by the victor
// If PlayerGame is true, then the game being played is one of the player's
//  games and the gameScores array must be updated
void Game::playGame(Team &teamA, Team &teamB, bool playerGame){
	int teamAScore = calculateTeamGameScore(teamA);
	int teamBScore = calculateTeamGameScore(teamB);

	int winner;

	// Tie condition - overtime
	if (teamAScore == teamBScore) {
		winner = runOvertime();

		// A touch down is scored to win over time
		if (winner == 0) {
			teamAScore += 6;
		}
		else {
			teamBScore += 6;
		}

	}

	teamAScore > teamBScore ? teamA.incrementScore() 
								: teamB.incrementScore();

	if (playerGame) {
		gameScores[this->week] = teamAScore;
		gameScores[(this->week) + 1] = teamBScore;

		week += 2;
	}
}

// Calculates the number of touchdowns, fieldgoals, and extra
//  points made by the given team within a game. 
int Game::calculateTeamGameScore(const Team &team){

	// Random number generator
	// Used to determine the number of points scored
	std::random_device rand;
	std::mt19937 generator(rand());

	std::uniform_real_distribution<double> distribution(0.0, 1.0);
	double randomValue = distribution(generator);

	// Number of different types of points to score - initial declarations
	int fieldGoalsScored = 0;
	int touchDownsScored = 0;
	int extraPointsScored = 0;

	// Number of touch downs scored
	while (randomValue <= team.getTouchDownChance()) {
		randomValue = distribution(generator);
		touchDownsScored++;
	}

	//std::cout << "Number of touchdowns: " << touchDownsScored << std::endl;

	randomValue = distribution(generator);

	// Number of field goals scored
	while (randomValue <= team.getFieldGoalChance()) {
		randomValue = distribution(generator);
		fieldGoalsScored++;
	}

	//std::cout << "Number of field goals: " << fieldGoalsScored << std::endl;

	randomValue = distribution(generator);

	// Number of extra points scored
	for (int i{}; i < touchDownsScored; i++) {
		if (randomValue <= team.getExtraPointChance()) {
			extraPointsScored++;
		}

		randomValue = distribution(generator);
	}

	//std::cout << "Number of extra points scored: " << extraPointsScored << std::endl;

	//std::cout << fieldGoalsScored * 3 + touchDownsScored * 6 + extraPointsScored << std::endl;

	return fieldGoalsScored * 3 + touchDownsScored * 6 + extraPointsScored;

} // End calculateTeamGameScore

// Runs overtime in the event of a game tie
// Each team has a 50/50 chance of winning in the over time.
// Coin toss is simulated
int Game::runOvertime(){

	// Random number generator
	std::random_device rand;
	std::mt19937 generator(rand());

	std::uniform_int_distribution<int> numberDistribution(0, 1);

	return numberDistribution(generator);

}

// Runs every possible combination of game
void Game::runAllGames() {
	playGame(npc1, npc2, false);
	playGame(npc1, npc3, false);
	playGame(npc1, npc4, false);
	playGame(playerTeam, npc1, true);

	playGame(npc2, npc3, false);
	playGame(npc2, npc4, false);
	playGame(playerTeam, npc2, true);

	playGame(npc3, npc4, false);
	playGame(playerTeam, npc3, true);

	playGame(playerTeam, npc4, true);
}

// Creates the final scoreboard
void Game::announceWinners() const {
	bool playerWins = true;

	int scores[5] = { playerTeam.getScore(),
					  npc1.getScore(),
					  npc2.getScore(),
					  npc3.getScore(),
					  npc4.getScore()};

	for (int i = 1; i < 5; i++) {
		if (scores[i] > scores[0]) {
			playerWins = false;
		}
	}

	if (playerWins) prompts.playerWonSeason();

	printScoreBoard();

	std::string userInput = "";

	while (userInput != "y") {
		prompts.weekAnalysis();

		std::cin >> userInput;
	}

	system("cls");

}

// Prints scoreboard - first place at top
void Game::printScoreBoard() const {

	// Create a vector of pairs to store the key-value pairs from the hash table
	std::vector<std::pair<std::string, int>> scoreNamePairs;

	// Create pair for each team (contains team name and score)
	std::pair<std::string, int> playerTeam;
	std::pair<std::string, int> npc1;
	std::pair<std::string, int> npc2;
	std::pair<std::string, int> npc3;
	std::pair<std::string, int> npc4;

	// Assign values

	playerTeam.first = "Your Team";
	playerTeam.second = this->playerTeam.getScore();

	npc1.first = "Team A";
	npc1.second = this->npc1.getScore();

	npc2.first = "Team B";
	npc2.second = this->npc2.getScore();

	npc3.first = "Team C";
	npc3.second = this->npc3.getScore();

	npc4.first = "Team D";
	npc4.second = this->npc4.getScore();

	// Add score/name pairs to the vector of pairs
	scoreNamePairs.push_back(playerTeam);
	scoreNamePairs.push_back(npc1);
	scoreNamePairs.push_back(npc2);
	scoreNamePairs.push_back(npc3);
	scoreNamePairs.push_back(npc4);

	// Sort vector by score
	std::sort(scoreNamePairs.begin(), scoreNamePairs.end(), [](const auto& a, const auto& b) {
		return a.second > b.second;
	});

	// Heading
	std::cout << "\nSCOREBOARD\n\n";

	// Print sorted vector
	for (const auto& score : scoreNamePairs) {
		std::cout << score.first << ": " << score.second << std::endl;
	}
}

void Game::printAllScores() const {
	std::cout << playerTeam.getScore() << std::endl;
	std::cout << npc1.getScore() << std::endl;
	std::cout << npc2.getScore() << std::endl;
	std::cout << npc3.getScore() << std::endl;
	std::cout << npc4.getScore() << std::endl;
}

void Game::gameBreakdown() const {
	
	std::string userInput = "";

	while (userInput != "y") {
		prompts.weekStats(1, gameScores[0], gameScores[1]);
		prompts.continuePrompt();

		std::cin >> userInput;
	}

	system("cls");
	userInput = "";

	while (userInput != "y") {
		prompts.weekStats(2, gameScores[2], gameScores[3]);
		prompts.continuePrompt();

		std::cin >> userInput;
	}

	system("cls");
	userInput = "";

	while (userInput != "y") {
		prompts.weekStats(3, gameScores[4], gameScores[5]);
		prompts.continuePrompt();

		std::cin >> userInput;
	}

	system("cls");
	userInput = "";

	while (userInput != "y") {
		prompts.weekStats(4, gameScores[6], gameScores[7]);
		prompts.continuePrompt();

		std::cin >> userInput;
	}

}

void Game::endGame() const {
	system("cls");

	std::cout << "\nGAME OVER\n\nThank you for playing!\n";

	printFinalScoreboard();
}

// Will print the user's final score board
// Includes the scores from each week
void Game::printFinalScoreboard() const {
	std::cout << "\nWeek 1: " << gameScores[0] << " - " << gameScores[1] << "\n";
	std::cout << "Week 2: " << gameScores[2] << " - " << gameScores[3] << "\n";
	std::cout << "Week 3: " << gameScores[4] << " - " << gameScores[5] << "\n";
	std::cout << "Week 4: " << gameScores[6] << " - " << gameScores[7] << "\n";
}