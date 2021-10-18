#include <iostream>

class Example {
public:
	Example() {
		std::cout << "Created Entity!" << std::endl;
	}

	Example(int x) {
		std::cout << "Created Entity with " << x << "!" << std::endl;
	}
};

class Entity {
private:
	std::string m_Name;
	Example m_Example;
public:	
	//Entity()						//Creates 2 entities
	//{
	//	m_Name = "Unknown 2";
	//	m_Example = Example(8);
	//}
	Entity()						//Creates just 2 entities
		: m_Name("Unknown"), m_Example(8)
	{

	}
	Entity(const std::string& name) 
		: m_Name(name)
	{
		
	}
	
	const std::string& GetName() const { return m_Name; }
};

void MIL() {
	Entity e0;
	std::cout << e0.GetName() << std::endl;
	Entity e1("AMP");
	std::cout << e1.GetName() << std::endl;
}