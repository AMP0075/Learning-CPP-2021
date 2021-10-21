#include <iostream>
#include <string>

using String = std::string;

class Entity1
{
private:
	String m_Name;
public:
	Entity1() : m_Name("Unknown") {};
	Entity1(const String& name) : m_Name(name) {};

	const String& GetName() const { return m_Name; }
};

void NewKey() {
	int a = 2;
	int* b = new int; //dynamic allocation on heap - 4 bytes
	int* c = new int[50];//200 bytes

	Entity1* e = new Entity1(); //not only allocate m/m on heap to store this entity but also call the constructor
	//in C - Entity* e = (Entity*)malloc(sizeof(Entity)); -> does not call the constructor

	delete e; //[NOTE]: We must use delete when we use new
	delete[] c; //[NOTE]: The square brackets here
	delete b;

	Entity1* e1 = new Entity1[50]; //creates an array in heap. Contiguous m/m locations
	delete[] e1;

	//Entity1* e2 = new(c) Entity1(); //placement new - let's us decide where the m/m comes from
									//we instantiate our m/m address in a specific m/m location

	//delete e2;
}