#include <iostream>
#include <array>

void IntegerBasics() {
	int example[5]; //created on stack and is deleted once we're out of the scope
	int debug1 = 1;
	if (debug1) {
		//array is just an integer pointer
		int* ptr = example; //therefore this will compile 

		for (int i = 0; i < 5; i++) {
			example[i] = 2;
		}

		example[2] = 5;
		std::cout << example[0] << std::endl << example[1] << std::endl << example[2] << std::endl << example[3] << std::endl;

		*(int*)((char*)ptr + 8) = 3;
		std::cout << example[0] << std::endl << example[1] << std::endl << example[2] << std::endl << example[3] << std::endl;
	}
	int debug2 = 1;
	if(debug2){
		//creating array using the new keyword
		int* another = new int[5]; //created on heap and will be live until we destroy it
		delete[] another;

		//important
		static const int exampSize = 2;
		int examp[exampSize];
	}
	int debug3 = 1;
	if (debug3) {
		//standard array
		std::array<int, 5> another2; //has balance checks and is more safer but has an overhead because it maintains size
	}
}