#include <iostream>
#include <string>

//only accessible to us through a member function (a function belonging to a class or a method)
//a pointer to the current object instance that the method belongs to

//void PrintEntity2_1(const Entity2* e);

//void PrintEntity2_2(const Entity2& e);

class Entity2 {
public:
	int x, y;
	Entity2(int x, int y) {
		Entity2* e3 = this;

		this->x = x; //this->x	=> the first x not the one that is passed 
					 //x=x => we are not doing anything. We are just assigning the parameter x, it's own value
		this->y = y; //same as (*this).y = y;

		//PrintEntity2_1(this);
		//PrintEntity2_2(*this);

		//delete this  //don't do this 
	}
	//or we could do this
	//Entity(int x, int y)
	//	:x(x), y(y)
	//{}

	//[NOTE]: 'this' - it is a Entity* (hover mouse over 'this')  [in video 42 - it says - Entity *const this]

	int GetX() const
	{
		const Entity2* e4 = this;
		//e4->x = 5;  //invalid because we made it a const
		return x;
	}

};

//Another useful case for 'this'
//if we wanted to call a function outside the Entity2 class from within this class that took entity3 as a parameter

//First way
//void PrintEntity2_1(const Entity2* e)
//{
//}

//Second way
//void PrintEntity2_2(const Entity2& e)
//{
//}
