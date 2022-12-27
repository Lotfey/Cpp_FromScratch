


#include <iostream>
#include<vector>
#include<cassert>
#include<algorithm>

class add_x
{
public:

	// Constructor
	add_x() = delete;
	add_x(int val) :x_(val) {};
	
	//getter
	int getx() { return x_; }

	//Functors
	// the operator () is overiden to define the functor 
	// the compelator choose the functor definition based on
	// the functor signature
	int operator()(int y) { return x_ + y; }
	float operator()(float s) { return x_ - s; }
private:
	int x_;
};


int main()
{
	// Now you can use it like this:
	// create an instance of the functor class

	add_x add42(42);
	std::cout <<"add_x after first instantiation: " << add42.getx() << std::endl;

	// and "call" it
	int i = add42(8.f); 

	// because the argument is float, the compelator calls the float functor 
	std::cout << i << std::endl;
	
	// assume this vector in contains a bunch of values
	std::vector<int> in; 
	for (int i=0; i<10;i++)
	{
		in.emplace_back(i);
		std::cout << in[i]<< " ";
	}
	std::cout<< std::endl;	
	
	// Pass a functor to std::transform, which calls the functor on every element
	// in the input sequence, and stores the result to the output sequence
	std::vector<int> out(in.size());
	std::transform(in.begin(), in.end(), out.begin(), add_x(1));
	for (int& value : out)
	{
		std::cout << value << " ";
	}

	std::cin.get();
}

