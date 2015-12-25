#include <iostream>
#include "../util/util.h"

void mergeWithoutSentinel(double arr[], int low, int mid, int high) {
	double *sortedSubArr = new double[high - low + 1];
	int leftSubArrIndex = low,
		rightSubArrIndex = mid + 1,
		sortedSubArrIndex = 0;

	for (; leftSubArrIndex <= mid && rightSubArrIndex <= high; ++sortedSubArrIndex) {
		if (arr[leftSubArrIndex] < arr[rightSubArrIndex]) {
			sortedSubArr[sortedSubArrIndex] = arr[leftSubArrIndex];
			++leftSubArrIndex;
		}
		else {
			sortedSubArr[sortedSubArrIndex] = arr[rightSubArrIndex];
			++rightSubArrIndex;
		}
	}

	if (leftSubArrIndex <= mid) {
		for (; leftSubArrIndex <= mid; ++leftSubArrIndex, ++sortedSubArrIndex) {
			sortedSubArr[sortedSubArrIndex] = arr[leftSubArrIndex];
		}
	}
	else {
		for (; rightSubArrIndex <= high; ++rightSubArrIndex, ++sortedSubArrIndex) {
			sortedSubArr[sortedSubArrIndex] = arr[rightSubArrIndex];
		}
	}

	for (int i = low, j = 0; j <= high - low; ++i, ++j) {
		arr[i] = sortedSubArr[j];
	}
	delete[]sortedSubArr;
}

void mergeSort_2_3_2(double* arr, int low, int high) {
	if (low < high) {
		int q = (low + high) / 2;
		mergeSort_2_3_2(arr, low, q);
		mergeSort_2_3_2(arr, q + 1, high);
		mergeWithoutSentinel(arr, low, q, high);
	}
}

int ex_2_3_2_Main() {
	const int arrLen = 12;
	double tab_1[arrLen] { 1, 12, 31, 2, 12, 412, 123, 123, 12, 41, 145, 1 };

	mergeSort_2_3_2(tab_1, 0, arrLen - 1);
	printTable(tab_1, arrLen, ' ');
	nl();

	return 0;
}