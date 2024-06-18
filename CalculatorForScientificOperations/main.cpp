/*
4. Calculator for Scientific Operations in C++
The main goal of a Calculator for Scientific Operations is to do simple mathematical computations. 
It also executes a few difficult-to-solve trigonometric and logarithmic functions. The calculator will evaluate any mathematical equation entered using infix notation, 
which will then provide the result. In addition, it supports addition, subtraction, multiplication, and division in mathematics. This calculator allows keyboard entry. 
The C++ class is used to define the data of the Calculator and the various types of functions it can perform such as addition, subtraction, multiplication, division, and modulo.
The project also uses classes that handle different exceptions when an illegal input is received or when an operation results in a singular value, such as an imaginary number. 
The technology used for this program was object-oriented programming which provided the flexibility necessary for the implementation of the various operations.

Technologies Required: C++ programming language, Data structures, and Algorithms, Math library in C++, and OOPS.
*/

/*
Big Anxiety:   1- Making a Infix Evaluetor
Small Anxiety: 1.1- Getting the string value of the infix expression - Check
Small Anxiety: 1.2- Ordenating the operators
Smaller Anxi.: 1.2.2- Creating a ordened list with the operations to be evaluated first
Small Anxiety: 1.3 - Create a object numbers  with the "to be" evaluated numbers
*/

#include <iostream>
#include <stack>
#include <string>

int checkPriority(char op) { //this piece of code check the priority of the operators
	if (op == '*')      return 2;
	else if (op == '/') return 2;
	else if (op == '+') return 1;
	else if (op == '-') return 1;
	return 0;
}

int evaluate(int num1, int num2, char op) {
	if (op == '*')      return num1 * num2;
	else if (op == '/') return num1 / num2;
	else if (op == '+') return num1 + num2;
	else if (op == '-') return num1 - num2;
}

//int convertStringToNumber

int Calculate(std::string expression) {
	std::stack <int> numbers;
	std::stack <char> operators;
	int number{ 0 };
	for (int i{ 0 }; i <= expression.length(); i++) {
		//std::cout << "Debug";
		if (isdigit(expression[i])) { //this piece of code makes the char into int *magic*
			number = 0;
			while (isdigit(expression[i])) {
				if (number == 0) {
					number = int(expression[i]) - 48;
					i++;
					continue;
				}

				number = number * 10 + (expression[i] - '0');
				i++;
			}
			numbers.push(number);
		}
		else {
			if (!operators.empty() && checkPriority(expression[i]) == checkPriority('*')) {
				//to implement
			}
			operators.push(expression[i]);
		}
	}
	while (numbers.size() > 1) {
		//to implement
	}
	return number;
}

int main() {
	std::string expression{};
	std::cout << "--Calculator--\nInsert the Expression:\n->";
	std::cin >> expression;

	//std::cout << 
	std::cout << Calculate(expression);

	/*std::stack <int> numbers;
	std::stack <std::string> operators;

	for (int i{ 0 };i <= expression.length(); i++) {
		std::cout << expression[i] << std::endl;

	}*/


	return 0;
}