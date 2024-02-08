// 303hw1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include "functionlist.h"

int main() {
    //declaring variables for array creation
    const std::string filename = "A1input.txt";
    int numberLine[maxSize];
    int size;

    readIn(numberLine, size, filename); //filling the array with the file


    int index = indexCheck(numberLine, size); //calls indexCheck to perform check
    if (index != -1)
    {
        std::cout << "Your number is found in the " << index << " index." << std::endl;
    }

    //Uses user information to call modification funtion and return 2 values
    int modInd;
    int newVal;
    std::cout << "Which index would you like to modify?" << std::endl;
    std::cin >> modInd;

    std::cout << "What value would you like to override with?" << std::endl;
    std::cin >> newVal;
    std::pair<int, int> buddySystem = modifyInt(numberLine, size, modInd, newVal);
    std::cout << "Index [" << modInd << "] has been changed from " << buddySystem.first << " to " << buddySystem.second << std::endl;

    //gets user input to add an integer to the end of the array like pushback function for vectors
    int addInt;
    bool printCheck;
    std::cout << "What number would you like to add to the end of the array?" << std::endl;
    std::cin >> addInt;
    
    std::cout << "Would you like to print your array?" << std::endl;
    std::cin >> printCheck;
    pushClone(numberLine, size, addInt, printCheck);//calls the function.

    //gets user input to select an index for removal
    int delIndex;
    std::cout << "Which index would you like to remove?" << std::endl;
    std::cin >> delIndex;
    removeInt(numberLine, size, delIndex, printCheck); //calls function to remove index

    // Display the updated array
  //  std::cout << "Updated Array: ";
  //  for (int i = 0; i < size; ++i) {
 //       std::cout << numberLine[i] << " ";
  // }
 //   std::cout << std::endl;

    return 0;
}