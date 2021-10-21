#include <iostream>

class Example {
public:
	Example() {
		std::cout << "Created Entity0!" << std::endl;
	}

	Example(int x) {
		std::cout << "Created Entity0 with " << x << "!" << std::endl;
	}
};

class Entity0 {
private:
	std::string m_Name;
	Example m_Example;
public:	
	//Entity0()						//Creates 2 entities
	//{
	//	m_Name = "Unknown 2";
	//	m_Example = Example(8);
	//}
	Entity0()						//Creates just 2 entities
		: m_Name("Unknown"), m_Example(8)
	{

	}
	Entity0(const std::string& name) 
		: m_Name(name)
	{
		
	}
	
	const std::string& GetName() const { return m_Name; }
};

void MIL() {
	Entity0 e0;
	std::cout << e0.GetName() << std::endl;
	Entity0 e1("AMP");
	std::cout << e1.GetName() << std::endl;
}