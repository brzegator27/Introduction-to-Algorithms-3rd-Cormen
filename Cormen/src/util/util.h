#include <array>

void nl();

template<typename T, std::size_t SIZE, typename SPLITTER>
void printTable(std::array<T, SIZE> arr, SPLITTER splitter);

template<typename T, typename S>
void printTable(T arr, int arrLength, S splitter);

template<typename T, typename S>
void printTableRange(T arr, int start, int end, S splitter);



//Definitions ----------------------------------------------

template<typename T, std::size_t SIZE, typename SPLITTER>
void printTable(std::array<T, SIZE> arr, SPLITTER splitter) {
	for (size_t i = 0; i < arr.size(); ++i) {
		std::cout << arr[i] << splitter;
	}
}

template<typename T, typename S>
void printTable(T arr, int arrLength, S splitter) {
	for (int i = 0; i < arrLength; ++i) {
		std::cout << arr[i] << splitter;
	}
}

template<typename T, typename S>
void printTableRange(T arr, int start, int end, S splitter) {
	if (end < start) {
		throw std::out_of_range("You try to write down array but You passed invalid range!");
	}
	for (int i = start; i <= end; ++i) {
		std::cout << arr[i] << splitter;
	}
}