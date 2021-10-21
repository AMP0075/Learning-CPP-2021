#include <iostream>
#include <string>

using String = std::string;

class Entity1
{
private:
	String m_Name;
public:
	Entity1() : m_Name("Unknown") {}
	Entity1(const String& name): m_Name(name) {}

	const String& GetName() const { return m_Name; }
};

void CreatingOnStack()
{
	//Entity entity = Entity("AMP");
	//std::cout << entity.GetName() << std::endl;
	Entity1* e;
	{
		Entity1 entity = Entity1("ACNPS");
		e = &entity;
		std::cout << entity.GetName() << std::endl;
	}
}

void CreatingOnHeap()
{
	Entity1* e;
	{
		Entity1* entity = new Entity1("AMP0075");
		e = entity;
		std::cout << (*entity).GetName() << std::endl;
		//👆🏻 same as 👇🏻
		std::cout << entity->GetName() << std::endl;
	}
	delete e;
}