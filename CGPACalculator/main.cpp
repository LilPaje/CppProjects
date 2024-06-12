#include <iostream>

float CGPACalculator(int coursesTaken, float* gradesEarned) 
{
	float CGPA = { 0.0f };
	for (int gradesIndex = 0; gradesIndex <= coursesTaken; gradesIndex++)
	{
		CGPA = {gradesEarned[gradesIndex] + CGPA};
	}
	CGPA = CGPA/coursesTaken;
	return CGPA;
}

void menu() 
{
	std::cout << "--CGPA CALCULATOR--\n";
	std::cout << "Please, insert the number of classes taken: ";
	int numberOfClasses = { 0 };
	std::cin >> numberOfClasses;
	float* listGrades = (float*)malloc(numberOfClasses * sizeof(int));
	for (int indexOfClasses = 0; indexOfClasses < numberOfClasses; indexOfClasses++)
	{
		std::cout << "Please, enter the " << indexOfClasses + 1 << " class grade: ";
		std::cin >> listGrades[indexOfClasses];
	}
	std::cout << "Your CGPA is: " << CGPACalculator(numberOfClasses, listGrades) << std::endl;
	free(listGrades);
}

int main()
{
	menu();
	return 0;
}