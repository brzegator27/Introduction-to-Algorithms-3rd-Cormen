void nl();

template<typename T, typename S>
void printTable(T arr, int arrLength, S splitter);

template<typename T, typename S>
void printTableRange(T arr, int start, int end, S splitter);



//Definitions ----------------------------------------------

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