#include<iostream>

// lvalue: usually the left side of an assignment operation 
// lvalue exists in a physical object in memory 

// rvalue is usually the right side of the preparation
// rvalue does not occupy permanent memory, maybe exist in a temporary
// register during the run time


// The print function is overriden, it takes two different argument signature 

// Reference to an rvalue argument, since it is an reference to rvalue, the argument 
// cannot be an operation, it must be an existing value in the memory
void printName(std::string& Name)
{
	std::cout << "Print name from [lvalue]: " << Name << std::endl;
}

// Reference to lvalue argument, it is a reference to lvalue, so the function 
// argument can take an operation of strings
void printName(std::string&& Name)
{
	std::cout << "Print name from [rvalue]: " << Name<< std::endl;
}

int main()
{
	int x = 666;   // ok
	// Here 666 is an rvalue  has no specific memory address, except for some
	//temporary register while the program is running

	int* y = &x;   // ok

	//int y;
	// 666 = y; // error!
	// 666, being a literal constant — so an rvalue, doesn't have a specific
	// memory location. I am assigning y to nowhere.

	std::string firstname, lastname, fullname;

	// rvalue = lvalue 

	firstname = "myFirstName";
	lastname = "myLastName";
	
	// fullname is lvalue and so firstname and lastname right 
	// in fact the compiler implicitely convert rvalue (firstname and lastname)
	// to rvalue.

	fullname = firstname + " " + lastname;
	
	// this print fuction should call the lvalue function
	printName(fullname);

	// this print function should call the rvalue function 
	printName(firstname + " " + lastname);

	return 0;
}