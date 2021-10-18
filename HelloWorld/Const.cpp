#include <iostream>

class Entity {
private:
	int m_X, m_Y;

	//say we wanted pointers
	int* m_P, m_Q; //[NOTE]: Here m_P is a pointer but m_Q is just an integer

	int *m_A, *m_B; //Here both m_A and m_B are pointers

	mutable int var;

public:
	int GetX() const{ //this const ensures that the variables are not modified when we call this Get function
		//m_X = 10;	  //invalid	
		var = 3;	  //valid because we used the mutable keyword
		return m_X;
	}

	int GetX() {	  //if we don't use const we can modify the values
		m_X = 10;
		return m_X;
	}
	
	int SetX(int x) {
		m_X = x;
	}

	const int* const GetP() const { //this means that we're returning a ptr which can't be modified; [first const]
									//the contents of this ptr cannot be modified; [second const]
									//and the method itself, i.e., the code inside GetP does not modify the actual entity class [third const]
		return m_P;
	}
};


void PrintEntity(const Entity& e) { //const Entity& - pass by reference ensures we cannot modify the contents of e
	//[NOTE] : If we reassign the reference e (e = Entity(); or e = nullptr;), we are actually changing this object
	//		   There is no seperation b/w a ptr and the contents of a ptr, because they are essentially same

	//this function uses the GetX() with const
	std::cout << e.GetX() << std::endl;
}

void ConstCaller() {
	Entity e;
	PrintEntity(e);
}

void Cons1() {
	const int MAX_AGE = 90;
	
	const int* a = new int;				//same as - int const* a = new int;
										//[NOTE]: Here we're making the variable a constant, i.e., the value but 
										//		  not the m/m pointed by the pointer. Therefore we can change the
										//		  the m/m to which the pointer points.
	
	//*a = 2;							//invalid - we can't change the contents of the pointer (the m/m location)
	
	
	a = nullptr;						//nullptr - provided default by C++


	a = (int*)2; // a=00000002
	a = (int*)10;// a=0000000A			//this means that the value is stored in Hex format
	//std::cout << *a << std::endl;		//Exception thrown: read access violation
	std::cout << a << std::endl; 


	//[NOTE]: We can change the m/m pointed to by a const pointer and thus break the notion of const
	a = (int*)&MAX_AGE;
	std::cout << *a << std::endl;

	std::cout << MAX_AGE << std::endl;
}

void Cons2() {
	const int MAX_AGE = 90;
	
	int* const a = new int;		//[NOTE]: Here we're making the m/m pointed by the pointer as constant
	
	*a = 2;	//valid - we can change the contents of the pointer (the m/m location)
	
	//a = (int*)2; 
	//a = (int*)10; //invalid - we can't reassign the pointer itself
	std::cout << a << std::endl; //prints m/m location unlike 00000002 in Cons1
	std::cout << *a << std::endl;

	//a = (int*)&MAX_AGE; //invalid - we can't reassign the pointer itself
	std::cout << *a << std::endl;
}

void Cons3() {
	const int* const a = new int;
	//[NOTE]: Here we're making both the m/m location as well as the value of m/m location a constant


	//In this case these are invalid 👇🏻
	//*a = 2;
	//a = (int*)2;
	//a = nullptr;
}