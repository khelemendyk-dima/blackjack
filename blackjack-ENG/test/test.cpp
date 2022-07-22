/**
 * @file test.cpp
 * @brief A file with tests of the implementation of functions: 
 * getting the value of a card, flipping a card, getting the 
 * total number of card points in the player's hand, whether 
 * the player has busted, whether the user wants to take a card, 
 * flipping the first dealer's card.
 *
 * @author Khelemendyk D.
 * @date 15-july-2022
 * @version 0.1
 */
#include <gtest/gtest.h>
#include "game.h"

/*
 * Verifying that the {@link getValue} function works based on 
 * the input card's data and the expected data.
 */
TEST(Blackjack_card, getValue_test)
{
	Card card(Card::SEVEN, Card::CLUBS);
	int expected_value = 7;
	int actual_value = card.getValue();
	ASSERT_EQ(expected_value, actual_value);
}

/*
 * Verifying that the {@link flipCard} function works based on 
 * the input card's data and the expected data.
 */
TEST(Blackjack_card, flipCard_test)
{
	Card card(Card::SEVEN, Card::CLUBS);
	// if the card is hidden then the value of card will be 0
	int expected_value = 0;
	card.flipCard();
	int actual_value = card.getValue();
	ASSERT_EQ(expected_value, actual_value);
}

/*
 * Verifying that the {@link getTotal} function works based on 
 * input card's data, hand and expected data.
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
 * Verifying that the {@link isBusted} function works based on 
 * input card's data, player and expected data.
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
 * Verifying that the {@link isHittingCard} function works based 
 * on input card's data, dealer and expected data.
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
 * Verifying that the {@link isHittingCard} function works based 
 * on input card's data, dealer and expected data.
 */
TEST(Blackjack_dealer, flipFirstCard_test)
{
	Dealer dealer;
	Card *card1 = new Card(Card::TEN, Card::CLUBS);
	dealer.addCard(card1);
	dealer.flipFirstCard();
	// if the card is hidden then the value of card will be 0
	int expected_value = 0;
	int actual_value = dealer.getTotal();
	ASSERT_EQ(expected_value, actual_value);
}