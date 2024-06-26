/*
The login And Registration System project in C++ involves mainly the user registration process. User Credentials like usernames and passwords are 
asked from the user. If the registration of the user is successful then with the given credentials a file will be created of a particular user in the 
database.

Technologies Required: C++ programming language, User Input/Output Libraries, File Manipulation Libraries, Strings and Structures Libraries and Database 
Libraries.
*/


#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

void hideInput() {
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(hStdin, &mode);
	SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
}

bool loginUser() {
	bool auth = { 0 };
	std::string username;
	std::string password;

	for (int i = 0; i < 3; i++) 
	{
		std::cout << "Username:\n-> ";
		std::cin >> username;
		std::cout << "Password:\n-> ";
		std::cin >> password;

		std::ifstream file;
		username = username + ".txt";
		file.open(username);
		if (file.good()) {
			std::string fLine;
			std::getline(file, fLine);
			if (fLine == password) {
				auth = 1;
				break;
			}
		}
		std::cout << "Wrong User or Password...\n";
	}
	return auth;
}

void registerUser() {
	std::string* userPass = new std::string[2];

	std::string username;
	std::string password;
	std::string confirmation;
	while(1)
	{
		std::cout << "Create your username:\n-> ";
		std::cin >> username;

		std::cout << "Create your password:\n-> ";
		std::cin >> password;
		
		std::cout << "Confirm your password:\n-> ";
		std::cin >> confirmation;
		if (confirmation == password)
		{
			break;
			userPass[0] = username;
			userPass[1] = password;
		}
		std::cout << "The Password didn't match the Confirmation, please try again\n";		
	}
	std::cout << "Created!" << std::endl;
	username = username + ".txt";
	std::ofstream file(username);
	file << password;
}


int main() {
	hideInput();
	while (1) {
		char user;
		std::cout << "--Welcome to Login/Register System--\n";
		std::cout << "[1] For Login; [2] For Register; [3] Shut Down the Program\n-> ";
		std::cin >> user;
		if (user == '1')
		{
			bool auth = loginUser();
			if (auth) {
				std::cout << "Access Granted" << std::endl;
			}
			else {
				std::cout << "Access Denied!" << std::endl;
			}
		}
		else if (user == '2')
		{
			registerUser();
		}
		else if (user == '3')
		{
			std::cout << "Bye Bye!" << std::endl;
			break;
		}
		else
		{
			std::cout << "Invalid Input! Try again: \n";
			continue;
		}

	}
	return 0;
}


//using namespace std;

//int main()
//{
//	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
//	DWORD mode = 0;
//	GetConsoleMode(hStdin, &mode);
//	SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
//
//	std::string s;
//	std::getline(std::cin, s);
//
//	std::cout << s << std::endl;
//	return 0;
//}//main 