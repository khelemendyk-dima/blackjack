/**
 * @mainpage
 * # Загальне завдання
 * Реалізувати карткову гру Blackjack у консолі.
 *
 * @author Khelemendyk D.
 * @date 15-july-2022
 * @version 0.1
 */

/**
 * @file main.cpp
 * @brief Файл з демонстрацією роботи функцій
 * та методів оперування ними.
 *
 * @author Khelemendyk D.
 * @date 15-july-2022
 * @version 0.1
 */

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - спочатку запитую у користувача з чого почати(старт, правила 
 * гри чи вихід) за допомогою функції {@link introduction};
 * - тепер якщо гравец не хоче завершити програму - починаю ігровий процес;
 * - якщо користувач вирішив ознайомитися з правилами гри - показую 
 * їх функцією {@link showRulesOfGame};
 * - потім запитую у гравців їхні імена шляхом виклику 
 * функції {@link getNamesOfPlayers};
 * - нарешті у циклі while запускаю гру функцією {@link startGame} 
 * та буду виконувати її доки користувач не відмовиться відновлювати 
 * ігровий процес за допомогою функції {@link isPlayAgain};
 * - @return успішний код повернення з програми (0).
 */

#include "game.h"

int main()
{
	Action action = introduction();
	if (action != END) {
		if (action == RULES)
			showRulesOfGame();
		cout << "\t\tBLACKJACK\n\n";
		vector<string> names;
		getNamesOfPlayers(names);
		Game game(names);
		bool playAgain = true;
		while (playAgain) {
			game.startGame();
			playAgain = isPlayAgain();
		}
	}
	cout << "\nGoodbye!!!" << endl;
	return 0;
}