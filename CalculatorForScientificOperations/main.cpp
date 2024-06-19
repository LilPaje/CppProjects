#include <iostream>
#include <stack>
#include <string>

int checkPriority(char op) { //this piece of code check the priority of the operators
	if      (op == '*') return 2;
	else if (op == '/') return 2;
	else if (op == '+') return 1;
	else if (op == '-') return 1;
	return -1;
}

int evaluate(int num1, int num2, char op) { //evaluate the expression based on the operator ~op~
	if      (op == '*') return num1 * num2; 
	else if (op == '/') return num1 / num2;
	else if (op == '+') return num1 + num2;
	else if (op == '-') return num1 - num2;
	else return -1;
}

int Calculate(std::string expression) { //here's where the magic happens
	std::stack <int> numbers;           //defining both stack of numbers and operators
	std::stack <char> operators;
	
	for (int i{ 0 }; i <= expression.length(); i++) {
		if (isdigit(expression[i])) {               //this piece of code makes the char into int *magic*
			int number{ 0 };
			while (isdigit(expression[i])) {        //here we check every digit before the next operator
				if (number == 0) {                  
					number = expression[i] - '0';   //and we cast it from char to int with this statement
					i++;
					continue;
				}

				number = number * 10 + (expression[i] - '0'); //we have to do this lil trick since we're getting the number starting on the highest pow of 10 and going to the lowest
				i++;;
			}
			numbers.push(number);
			i--;                                             //at the end, this freak finishes at the next number, jumping the operator, so we have to subtract the index to 
			                                                 //get back to the operator
		}
		else if (expression[i] == '*' || expression[i] == '/' || expression[i] == '+' || expression[i] == '-') { //here we check if the character we're in is a operator
			                                                                                                     //note: Since, "cin" creates a list of characters where the 
																												 //last one is an empty character, indicating that the string 
																												 //ended, we chave to check with this giant
			                                                                                                     //piece of crap i made. There are probably much better 
																												 //ways to do this, but i'm dumb :D 
			
			
			operators.push(expression[i]); //so here is where the real magic begins.
			if (checkPriority(expression[i]) == checkPriority('*')) { //since in math we first evaluate multiplications and divisions, we'll first evaluate that and push
				i++;                                                  // the result to the stack
				int number{ 0 };				
				while (isdigit(expression[i])) {                      //after an "*" or "/" is identified, we have to look to the next number...
					if (number == 0) {                                //Yeah bro i broke about the DRY stuff, but i didn't come up with something better, sorry Mr. Bjarne, 
														              //for i have sinned
						number = expression[i] - '0';
						i++;
						continue;
					}
					number = number * 10 + (expression[i] - '0');
					i++;
				}
				i--;                                                  //It's pretty much the same logic, so, check line 26
				int num1{ numbers.top() };                            //now, here's some math: first-> take the top number, save it into a variable
				numbers.pop();                                        //delete the bad boy from the stack
				char op{ operators.top() };                           //same thing for operators stack
				operators.pop();                                      //delete it
				numbers.push(evaluate(num1, number,op));              //use the evaluate function to calculate the result of the equation, than, save it on the top of stack
				}
			
		}
	}
	while (numbers.size() > 1) {                        //now, since we cleared the mult. and division ops, we only have the sum and sub. on the stack, let's clear ir up too.
		int num2{ numbers.top() };                      //remember we're on a stack, so the top number will be the last one add, tha'ts why we have to first take the 2nd and pop it
		numbers.pop();                                  //delete the bad boy
		int num1{ numbers.top() };;                     //now take the first num
		numbers.pop();                                  //delete it again
		char op{ operators.top() };                     //operator
		operators.pop();                                //delete it
		numbers.push(evaluate(num1, num2, op));		    //calculate the bad boy and put it to the stack. Repeat that until we have only 1 bad boy on the stack, which is our result 
	}
	return numbers.top();                               //return the result to the code
}

int main() {
	std::string expression{};
	std::cout << "--Calculator--\nInsert the Expression:\n->";
	std::cin >> expression;

	//std::cout << 
	std::cout << "Result: " << Calculate(expression) << std::endl;

	/*std::stack <int> numbers;
	std::stack <std::string> operators;

	for (int i{ 0 };i <= expression.length(); i++) {
		std::cout << expression[i] << std::endl;

	}*/


	return 0;
}