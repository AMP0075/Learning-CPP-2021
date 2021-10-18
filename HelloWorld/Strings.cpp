#include <iostream>
#include <string>
void StringBasics() {
	const char* name = "AMP";			   //const is usally used because Strings are immutable 
										   //and fixed allocated blocks of memory
	
	//name[1]="K"						   //is invalid
	
	//[NOTE]: untill and unless you use the "new" keyword don't use the "delete" keyword, it is not required
	
	char name2[9] = {'A','M','P','0','0','7','5','\0'};
	std::cout << "name2 = " << name2 << std::endl;

	std::string name3 = "Hola!";
	std::cout << "name3 = " << name3 << std::endl;
	std::cout << "size of name3 = " << name3.size() << std::endl;

	std::string name4 = name3 + name2;		//works because we are adding two strings
	std::cout << "name4 = " << name4 << std::endl;
	std::cout << "size of name4 = " << name4.size() << std::endl;

	//std::string name5 = "AMP" + "BAD";    //Does Not work because we can't add two const char* pointers

	std::string name5 = "AMP";
	name5 += "BAD";							//works because we are adding a pointer to an actual string 
											//i.e., overloading string class is allowed
	
	std::string name6 = std::string("AMP") + "BAD"; //works - same reason as above
}

//instead of this 👉🏻 void PrintString(std::string string) use 👇🏻
void PrintString(const std::string& string){
	//creates no copies on heap hence faster - pass by reference
	//we can avoid using the const if we want to make changes to the original string
	std::cout << string << std::endl;
}

void StringOperations1() {
	//<stringName>.find - returns the position of begining of substring in the actual string
	std::string name = "Hello!";
	//very important 🌟👇🏻
	bool contains = name.find("lo") != std::string::npos; //npos - illegal position for that find 
	PrintString(name);
	std::cout << contains << std::endl;
}

void OtherTypes() {
	const char* name = u8"Hola!";		//u8 - not necessary
	const wchar_t* name1 = L"Hello!";   //wide character - notice the 'L' before the string literal
	const char16_t* name2 = u"Hello!";  //u
	const char32_t* name3 = U"Hello!";  //U

	//wrting ouputs on different lines without using \n or different print statements
	const char* example = R"(Line1
Line2
Line3)";
std::cout << example << std::endl;
}
