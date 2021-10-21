#include <iostream>

class Entity5 {
public:
	Entity5() {
		std::cout << "Created Entity5!" << std::endl;
	}
	~Entity5() {
		std::cout << "Destroyed Entity5!" << std::endl;
	}

};

class ScopedPointer {
private:
	Entity5* m_Ptr;
public:
	ScopedPointer(Entity5* ptr)
		:m_Ptr(ptr)
	{
	}

	~ScopedPointer()
	{
		delete m_Ptr;
	}
};

void ScopedPtr()
{
	{
		//this has a scope within these curly braces even though it is a heap allocation
		ScopedPointer e = new Entity5();
	}
}