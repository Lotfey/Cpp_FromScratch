// createThread.cpp

#include <iostream>
#include <thread> //std::thread C++11


// standard function says hello!
void helloFunction() {
    std::cout << "Hello C++11 from function." << std::endl;
}

// function object or functor is a special fuction 
// imlemented inside a class and overide the operator ()

class HelloFunctionObject {
public:
    // overide the operator () by () meaning the () excecute whateven inside the body {}
    void operator()() const 
    {
        std::cout << "Hello C++11 from a function object." << std::endl;
    }
};


int main() 
{
    std::cout << std::endl;

    // thread executing helloFunction
    std::thread t1(helloFunction);

    // thread executing helloFunctionObject
    HelloFunctionObject helloFunctionObject;
    std::thread t2(helloFunctionObject);

    // thread executing lambda Expression [capture](parameters){body}
    std::thread t3([] {std::cout << "Hello C++11 from lambda function." << std::endl; });

    // ensure that t1, t2 and t3 have finished before main terminates
    t1.join();
    t2.join();
    t3.join();

    // notice that the output is not necessarily depicted as suggested in the code 
    // t1, t2,t3. Every time you run the code different results appear depending on the 
    // machine available resources

    // the issue that occurs is that threads t1, t2 and t3 sometime need to access the std::cout
    // resource at the same time but one can use the resource which causes some time the 
    // results showed un in the same line 

    // SOLUTION: thread must be synchorised to access resources thus the use of std::mutex
    std::cin.get();
    
    return 0;
}

