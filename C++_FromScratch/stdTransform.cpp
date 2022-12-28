#include <iostream>    // std::cout
#include <algorithm>   // std::transform
#include <vector>      // std:: vector
#include <functional>  // std::plus

// simple class that has an interger as class member 
// and implement a functor by overriding the operator ()

class X_
{
public:
	//constructor
	X_() = delete;
	X_(int a) : x_(a) { std::cout << "Initialised constructor is called \n"; };
	// copy constructor	
	X_(const X_& T) : x_(T.x_) { std::cout << "Copy constructor is called \n"; }

	//getters
	int getx()
	{
		return x_;
	}
	
	//deconstructor
	~X_() = default; 
	
	// methods
	// overide the operator (), the object instatiated from the 
	//class X_ can be used as a functor 
	int operator () (int kk) 
	{	
		// operator () perform this equation 
		std::cout << "functor is called\n";
		  return  (x_ + kk) ;
	}
	// No implicit casting for the opearator () is allowed 
	// so to use the functor you must use int variable as first argument
	//  and float variableas second argument 
	template <class T>
	int operator ()(T) = delete; // C++11 
	
	int incrementOperation(int i)
	{
		return i++;
	}

private:
	int x_;
};


int main()
{
	typedef int MyVar;
	typedef std::vector <MyVar> Myvec;

	
	Myvec inVect, outVect;

	X_ Myclass(102);
	X_ CopyMyclass=Myclass;

	std::cout << Myclass.getx() << std::endl;
	std::cout << CopyMyclass.getx() << std::endl;

	std::cout << std::endl;
	std::cout << Myclass(150) << std::endl;	
	std::cout<<CopyMyclass.getx()<<std::endl;

	// set some values
	for (int i=0; i<10; ++i)
	{
		// I like use emplace_back than push_back to avoid copies
		inVect.emplace_back(i*100);//0 100 200 ...900
	}
	
	outVect.resize(inVect.size());
	// std::stransform called the functor from the calss Myclass 
	std::transform(inVect.begin(), inVect.end(), outVect.begin(), Myclass);

	std::cout << "inVect contains:";
	for (std::vector<MyVar>::iterator it=inVect.begin(); it!=inVect.end(); ++it)
	{
		std::cout << ' ' << *it;
	}
	std::cout <<'\n';
	std::cout << "outVect contains:";
	
	for (std::vector<MyVar>::iterator it=outVect.begin(); it!=outVect.end(); ++it)
	{
		std::cout << ' ' << *it;
	}

	std::cout << '\n'<< std::endl;
	return 0;
}
