#include <iostream>
#include <string>
#include <memory>

//Smart Pointers help in automating the 'new' and 'delete' operators
//they are a wrapper around a real 'raw pointer'

class Entity6 {
public:
	Entity6()
	{
		std::cout << "Created Entity6" << std::endl;
	}
	~Entity6() 
	{
		std::cout << "Destroyed Entity6" << std::endl;
	}

	void Print() 
	{

	}
};

//unique smart pointer - simplest
	//it is a scoped pointer
	//cannot be copied or shared
void UniquePtr() {
	{
		std::unique_ptr<Entity6> entity(new Entity6()); //no implicit conversion present, we need to call it explicitly
		//std::unique_ptr<Entity6> e0 = entity;			//invalid - since copying is not allowed

		entity->Print();
	}

	{
		std::unique_ptr<Entity6> entity = std::make_unique<Entity6>(); 
		//Important due to Exception Safety
		//Helps in avoiding Dangling Pointers
	}
}


// shared pointer is when we want to share, i.e., copy pointer, etc.
// works via Reference Counting - when reference count reaches 0, it gets deleted
// it has a bit of overhead because it stores a reference table
// whenever we create a new shared ptr with reference to the same Entity it reference count by 1
void SharedPtr() {
	std::shared_ptr<Entity6> entity = std::make_shared<Entity6>();
	
	// we don't want to do this 👇🏻
	// std::shared_ptr<Entity6> entity (new Entity6());
	// because shared ptr has to allocate another block of memory called 'Control Block' where 
	//		it stores the reference count and if we first create a new entity and then pass it to
	//		shared pointer constructor => this leads to 2 allocations, i.e.,
	//		creating entity first and then shared ptr has to construct its control block

}

void SharedPtr2()
{
	{
		std::shared_ptr<Entity6> e0;
		{
			std::shared_ptr<Entity6> sharedEntity = std::make_shared<Entity6>();
			e0 = sharedEntity;							// increases the ref count
		}
	}
}

void WeakPtr() {
	{
		std::shared_ptr<Entity6> e0;
		{
			std::shared_ptr<Entity6> sharedEntity = std::make_shared<Entity6>();
			std::weak_ptr<Entity6> e1 = sharedEntity;	//does not increase the ref count
			//useful when we don't want to take ownership of the Entity
			//with weak ptr we can check whether this is still alive
			//shared pointer copying ensures that it is kept alive, that's not the case with weak ptr
		}
	}
}

void SmartPtr() {
	UniquePtr();
	SharedPtr();
	SharedPtr2();
	WeakPtr();
}