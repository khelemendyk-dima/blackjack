#ifndef PLAYER_H
#define PLAYER_H

/**
 * @file player.h
 * @brief Файл з описом функцій класів "загальний гравець", 
 * "гравець" та "дилер".
 * Клас "загальний гравець": конструктор, деструктор, 
 * чи перебрав гравець, оператор виводу та вивід гравця, котрий 
 * перебрав, на екран.
 * Клас "гравець": конструктор, деструктор, чи бажає гравець 
 * взяти карту, перемога, поразка та нічия.
 * Клас "дилер": конструктор, деструктор, чи бажає дилер 
 * взяти карту та перевертання першої карти.
 * 
 * @author Khelemendyk D.
 * @date 15-july-2022
 * @version 0.1
 */

#include "hand.h"
#include <cctype>

/**
 * Клас "загальний гравець". Відображає загального гравця, котрий 
 * має власне ім'я та деякі методи.
 */
class GenericPlayer : public Hand {
    public:
	GenericPlayer(const string &name = "");
	~GenericPlayer() override;

	virtual bool isHittingCard() const = 0;
	/**
	 * Чи перебрав гравець.
	 *
	 * Функція перевіряє чи загальна сума очок карт у руці 
	 * більше 21.
	 * @return істину якщо гравець перебрав.
	 */
	bool isBusted() const;

	// Вивід гравця, котрий перебрав.
	void playerBusts() const;
	
	/**
	 * Оператор виводу.
	 *
	 * Функція відправляє об'єкт типа GenericPlayer в стандартний 
	 * поток виводу. Друкує ім'я гравця, його карти та загальну 
	 * суму очок.
	 */
	friend ostream &operator<<(ostream &os, const GenericPlayer &genericPlayer);

    protected:
	string playerName;
};
/**
 * Клас "гравець".
 */
class Player : public GenericPlayer {
    public:
	Player(const string &name = "");
	~Player() override;
	/**
	 * Отримання даних щодо бажання гравця продовжити брати карту.
	 *
	 * Якщо загальна кількість очок карт у руці гравця не дорівнює 
	 * 21 - функція запитує чи хоче він взяти карту.
	 * @return істину якщо гравець хоче взяти карту.
	 */
	bool isHittingCard() const override;

	// Оголошення перемоги гравця
	void playerWins() const;
	// Оголошення поразки гравця
	void playerLoses() const;
	// Оголошення нічиї гравця
	void playerPushes() const;
};
/**
 * Клас "дилер".
 */
class Dealer : public GenericPlayer {
    public:
	Dealer(const string &name = "Dealer");
	~Dealer() override;
	/**
	 * Отримання даних щодо бажання дилера продовжити брати карту.
	 *
	 * @return істину якщо загальна кількість очок карт у руці 
	 * дилера менше 17.
	 */
	bool isHittingCard() const override;
	
	/**
	 * Перевертання першої карти.
	 *
	 * Якщо наявні карти - функція перевертає першу.
	 */
	void flipFirstCard();
};
#endif