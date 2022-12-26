// Functor.cpp


#include <iostream>
class Counter
{
public:
	Counter() = delete;
	Counter(int  count) :mCount(count) {};

	
	// Functor that returns the count 
	// By overriding the operator (), the object counter will be 
	// responsible of performing the cumule and save it in the 
	// class member variable 
	int  operator() (int n)	
	{
		return mCount+=n;
	}

	int getCount() { return mCount; };

	~Counter()
	{
		std::cout << "\nCounter Object is destroyed!!!" << std::endl;
	}
	private:
	int mCount;
};


int main() {

	Counter C1(0);

	int A[10] = { 0 };
	
	for (int i = 0; i < 10; ++i)
	{
		A[i] = C1(i);
		std::cout << "A["<<i<<"]= " << A[i]  << std::endl;
	}

	std::cout<<"\nThe cumulative count is: "<<C1.getCount() << std::endl;
	
	return 0;
}
