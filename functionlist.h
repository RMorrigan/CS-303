#pragma once

#include <iostream>
#include <stdexcept>
#include <fstream>

const int maxSize = 150;

void readIn(int arr[], int& size, const std::string & filename) { //This function reads in the file and determines the current capacity of the array
	std::ifstream inputFile(filename);

	if (!inputFile) {
		std::cerr << "Error opening file: " << filename << std::endl;
		exit(1);
	}

	size = 0;
	while (inputFile >> arr[size] && size < maxSize) {
		size++;
	}

	inputFile.close();
};

int indexCheck(const int numberLine[], int& size) //This function takes in the user inputted number and returns which index it is in or neg 1 as error.
{
	int target;
	std::cout << "What number would you like to search for?" << std::endl;
	std::cin >> target;
	for (int i = 0; i < size; i++) {
		if (numberLine[i] == target) {
			return i;
		}
	}
	return -1; //setting to -1 because 0 is a valid index of array
};

std::pair <int, int> modifyInt(int numberLine[], int size, int modInd, int modNum)
{
	try {
		if (modInd >= 0 && modInd < size) //checks if index to modify is in bounds and saves a temporary variable to hold the old value in numberLine
		{
			int tvar = numberLine[modInd];
			numberLine[modInd] = modNum;

			return std::make_pair(tvar, modNum); //makes a pair to return both values to the user
		} 
	}
	catch (std::out_of_range& e) 
	{
		std::cout << e.what();
		std::cerr << "Invalid index selection.\n";
		exit(1);
	}
}


void pushClone(int numberLine[], int& size, int newNum, bool printCheck) //This function takes in a user inputted number and adds it to the end of the array and increments size of array
{
	try
	{
		if (size < maxSize) {
			numberLine[size] = newNum;
			size++;
		}
	}
	catch (std::out_of_range& e)
	{
		std::cout << e.what() << std::endl;
		std::cerr << "Array is full. Increase size before adding further entries."; //error for not enough allocated space
		exit(1);
	}
	if (printCheck == true) //I added a print check for testing and user ease
	{
		std::cout << "Updated Array: ";
		for (int i = 0; i < size; ++i) {
			std::cout << numberLine[i] << " ";
		}
		std::cout << std::endl;
	};
};

void removeInt(int numberLine[], int size, int delIndex, bool printCheck) //This function removes an int at the given index and moves all data forward. Then decrements size.
{
	for (int i = delIndex; i < size - 1; i++)
	{
		numberLine[i] = numberLine[i+1];
	}
	--size;
	if (printCheck == true) //I added a print check for testing and user ease keeps value from first choice
	{
		std::cout << "Updated Array: ";
		for (int i = 0; i < size; ++i) {
			std::cout << numberLine[i] << " ";
		}
		std::cout << std::endl;
	};
}