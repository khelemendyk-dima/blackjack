/**
 * @file hand.cpp
 * @brief Файл з реалізацією функцій класів "карта" та "рука".
 * Клас "карта": перерахування, конструктор, отримання значення 
 * карти, перевертання карти та оператор виводу.
 * Клас "рука": конструктор, деструктор, додавання карти в руку,
 * очищення руки від карт та отримання суми очок карт в руці.
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
		// якщо карта - валет, дама чи король
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
	// якщо перша карта лежить сорочкою вгору
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