// coutUnsynchronized.cpp

#include <chrono>
#include <iostream>
#include <thread>

class Worker {
public:
    Worker(std::string n) :name(n) {};

    //Override the operator () so worker() run the code below
    // every thread that runs this code tries to use the resources available 
    // notably  std::cout 
    // this behavior results in running the code asynchronously but also
    // could potentially introduce logic errors 
    void operator() ()
    {
        for (int i = 1; i <= 3; ++i) {
            // begin work
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            // end work
            std::cout << name << ": " << "Work " << i << " done !!!" << std::endl;
        }
    }

private:
    std::string name;
};


int main() 
{
    std::cout << std::endl;
    std::cout << "Boss: Let's start working.\n\n";

    std::thread herb = std::thread(Worker("Herb"));
    std::thread andrei = std::thread(Worker("  Andrei"));
    std::thread scott = std::thread(Worker("    Scott"));
    std::thread bjarne = std::thread(Worker("      Bjarne"));
    std::thread andrew = std::thread(Worker("        Andrew"));
    std::thread david = std::thread(Worker("          David"));

    herb.join();
    andrei.join();
    scott.join();
    bjarne.join();
    andrew.join();
    david.join();

    std::cout << "\n" << "Boss: Let's go home." << std::endl;

    // notice that the work has been done but the display is a bit wacky
    // because multiple threads want to use the resource std::cout at 
    // the same time.
    // to solve this issueand,one sulution is to make the code run synchronously
    // when access to std:::cout by using the class mutex to lock and unlock 
    // the resource beforeand after usage
}