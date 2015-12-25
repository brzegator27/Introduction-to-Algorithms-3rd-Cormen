#include <iostream>
#include "allHeaders.h"

/**
 * Defining NOMINMAX before including windows.h solves the problem of
 * unfortunate max macro definition in minwindef.h
 * Solution to the problem was introduced at: 
 * http://stackoverflow.com/questions/14657474/conflict-of-windows-h-and-limits.
*/
#define NOMINMAX
/**
 * Header from Visula Leak Detector, more on:
 * http://vld.codeplex.com/
*/
#include <vld.h>

int main() {
	//insertionSortMain();
	//mergeSortMain();
	ex_2_3_2_Main();

	std::cout << "\n" << "Press ENTER to continue...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}