#include <iostream>
#include "../util/util.h"

void insertionSort(int* arr, int arrLength) {
	int key,
		currentIndex;

	for (int i = 1; i < arrLength; i++) {
		key = arr[i];
		currentIndex = i - 1;
		while (currentIndex >= 0 && arr[currentIndex] > key) {
			arr[currentIndex + 1] = arr[currentIndex];
			currentIndex--;
		}
		arr[currentIndex + 1] = key;
	}
}

void insertionSortInverse(int* arr, int arrLength) {
	int currentIndex,
		key;

	for (int i = 1; i < arrLength; i++) {
		key = arr[i];
		currentIndex = i - 1;
		while (currentIndex >= 0 && arr[currentIndex] < key) {
			arr[currentIndex + 1] = arr[currentIndex];
			currentIndex--;
		}
		arr[currentIndex + 1] = key;
	}
}

int* addTwoBinaryIntegers(int* numb1, int* numb2, int numbsLength) {
	int* additionResult = new int(numbsLength + 1),
		currentSum = 0;

	for (int i = numbsLength - 1; i >= 0; i--) {
		currentSum = numb1[i] + numb2[i] + currentSum;
		additionResult[i + 1] = currentSum % 2;
		//currentSum = currentSum > 1 ? 1 : 0;
		currentSum -= currentSum % 2;
		currentSum /= 2;
	}
	additionResult[0] = currentSum;

	return additionResult;
}

int insertionSortMain() {
	char nl[1] = { '\n' };
	int tab_1[6] = { 1, 12, 31, 2, 12, 412 };

	insertionSort(tab_1, 6);
	printTable(tab_1, 6, ' ');
	
	printTable(nl, 1, "");

	insertionSortInverse(tab_1, 6);
	printTable(tab_1, 6, ' ');

	printTable(nl, 1, "");

	int tab_2[3] = { 1, 1, 1 };
	int tab_3[3] = { 0, 1, 1 };
	int* additionResult = addTwoBinaryIntegers(tab_2, tab_3, 3);
	printTable(additionResult, 4, " ");

	return 0;
}