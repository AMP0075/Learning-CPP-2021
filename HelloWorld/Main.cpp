#include <iostream>

void Log(const char* message);
void IntegerBasics();
void StringBasics();
void StringOperations1();
void OtherTypes();
void Cons1();
void Cons2();
void ConstCaller();
void MutableLambdas1();
void MIL();
void CreatingOnStack();
void CreatingOnHeap();
void NewKey();

int main() {
	Log("Hello World!");
	IntegerBasics();
	StringBasics();
	StringOperations1();
	OtherTypes();
	Cons1();
	Cons2();
	ConstCaller();
	MutableLambdas1();
	MIL();
	CreatingOnStack();
	CreatingOnHeap();
	NewKey();
	std::cin.get();
}