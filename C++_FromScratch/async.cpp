// async.cpp

#include <future> // std::async
#include <iostream>
#include <string>

// Traditional function that return a string 
// argument "myString" is passes as const reference to avoid copy
std::string helloFunction(const std::string& myString)
{
  return "Hello C++11 from " + myString + ".";
}

// object function  method
// the idean is implement a publique class with member function that return 
// something and then override the operator ().
class HelloFunctionObject
{  
  public:
  // Overide the operator () so the object will call the object fuction on the construction 
    std::string operator()(const std::string& mySring) const
    {
      return "Hello C++11 from " + mySring + ".";
    }
};

// lambda function must be implemented iside the main...

int main()
{
  std::cout << std::endl;

  // future with function
  auto futureFunction= std::async(helloFunction,"function");

  // future with function object
  HelloFunctionObject helloFunctionObject;
  auto futureFunctionObject= std::async(helloFunctionObject,"function object");

  // future with lambda function
  auto futureLambda= std::async([](const std::string& myString ) {return "Hello C++11 from " + myString + ".";},"lambda function");

  // here is the usefulness of std::async
  // the returned values of different functions
  // are accessible via future::get() method
  std::cout
      << futureFunction.get() << "\n" 
      << futureFunctionObject.get() << "\n" 
      << futureLambda.get() << std::endl;

  std::cin.get();

  return 0;
}