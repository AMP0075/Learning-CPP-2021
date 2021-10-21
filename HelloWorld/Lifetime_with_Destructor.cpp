#include <iostream>

class Entity4 {
public:
	Entity4(){
		std::cout << "Created Entity4!" << std::endl;
	}
	~Entity4() {
		std::cout << "Destroyed Entity4!" << std::endl;
	}

};

int* CreateArray1() {
	int array[50];
	return array;
}

int* CreateArray2() {
	int* array = new int[50];
	return array;
}

void CreateArray3(int* array2) {
	//maybe fill our array
}

void ObjectLifetime() {
	{
		Entity4 e;
	}

	{
		Entity4* e1 = new Entity4;
	}

	//int* a = CreateArray1();		//invalid - because the array being created is present on 
									//stack and it no longer exists when function ends (returns value)

	int array2[50];
	CreateArray3(array2); //this is a classic mistake - we're creating a stack based variable and 
						  //returning a pointer to it. Once the function ends the variable no longer exists
	
}