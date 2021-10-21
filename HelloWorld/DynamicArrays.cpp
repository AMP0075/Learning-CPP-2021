#include <iostream>
#include <string>
#include <vector>

struct Vertex
{
	float x, y, z;
	Vertex(float x, float y, float z)
		: x(x), y(y), z(z)
	{

	}
	Vertex(const Vertex& vertex)
		:x(vertex.x), y(vertex.y), z(vertex.z)
	{
		std::cout << "Copied!\t{" << vertex.x << "," << vertex.y << "," << vertex.z << "}\n" << std::endl;
	}
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex) 
{
	stream << vertex.x << "," << vertex.y << "," << vertex.z;
	return stream;
}

void SomeFunction(const std::vector<Vertex>& vertices) 
//Always remember to pass as a reference - ensuring we're not copying the entire array or struct
{

}

void DynamicArrayBasics()
{
	//Vertex* vertices = new Vertex[10];
	
	std::vector<Vertex> vertices2;

	//in this case 6 copying operations will take place
	//	1 - {1,2,3} passed from main to constructor			[execution of line 45]
	//	2 - {4,5,6} passed from main to constructor			[execution of line 46]
	//	3 - {1,2,3} copied to new location					[execution of line 46]
	//	4 - {6,7,8} passed from main to constructor			[execution of line 47]
	//	5 - {1,2,3} copied to new location					[execution of line 47]
	//	6 - {4,5,6} copied to new location					[execution of line 47]
	vertices2.push_back({ 1, 2, 3 });
	vertices2.push_back({ 4, 5, 6 });
	vertices2.push_back({ 6, 7, 8 });
	for (Vertex& v : vertices2) {			//[NOTE]: We can do Vertex v : vertices2 but it will be more expensive
		std::cout << v << std::endl;
	}

	std::vector<int> vertices3;
	vertices3.push_back({ 101 });
	vertices3.push_back({ 924 });
	vertices3.push_back({ 341 });
	
	for (int v2 : vertices3) {
		std::cout << v2 << std::endl;
	}

	vertices2.erase(vertices2.begin() + 1);	//[NOTE]: We need to pass in an iterator for erase function
											// so to remove second element {4, 5, 6}, we need to do this
	std::cout << "\nPrinting vertices2 after erase operation" << std::endl;
	for (Vertex& v2 : vertices2) {
		std::cout << v2 << std::endl;
	}
}

void OptimizeVector1() {
	std::vector<Vertex> vertices;
	vertices.reserve(3);			//reserves m/m so that multiple copying during each operation can be avoided
	vertices.push_back({ 1, 2, 3 });
	vertices.push_back({ 4, 5, 6 });
	vertices.push_back({ 7, 8, 9 });

	//[NOTE]: push_back can be implemented using <varName>.push_back({ ..data.. });
	//			and also using <varName>.push_back(<DataType>(..data..));

	std::cout << "\nPrinting vertices with some optimization" << std::endl;
	for (const Vertex& v : vertices) {
		std::cout << v << std::endl;
	}
}

void OptimizeVector2() {
	//completely removing unnecessary copying

	std::vector<Vertex> vertices;
	vertices.reserve(3);
	
	//[NOTE]: emplace_back can be implemented using <varName>.emplace_back(<DataType>(..data..));
	
	vertices.emplace_back(Vertex(1, 2, 3)); //"insert by perfectly forwarding into element at end, provide strong guarantee"
	vertices.emplace_back(Vertex(4, 5, 6)); 
	vertices.emplace_back(Vertex(7, 8, 9)); 
	std::cout << "\nPrinting vertices with more optimization" << std::endl;
	for (const Vertex& v : vertices) {
		std::cout << v << std::endl;
	}
}

void DynamicArray() {
	DynamicArrayBasics();
	OptimizeVector1();
	OptimizeVector2();
}