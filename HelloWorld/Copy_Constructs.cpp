#include <iostream>
#include <string>

class String
{
private:
	char* m_Buffer;
	unsigned int m_Size;
public:
	String(const char* string)
	{
		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, string, m_Size);
		m_Buffer[m_Size] = 0;
	}

	String(const String& other)
		:m_Size(other.m_Size)
	{
		std::cout << "Copied Stirng" << std::endl;
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
		m_Buffer[m_Size] = 0;
	}

	char& operator[](unsigned index)
	{
		return m_Buffer[index];
	}

	~String()
	{
		delete[] m_Buffer;
	}

	

	friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

//[NOTE]: Important 👇🏻
std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.m_Buffer;
	return stream;
}

//void PrintString(String string)			//if we do this 3 copies will be created for copying 
void PrintString(const String& string)		//String& - passing reference, ensures no unecessary overhead
											//const	  - ensures that the string is not modified in this function
{
	std::cout << string << std::endl;
}

void CopyConst() {
	String string1 = "AMP";
	String string2 = string1;
	
	string2[1] = 'O';

	PrintString(string1);
	PrintString(string2);
}