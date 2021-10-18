#include <iostream>

void MutableLambdas1() {
	int x = 8;
	auto f = [&]() //pass by reference
	{
		x++;
		std::cout << x << std::endl;
	};
	f();
	std::cout << x << std::endl; //x=9

	int y = 8;
	auto g = [=]() //pass by value - essentialy copies the value and the value 
				   //remains the same after the execution of this lambda
	{
		//y++;     //invalid
		std::cout << y << std::endl;
	};

	int z = 8;
	auto h = [=]() mutable //this allows the modification of variables
	{
		z++;						 //this is the copy of z which can be changed
		std::cout << z << std::endl; //z=9
	};
	h();
	std::cout << z << std::endl;	 //z=8
}