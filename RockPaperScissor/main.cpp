/*
Stone Paper Scissor or Rock Paper Scissor is a game that is played between two people, Each player in this game forms one of three shapes. The winner will be decided as per the given rules:

Rock vs Scissor -> Rock wins
Rock vs Paper -> Paper wins
Paper vs Scissor -> Scissor wins
In this game, the user is asked to make choices based on both computer and user choices and the results are displayed showing both computer and user choices.

*/

// Rock    = 0
// Paper   = 1
// Scissor = 2
#include <iostream>
#include <ctime>
#include <cstdlib>

int pcChoice()
{
	srand((unsigned)time(0));
	int i;
	i = (rand() % 3);
	return i;
}

void game(int pcChoice)
{
	std::cout << "Insert your choice\n[0]Rock\n[1]Paper\n[2]Scissor\n-> ";
	int playerChoice = { 0 };
	std::cin >> playerChoice;
	if (pcChoice == 0)
	{
		std::cout << "Rock (PC) vs ";
		if (playerChoice == 0) 
		{ 
			std::cout << "Rock (Player)\n";
			std::cout << "Draw" << std::endl;
			
		}

		else if (playerChoice == 1) 
		{ 
			std::cout << "Paper (Player)\n";
			std::cout << "Player Wins" << std::endl; 
			
		}
		else if (playerChoice == 2) 
		{ 
			std::cout << "Scissor (Player)\n";
			std::cout << "PC Wins" << std::endl; 
			
		}
	}
	else if (pcChoice == 1)
	{
		std::cout << "Paper (PC) vs ";
		if (playerChoice == 1) 
		{ 
			std::cout << "Paper (Player)\n";
			std::cout << "Draw" << std::endl; 
			
		}
		else if (playerChoice == 2) 
		{ 
			std::cout << "Scissor (Player)\n";
			std::cout << "Player Wins" << std::endl; 
			
		}
		else if (playerChoice == 0) 
		{ 
			std::cout << "Rock (Player)\n";
			std::cout << "PC Wins" << std::endl; 
			
		}
	}
	else if (pcChoice == 2)
	{
		std::cout << "Scissor (PC) vs ";
		if (playerChoice == 2) 
		{ 
			std::cout << "Scissor (Player)\n";
			std::cout << "Draw" << std::endl; 
		}
		else if (playerChoice == 0) 
		{ 
			std::cout << "Rock (Player)\n";
			std::cout << "Player Wins" << std::endl; 
		}
		else if (playerChoice == 1) 
		{ 
			std::cout << "Paper (Player)\n";
			std::cout << "PC Wins" << std::endl; 
		}
	}
}


int main() 
{
	//defining the random number
	std::cout << "--Rock-Paper-Scissor-- \n";
	bool playAgain = { 1 };
	while (playAgain) 
	{
		game(pcChoice());

		std::cout << "Play again?\n[0]No\n[1]Yes\n-> ";
		std::cin >> playAgain;

	}
	
	

	//std::cout << i << std::endl; //printing the random number



	return 0;
}