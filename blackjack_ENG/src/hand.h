#ifndef HAND_H
#define HAND_H

/**
 * @file hand.h
 * @brief A file describing the functions of the "Card" and 
 * "Hand" classes.
 * Class "Card": enumerations, constructor, destructor, getting 
 * the value of the card, flipping the card, and the output 
 * operator.
 * Class "Hand": constructor, destructor, adding a card to 
 * the hand, clearing the hand of cards and getting the sum of 
 * the points of the cards in the hand.
 *
 * @author Khelemendyk D.
 * @date 15-july-2022
 * @version 0.1
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * Class "Card". Represent rank and suit of the card.
 */
class Card {
    public:
	/**
	 * Enumeration "Rank". Represents rank of the card.
	 */
	enum Rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
	/**
	 * Enumeration "Suit". Represents suit of the card.
	 */
	enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };
	Card(Rank r = ACE, Suit s = SPADES, bool ifu = true);
	~Card();
	/**
	 * Getting the card value.
	 *
	 * The function checks whether the card is open, 
	 * if so - returns its value.
	 * @return value of the card from 1 to 11.
	 */
	int getValue() const;

	/**
	 * Flipping the card.
	 *
	 * The function flips the card: a card lying face up is 
	 * turned face down and vice versa.
	 */
	void flipCard();

	/**
	 * Output operator overloading.
	 *
	 * The function sends an object of type Card to the standard 
	 * output stream. If the card is not hidden, it prints its 
	 * rank and suit, otherwise it prints "XX".
	 */
	friend ostream &operator<<(ostream &os, const Card &card);

    private:
	Rank rank;
	Suit suit;
	bool isFaceUp;
};
/**
 * Class "Hand". Represent a hand holding cards.
 */
class Hand {
    public:
	Hand();
	virtual ~Hand();
	/**
	 * Adding a card to the hand.
	 *
	 * The function receives a pCard and adds it to the vector 
	 * of cards.
	 * @param pCard card that needs to be added to hand.
	 */
	void addCard(Card *pCard);

	/**
	 * Clearing hand from cards.
	 *
	 * The function passes through the vector, frees the 
	 * allocated memory. Then clears the vector.
	 */
	void clearHand();
	
	/**
	 * Receiving the total number of card points in the player's 
	 * hand.
	 *
	 * Function counts the number of points, assigning the value 
	 * of 1 or 11 to the ace depending on the situation.
	 * @return the total number of points in the player's hand.
	 */
	int getTotal() const;

    protected:
	vector<Card *> cards;
};
#endif