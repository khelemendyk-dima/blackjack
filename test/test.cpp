/**
 * @file test.cpp
 * @brief Файл з тестами на реалізації функцій: отримання 
 * значення карти, перевертання карти, отримання загальної 
 * кількості очок карт в руці гравця, чи перебрав гравець, 
 * чи бажає користувач взяти карту, перевертання першої карти 
 * дилера.
 *
 * @author Khelemendyk D.
 * @date 15-july-2022
 * @version 0.1
 */
#include <gtest/gtest.h>
#include "game.h"

/*
 * Верифікація роботи функції {@link getValue}
 * на основі вхідних даних карти та очікуваних даних.
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
TEST(Blackjack_card, getValue_test)
{
	Card card(Card::SEVEN, Card::CLUBS);
	int expected_value = 7;
	int actual_value = card.getValue();
	ASSERT_EQ(expected_value, actual_value);
}

/*
 * Верифікація роботи функції {@link flipCard}
 * на основі вхідних даних карти та очікуваних даних.
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
TEST(Blackjack_card, flipCard_test)
{
	Card card(Card::SEVEN, Card::CLUBS);
	// якщо карта схована, то значення карти буде 0
	int expected_value = 0;
	card.flipCard();
	int actual_value = card.getValue();
	ASSERT_EQ(expected_value, actual_value);
}

/*
 * Верифікація роботи функції {@link getTotal}
 * на основі вхідних даних карти, руки та очікуваних даних.
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
TEST(Blackjack_hand, getTotal_test)
{
	Hand hand;
	Card *card = new Card(Card::SEVEN, Card::CLUBS);
	hand.addCard(card);
	int expected_value = 7;
	int actual_value = hand.getTotal();
	ASSERT_EQ(expected_value, actual_value);
}

/*
 * Верифікація роботи функції {@link isBusted}
 * на основі вхідних даних карт, гравця та очікуваних даних.
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
TEST(Blackjack_player, isBusted_test)
{
	Player player;
	Card *card1 = new Card(Card::TEN, Card::CLUBS);
	Card *card2 = new Card(Card::TEN, Card::SPADES);
	Card *card3 = new Card(Card::TEN, Card::HEARTS);
	player.addCard(card1);
	player.addCard(card2);
	player.addCard(card3);
	bool expected_value = true;
	bool actual_value = player.isBusted();
	ASSERT_EQ(expected_value, actual_value);
}

/*
 * Верифікація роботи функції {@link isHittingCard}
 * на основі вхідних даних карти, дилера та очікуваних даних.
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
TEST(Blackjack_dealer, isHittingCard_test)
{
	Dealer dealer;
	Card *card1 = new Card(Card::TEN, Card::CLUBS);
	dealer.addCard(card1);
	bool expected_value = true;
	bool actual_value = dealer.isHittingCard();
	ASSERT_EQ(expected_value, actual_value);
}

/*
 * Верифікація роботи функції {@link flipFirstCard}
 * на основі вхідних даних карти, дилера та очікуваних даних.
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
TEST(Blackjack_dealer, flipFirstCard_test)
{
	Dealer dealer;
	Card *card1 = new Card(Card::TEN, Card::CLUBS);
	dealer.addCard(card1);
	dealer.flipFirstCard();
	// якщо карта схована, то значення карти буде 0
	int expected_value = 0;
	int actual_value = dealer.getTotal();
	ASSERT_EQ(expected_value, actual_value);
}