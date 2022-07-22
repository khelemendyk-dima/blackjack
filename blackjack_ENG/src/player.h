#ifndef PLAYER_H
#define PLAYER_H

/**
 * @file player.h
 * @brief A file describing the functions of the "GenericPlayer", 
 * "Player" and "Dealer" classes.
 * Class "GenericPlayer": constructor, destructor, whether 
 * the player busted, output operator, and output of the player 
 * who busted.
 * Class "Player": constructor, destructor, whether the player 
 * wants to take a card, win, lose, and pushes.
 * Class "Dealer": constructor, destructor, whether the dealer 
 * wants to take a card and flipping the first card.
 * 
 * @author Khelemendyk D.
 * @date 15-july-2022
 * @version 0.1
 */

#include "hand.h"
#include <cctype>

/**
 * Class "GeneralPlayer". Represents a generic player that has 
 * its own name and some methods.
 */
class GenericPlayer : public Hand {
    public:
	GenericPlayer(const string &name = "");
	~GenericPlayer() override;

	virtual bool isHittingCard() const = 0;
	/**
	 * Is busted player.
	 *
	 * The function checks if the total points of the cards in 
	 * the hand is greater than 21.
	 * @return true if the player is busted.
	 */
	bool isBusted() const;

	// Output of the player who busts.
	void playerBusts() const;
	
	/**
	 * Output operator.
	 *
	 * The function sends the player to the standard output 
	 * stream. Prints the player's name, his cards, and his 
	 * total points. 
	 */
	friend ostream &operator<<(ostream &os, const GenericPlayer &genericPlayer);

    protected:
	string playerName;
};
/**
 * Class "Player".
 */
class Player : public GenericPlayer {
    public:
	Player(const string &name = "");
	~Player() override;
	/**
	 * Receiving data on the player's desire to continue taking a card.
	 *
	 * If the total number of points in the player's hand is not 
	 * equal 21 then function asks if he wants to take a card.
	 * @return true if the player wants to take the card.
	 */
	bool isHittingCard() const override;

	// Output of the player who wins.
	void playerWins() const;
	// Output of the player who loses.
	void playerLoses() const;
	// Output of the player who pushes.
	void playerPushes() const;
};
/**
 * Class "Dealer".
 */
class Dealer : public GenericPlayer {
    public:
	Dealer(const string &name = "Dealer");
	~Dealer() override;
	/**
	 * Receiving data on the dealer's desire to continue taking 
	 * the card.
	 *
	 * @return true if the total number of card points in the 
	 * dealer's hand is less than 17.
	 */
	bool isHittingCard() const override;
	
	/**
	 * Flipping the first card.
	 *
	 * If there are cards - the function flipping the first one.
	 */
	void flipFirstCard();
};
#endif