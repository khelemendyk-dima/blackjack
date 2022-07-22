/**
 * @file game.cpp
 * @brief Файл з реалізацією функцій взаємодії з користувачем, 
 * класів "колода" та "гра".
 * Клас "колода": конструктор, деструктор, створення та 
 * тасування колоди, взаємодія з гравцем та додавання 
 * додаткової карти.
 * Клас "гра": конструктор, деструктор та початок гри.
 *
 * @author Khelemendyk D.
 * @date 15-july-2022
 */

#include "game.h"

Action introduction()
{
	cout << "\n\t\tWelcome to Blackjack!\n\n";
	cout << "0 - START GAME" << endl;
	cout << "1 - RULES OF THE GAME" << endl;
	cout << "2 - QUIT" << endl << endl;
	char answer = 0;
	while (answer < 48 || answer > 50) {
		cout << "Your choice: ";
		cin >> answer;
	}
	cout << endl;
	int action = answer - '0';
	if (action == 0) {
		return START;
	} else if (action == 1) {
		return RULES;
	} else {
		return END;
	}
}
void showRulesOfGame()
{
	cout << "\t\tRules of the game" << endl;
	cout << "\tBlackjack can be played by 1 to 7 players. One standard 52-card\n"
		"deck is shuffled. Each player gets an initial hand of two cards visible\n"
		"to the people playing on it. The dealer's hand gets its first card face\n"
		"down, and, a second card gets face up. The object of the\n"
		"game is to win by creating card totals higher than those of the dealer's\n"
		"hand but not exceeding 21, or by stopping at a total in the hope that\n"
		"dealer will bust. On their turn, players choose to \"hit\"(take a card)\n"
		"or \"stand\" (end their turn and stop without taking a card). Number cards\n"
		"count as theirnumber, the jack, queen, and king count as 10, and aces count\n"
		"as either 1 or 11 according to the player's choice. If the total exceeds\n"
		"21 points, it busts, and player immediately lose. After the players have\n"
		"finished playing, dealer show its first card. The dealer's hand is\n"
		"resolved by drawing cards until the hand achieves a total of 17 or higher.\n"
		"If the dealer busts, all remaining player hands win. If the dealer does\n"
		"not bust, each remaining bet wins if its hand is higher than the dealer's\n"
		"and loses if it is lower. If the player and the dealer have the same number\n"
		"of points in their hands, then this situation is called a push. In such a\n"
		"situation, no one wins or loses. Good luck!\n\n";
}
void getNamesOfPlayers(vector<string> &names)
{
	cout << "\tGetting name of players..." << endl;
	char numPlayers = 0;
	// числа від 1 до 7 в ASCII
	while (numPlayers < 49 || numPlayers > 55) {
		cout << "How many players? (1 - 7): ";
		cin >> numPlayers;
	}
	string name;
	getchar();
	for (int i = 0; i < numPlayers - '0'; i++) {
		cout << "Enter player name: ";
		getline(cin, name);
		names.push_back(name);
	}
	cout << endl;
}
bool isPlayAgain()
{
	char playAgain = 'y';
	while (playAgain != 'Y' && playAgain != 'N') {
		cout << "\nDo you want to play again? (Y/N): ";
		cin >> playAgain;
		playAgain = (char)toupper(playAgain);
	}
	if (playAgain == 'Y')
		return true;
	else
		return false;
}
Deck::Deck()
{
	cards.reserve(52);
	populateDeck();
}
Deck::~Deck()
{
}
void Deck::populateDeck()
{
	clearHand();
	for (int s = Card::CLUBS; s <= Card::SPADES; s++) {
		for (int r = Card::ACE; r <= Card::KING; r++) {
			addCard(new Card((Card::Rank)(r), (Card::Suit)(s)));
		}
	}
}
void Deck::shuffleDeck()
{
	random_shuffle(cards.begin(), cards.end());
}
void Deck::dealWithPlayer(Hand &hand)
{
	if (!cards.empty()) {
		hand.addCard(cards.back());
		cards.pop_back();
	} else
		cout << "Out of cards. Unable to deal.";
}
void Deck::additionalCards(GenericPlayer &genericPlayer)
{
	cout << endl;
	while (!(genericPlayer.isBusted()) && genericPlayer.isHittingCard()) {
		dealWithPlayer(genericPlayer);
		cout << genericPlayer << endl;
		if (genericPlayer.isBusted())
			genericPlayer.playerBusts();
	}
}

Game::Game(const vector<string> &names)
{
	// створює вектор гравців із вектора з іменами
	for (auto pName = names.begin(); pName != names.end(); pName++)
		players.push_back(Player(*pName));
	srand((unsigned int)time(NULL));
	deck.populateDeck();
	deck.shuffleDeck();
}
Game::~Game()
{
}
void Game::startGame()
{
	// роздає кожному по дві карти
	vector<Player>::iterator iPlayer;
	for (int i = 0; i < 2; i++) {
		for (iPlayer = players.begin(); iPlayer != players.end(); iPlayer++)
			deck.dealWithPlayer(*iPlayer);
		deck.dealWithPlayer(dealer);
	}
	// ховає першу карту дилера
	dealer.flipFirstCard();
	// відкриває руки всіх гравців
	cout << "\tHanding out cards..." << endl;
	for (iPlayer = players.begin(); iPlayer != players.end(); iPlayer++)
		cout << *iPlayer << endl;
	cout << dealer << endl << endl;
	// роздає гравцям додаткові карти
	if (players.size() == 1)
		cout << "\tPlayer's move";
	else
		cout << "\tPlayers's move";
	for (iPlayer = players.begin(); iPlayer != players.end(); iPlayer++)
		deck.additionalCards(*iPlayer);
	cout << "\n\tDealer's move";
	// відкриває першу карту дилера
	dealer.flipFirstCard();
	cout << endl << dealer;
	deck.additionalCards(dealer);
	if (dealer.isBusted()) {
		for (iPlayer = players.begin(); iPlayer != players.end(); iPlayer++) {
			if (!(iPlayer->isBusted()))
				iPlayer->playerWins();
		}
	} else {
		// порівнює загальну кількість очок решти гравців з сумою дилера
		for (iPlayer = players.begin(); iPlayer != players.end(); iPlayer++) {
			if (!(iPlayer->isBusted())) {
				if (iPlayer->getTotal() > dealer.getTotal())
					iPlayer->playerWins();
				else if (iPlayer->getTotal() < dealer.getTotal())
					iPlayer->playerLoses();
				else
					iPlayer->playerPushes();
			}
		}
	}
	for (iPlayer = players.begin(); iPlayer != players.end(); iPlayer++) {
		iPlayer->clearHand();
	}
	dealer.clearHand();
}