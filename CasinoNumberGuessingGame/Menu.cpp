#include "Casino.cpp"
#include <iostream>
class Menu 
{
	public: 
		Menu()
		{
			int playerNumber = { 0 };
			std::cout << "---Casino---\n";
			std::cout << "Chose a number betwen 1 and 10:\n-> ";
			std::cin >> playerNumber;
			if (Casino::guessingGame(playerNumber)){std::cout << "Player Wins!" << std::endl;}
			else { std::cout << "Wrong Number..." << std::endl; }
		}
};