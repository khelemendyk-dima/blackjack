/**
 * @mainpage
 * # General task
 * Implement the Blackjack card game in the console.
 *
 * @author Khelemendyk D.
 * @date 15-july-2022
 * @version 0.1
 */

/**
 * @file main.cpp
 * @brief A file with a demonstration of functions and methods 
 * of operating them.
 *
 * @author Khelemendyk D.
 * @date 15-july-2022
 * @version 0.1
 */

/**
 * The main function.
 *
 * Sequence of actions:
 * - firstly, I ask the user where to start (start, game rules 
 * or exit) using the {@link introduction} function;
 * - now if the player does not want to finish the program 
 * I start the gameplay;
 * - if the user decided to see the rules of the game I show 
 * them with the function {@link showRulesOfGame};
 * - then I ask players names by calling 
 * function {@link getNamesOfPlayers};
 * - finally, in the while loop I start the game with the 
 * function {@link startGame} and will run it until the user 
 * refuses to resume the gameplay using the function {@link isPlayAgain};
 * - @return the successful return code from the program (0).
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