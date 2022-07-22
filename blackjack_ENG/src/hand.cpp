/**
 * @file hand.cpp
 * @brief A file implementation the functions of the "Card" and 
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
 */

#include "hand.h"

Card::Card(Rank r, Suit s, bool ifu) : rank(r), suit(s), isFaceUp(ifu)
{
}
Card::~Card()
{
}
int Card::getValue() const
{
	int value = 0;
	if (isFaceUp) {
		value = rank;
		// if the card is jack, queen or king
		if (value > 10) {
			value = 10;
		}
	}
	return value;
}
void Card::flipCard()
{
	isFaceUp = !(isFaceUp);
}
ostream &operator<<(ostream &os, const Card &card)
{
	const string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	const string SUITS[] = { "c", "d", "h", "s" };
	if (card.isFaceUp)
		os << RANKS[card.rank] << SUITS[card.suit];
	else
		os << "XX";
	return os;
}

Hand::Hand()
{
	cards.reserve(7);
}
Hand::~Hand()
{
	clearHand();
}
void Hand::addCard(Card *pCard)
{
	cards.push_back(pCard);
}
void Hand::clearHand()
{
	for (auto iter = cards.begin(); iter != cards.end(); iter++) {
		delete *iter;
		*iter = 0;
	}
	cards.clear();
}
int Hand::getTotal() const
{
	if (cards.empty())
		return 0;
	// if the first card is face up
	if (cards[0]->getValue() == 0)
		return 0;
	int total = 0;
	bool isContainsAce = false;
	for (auto iter = cards.cbegin(); iter != cards.cend(); iter++) {
		total += (*iter)->getValue();
		if ((*iter)->getValue() == Card::ACE)
			isContainsAce = true;
	}
	if (isContainsAce && total <= 11) {
		total += 10;
	}
	return total;
}