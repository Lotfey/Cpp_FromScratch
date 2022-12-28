// threadLocal.cpp

#include <iostream>
#include <string>
#include <mutex>
#include <thread>

std::mutex coutMutex;
// thread_local is defined as a specifier to define the thread-local data
// this data is created when the thread is created
// and destroyed when the thread is also destroyed
thread_local std::string localThread("Hello from ");

void addThreadLocal(std::string const& s2,int threadNum)
{
	localThread += s2+ std::to_string(threadNum);
	// protect std::cout
	std::lock_guard<std::mutex> guard(coutMutex);
	std::cout << localThread << std::endl;
	std::cout << "&localThread: " << &localThread << std::endl;
	std::cout << "ID: " << std::this_thread::get_id() << std::endl;
	std::cout << std::endl;
}

int main() {

	std::cout << std::endl;

	//C++20
	std::jthread t1(addThreadLocal, "thread ", 1);
	std::jthread t2(addThreadLocal, "thread ", 2);
	std::jthread t3(addThreadLocal, "thread ", 3);
	std::jthread t4(addThreadLocal, "thread ", 4);
}