/**
 * @file player.cpp
 * @brief A file implementation the functions of the 
 * "GenericPlayer", "Player" and "Dealer" classes.
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
 */

#include "player.h"

GenericPlayer::GenericPlayer(const string &name) : playerName(name)
{
}
GenericPlayer::~GenericPlayer()
{
}
bool GenericPlayer::isBusted() const
{
	return (getTotal() > 21);
}
void GenericPlayer::playerBusts() const
{
	cout << endl << playerName << " busts.\n";
}
ostream &operator<<(ostream &os, const GenericPlayer &genericPlayer)
{
	os << genericPlayer.playerName << ":\n";
	if (!genericPlayer.cards.empty()) {
		for (auto pCard = genericPlayer.cards.cbegin(); pCard != genericPlayer.cards.cend(); pCard++)
			os << *(*pCard) << "\t";
		if (genericPlayer.getTotal() != 0)
			cout << "(" << genericPlayer.getTotal() << ")";
	} else
		os << "<empty>";
	return os;
}

Player::Player(const string &name) : GenericPlayer(name)
{
}
Player::~Player()
{
}
bool Player::isHittingCard() const
{
	if (getTotal() == 21)
		return false;
	char response = 'a';
	while (response != 'Y' && response != 'N') {
		cout << playerName << ", do you want a hit? (Y/N): ";
		cin >> response;
		response = (char)toupper(response);
	}
	return response == 'Y';
}
void Player::playerWins() const
{
	cout << endl << playerName << " wins!\n";
}
void Player::playerLoses() const
{
	cout << endl << playerName << " loses.\n";
}
void Player::playerPushes() const
{
	cout << endl << playerName << " pushes.\n";
}

Dealer::Dealer(const string &name) : GenericPlayer(name)
{
}
Dealer::~Dealer()
{
}
bool Dealer::isHittingCard() const
{
	return (getTotal() < 17);
}
void Dealer::flipFirstCard()
{
	if (!(cards.empty()))
		cards[0]->flipCard();
	else
		cout << "No card to flip!\n";
}