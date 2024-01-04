/*
 * Written by Evan Poon
 * 28 July 2023
 * CSC1061
 * Fantasy Football
 * 
 * This is the main file for the fantasy football simulator.
 * This simulator allows users to play fantasy football with four other NPC teams.
 * The user has the opportunity to "draft" the players on their team.
 * The NPCs also draft players to their respective teams. 
 * Each team plays the other one time during the season.
 * When the season is complete, a scoreboard is displayed and the player
 *  views their team's performance. Ties are possible
 * 
 * 
 * Programming concepts used:
 *  - Classes
 *  - Abstract Data Types
 *  - Inheritance
 *  - Pointers
 *  - Polymorphism
 *  - Constructors/Destructors
*/

#include "Game.h"

int main() {

    Game game;

    game.startGame();
    game.runDraft();
    game.runSimulation();
    game.announceWinners();
    game.gameBreakdown();
    game.endGame();

    return 0;
}