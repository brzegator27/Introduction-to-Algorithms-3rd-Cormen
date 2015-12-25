#include <iostream>
#include "../util/util.h"

void merge(double* arr, int low, int mid, int high) {
	int nLeft = mid - low + 1,
		nRight = high - mid;
	double *duplicatedArrLeft = new double[nLeft + 1],
		*duplicatedArrRight = new double[nRight + 1];

	for (int i = 0; i < nLeft; ++i) {
		duplicatedArrLeft[i] = arr[low + i];
	}
	for (int j = 0; j < nRight; ++j) {
		duplicatedArrRight[j] = arr[mid + 1 + j];
	}

	duplicatedArrLeft[nLeft] = std::numeric_limits<double>::infinity();
	duplicatedArrRight[nRight] = std::numeric_limits<double>::infinity();

	int i = 0,
		j = 0;
	for (int k = low; k <= high; ++k) {
		if (duplicatedArrLeft[i] <= duplicatedArrRight[j]) {
			arr[k] = duplicatedArrLeft[i];
			++i;
		}
		else {
			arr[k] = duplicatedArrRight[j];
			++j;
		}
	}

	delete[]duplicatedArrLeft;
	delete[]duplicatedArrRight;
}

void mergeSort(double* arr, int low, int high) {
	if (low < high) {
		int q = (low + high) / 2;
		mergeSort(arr, low, q);
		mergeSort(arr, q + 1, high);
		merge(arr, low, q, high);
	}
}

int mergeSortMain() {
	const int arrLen = 12;
	double tab_1[arrLen] { 1, 12, 31, 2, 12, 412, 123, 123, 12, 41, 145, 1 };

	mergeSort(tab_1, 0, arrLen - 1);
	printTable(tab_1, arrLen, ' ');
	nl();

	return 0;
}