#include <iostream>
#include <string>

struct Vector3
{
	float x, y, z;
};

class Entity7 
{
public:
	void Print() const { std::cout << "Hello!" << std::endl; }
};

class ScopedPtr2
{
private:
	Entity7* m_Obj;
public:
	ScopedPtr2(Entity7* entity)
		: m_Obj(entity)
	{
	}
	~ScopedPtr2()
	{
		delete m_Obj;
	}

	Entity7* operator->() 
	{
		return m_Obj;
	}

	const Entity7* operator->() const
	{
		return m_Obj;
	}
};

void ArrowBasics() {
	Entity7 e;
	e.Print();

	Entity7* ptr = &e;
	//Entity7& entity = *ptr;
	//(*ptr).Print(); 
	//		or
	ptr->Print();

	const ScopedPtr2 entity = new Entity7();
	entity->Print();


	int offset = (int)&((Vector3*)nullptr)->x;
	std::cout << offset << std::endl;				//prints 0 
	int offset2 = (int)&((Vector3*)nullptr)->y;
	std::cout << offset2 << std::endl;				//prints 4
	int offset3 = (int)&((Vector3*)nullptr)->z;
	std::cout << offset3 << std::endl;				//prints 8

	// nullptr = 0
	// (Vector3*)nullptr
	// ((Vecotor3*)nullptr)->x
	// &((Vecotor3*)nullptr)->x
	// (int)&((Vecotor3*)nullptr)->x


}