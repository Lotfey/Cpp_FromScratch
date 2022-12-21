#include<iostream>


// move semantics essentially just allow us to move 
// object around, this was not possible before C++11
// because C++11 introduces for the first time the rvalue 
// references that are necessary for move semantics

// the basic idea is when we write C++ code, sometimes 
// we do not necessarily want to copy an object to another 
// which eventually requires more resources but we just need 
// to move the object


// create a simple string class and check how it behaves 
// interacting with another class
class myString
{
public :
	// default constructor 
	myString() = default;

	// intialised constructor 
	myString(const char* string)
	{
		printf("String created by initialised constructor !\n");
		mSize = strlen(string);
		mData = new char[mSize];
		memcpy(mData, string, mSize);
	}

	// Copy constructor
	myString(const myString& other)
	{
		printf("String created by COPY constructor!\n");
		mSize = other.mSize;
		mData = new char[mSize];
		memcpy(mData, other.mData, mSize);
	}

	// Move constructor
	myString(myString&& other) noexcept
	{	
		printf("String is moved by MOVE constructor!\n");
		// instead of coping data 
		// we create rvalue, a hollow variable 
		// to move myString object
		mSize = other.mSize;
		mData =other.mData;

		// then clean up everything 
		other.mSize = 0;
		other.mData = nullptr;
	}	
	
	// simple method o print myString data
	void printData ()
	{
		printf("\n");
		for (uint32_t i=0; i < mSize; ++i)
		{
			printf("%c", mData[i]);
		}
		printf("\n");
	}

	//Deconstructor
	~myString()
	{
		printf("myString object is destroyed!!!\n");
		delete mData;
	}
private:
	char* mData;
	uint32_t mSize;
};


// create a class myEntity that uses myClass object 
class myEntity 
{
public:
	// we don't need default constructor 
	myEntity() = delete;

	//intilised constructor 
	myEntity(const myString& name) : mName(name)
	{};

	// Move constructor by casting rvalue fererence of the object like so (myString&&)variable	
	//myEntity(myString&& name) : mName((myString&&)name)
	//{};
	
	// Move constructor by std::move
	myEntity(myString&& name) : mName(std::move(name))
	{};

	// simple method to print myEntity data
	void printName()
	{
		mName.printData();
	}

	// Deconstructor
	~myEntity()
	{
		printf("myEntity object is destroyed \n");
	}


private:
	myString mName;
};

// Test behavior
int main()
{

	myEntity entity(myString("myName"));
	entity.printName();

	// Test output [only initialised and copy constructor are implemented in myString class]
	// String created by initialised constructor !
	// String created by copy constructor!
	//
	// myName
	
	// notice that the object is first created by the initialised constructor 
	// which means memory has been allocated for the string.
	// entity object requires a copy constructor to create the string is his 
	// data member, so the initialised constructor of the class myEntety calls
	// the copy constructor of the class myString thus we have made a new 
	// copy of the same string in memory, new memory allocation for the copy!!!

	// HERE IT COME THE SOLUTION 

	//To avoid the copy we use MOVE SEMANTIC constructor 

	// thus the output [Move constructor is added to myString and myEntity classes]
	// String created by initialised constructor !
	// String is moved by MOVE constructor!
	// myString object is destroyed!!!
	//
	// myName

	// this feature is extremely important when we use heavy objects that consume
	// lot of memory, so instead of copying a heavy object and allocating memory 
	// for it, no, we just need to move it to be used only


	std::cin.get();
	return 0;
}
