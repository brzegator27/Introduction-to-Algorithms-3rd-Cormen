void nl();

template<typename T, typename S>
void printTable(T arr, int arrLength, S splitter);




//Definitions ----------------------------------------------

template<typename T, typename S>
void printTable(T arr, int arrLength, S splitter) {
	for (int i = 0; i < arrLength; i++) {
		std::cout << arr[i] << splitter;
	}
}