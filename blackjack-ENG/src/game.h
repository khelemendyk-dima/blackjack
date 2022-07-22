#ifndef GAME_H
#define GAME_H

/**
 * @file game.h
 * @brief A file describing the user interface, methods of the
 * "Deck" and "Game" classes.
 * Class "Deck": constructor, destructor, populating and 
 * shuffling deck, player interaction, and adding an extra card.
 * Class "Game": constructor, destructor, and start game.
 *
 * @author Khelemendyk D.
 * @date 15-july-2022
 * @version 0.1
 */

#include "player.h"
#include <algorithm>
#include <ctime>
#include <cctype>

/**
 * Enumeration "Action". Reflects the user's desire for further 
 * actions in program(start the game, show the rules or exit).
 */
enum Action { START, RULES, END };

/**
 * Introduction.
 *
 * The function welcomes the player and asks for the next action.
 * @return enum "Action"(START, RULES or END);
 */
Action introduction();

// Printing game rules.
void showRulesOfGame();

/**
 * Getting names of players.
 *
 * The function asks for the number of players and their names.
 * @param names is a vector that stores the names of all players.
 */
void getNamesOfPlayers(vector<string> &names);

/**
 * Is play again.
 *
 * The function asks the user whether to play again.
 * @return true if the player wants to resume the game.
 */
bool isPlayAgain();

/**
 * Class "Deck". Represents a playing deck of cards.
 */
class Deck : public Hand {
    public:
	Deck();
	~Deck() override;

	/**
	 * Populating the deck.
	 *
	 * The function creates a deck of 52 cards.
	 */
	void populateDeck();

	/**
	 * Shuffling the deck.
	 *
	 * The function shuffles the deck of cards using 
	 * the random_shuffle function.
	 */
	void shuffleDeck();

	/**
	 * Dealing with the player.
	 *
	 * If there are cards in the player's hand, function adds 
	 * a card.
	 * @param hand - player's hand.
	 */
	void dealWithPlayer(Hand &hand);

	/**
	 * Additional card.
	 *
	 * If the player has not busted and wants to take a card, 
	 * then thefunction deals with the player by the function 
	 * {@link dealWithPlayer}. Then prints the user on the 
	 * screen. Also, if the player has busted - reports about it.
	 * @param genericPlayer - a reference to a generic player. 
	 */
	void additionalCards(GenericPlayer &genericPlayer);
};
/**
 * Class "Game". Conducts the game.
 */
class Game {
    public:
	Game(const vector<string> &names);
	~Game();
	/**
	 * Start the game.
	 *
	 * Firstly, the function giving two playing cards to each 
	 * player and hides the dealer's first card. Then opens the 
	 * hands of all players. Now gives out additional cards to 
	 * players (if the player has busted - prints it). Then 
	 * opens the dealer's first card and deals additional cards 
	 * to him. Finally, sums up the game. At the end, function 
	 * frees allocated memory.
	 */
	void startGame();

    private:
	Deck deck;
	Dealer dealer;
	vector<Player> players;
};
#endif