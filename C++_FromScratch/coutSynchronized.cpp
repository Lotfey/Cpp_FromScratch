// coutSynchronized.cpp

#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex coutMutex;

class Worker 
{
public:
	Worker(std::string n) :name(n) {};

	// override the operator () for the class Worker
	void operator() ()
	{
		for (int i = 1; i <= 3; ++i) {
			// begin work
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
			// end work
			coutMutex.lock();
			std::cout << name << ": " << "Work " << i << " done !!!" << std::endl;
			coutMutex.unlock();
		}
		
	}
	~Worker() = default;
private:
	std::string name;
};


int main() {

	std::cout << std::endl;
	std::cout << "Boss: Let's start working." << "\n\n";
	
	std::thread herb = std::thread(Worker("1- Herb"));
	std::thread andrei = std::thread(Worker("2-  Andrei"));
	std::thread scott = std::thread(Worker("3-   Scott"));
	std::thread bjarne = std::thread(Worker("4-     Bjarne"));
	std::thread andrew = std::thread(Worker("5-      Andrew"));
	std::thread david = std::thread(Worker("6-       David"));

	herb.join();
	andrei.join();
	scott.join();
	bjarne.join();
	andrew.join();
	david.join();

	std::cout << "\n" << "Boss: Let's go home." << std::endl;

	std::cout << std::endl;

	// thanks for the mutex capability, the work has been done with in the order of the work presented
	// meaning, all worker should finish work 1 then 2 and then the last one 
	return 0;

}
