#include <iostream>
#include <string>

using String = std::string;

class Entity
{
private:
	String m_Name;
public:
	Entity() : m_Name("Unknown") {}
	Entity(const String& name): m_Name(name) {}

	const String& GetName() const { return m_Name; }
};

void CreatingOnStack()
{
	//Entity entity = Entity("AMP");
	//std::cout << entity.GetName() << std::endl;
	Entity* e;
	{
		Entity entity = Entity("ACNPS");
		e = &entity;
		std::cout << entity.GetName() << std::endl;
	}
}

void CreatingOnHeap()
{
	Entity* e;
	{
		Entity* entity = new Entity("AMP0075");
		e = entity;
		std::cout << (*entity).GetName() << std::endl;
		//👆🏻 same as 👇🏻
		std::cout << entity->GetName() << std::endl;
	}
	delete e;
}