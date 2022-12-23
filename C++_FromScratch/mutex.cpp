#include<iostream>

#include <mutex>
#include <thread> 

std::mutex mut;

void workOnResource() 
{
	// lock the acess to the resource so one thread can use this resource at the time 
	
	int sleepTime = 1000; // milliseconds
	
	mut.lock();
	auto ID = std::this_thread::get_id();
	std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
	std::cout
		<< "The thread #" << ID << " WAS asleep for "
		<< sleepTime/1000<<" Seconds\n";
	mut.unlock();
	// Unluck access to the resource 
}

void workOnResourceAutoLock()
{
	// lock the acess to the resource so one thread can use this resource at the time 

	int sleepTime = 5000; // milliseconds

	// wrapping up the mutex in the lock_guard for auto locking 
	// So the lock guard take the ownership of the mutex  and 
	// can be used only one at the time by a given thread
	// no need to lock and unlock the mutex manually 
	std::lock_guard<std::mutex>locker(mut);

	auto ID = std::this_thread::get_id();
	std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
	std::cout
		<< "The thread #" << ID << " WAS asleep for "
		<< sleepTime / 1000 << " Seconds\n";
	
	// Unluck access to the resource 
}


int main() {

	std::thread t1(workOnResource);
	std::thread t2(workOnResource);

	t1.join();
	t2.join();

	std::cin.get(); 
	
	// side note: because std::cin.get() do not let the main body terminate
	// till a key press, it thus works similarly to join() of course, this not
	// a solution just exploiting a bug


	// mutex solve the issue of accessing shared resource at the same time 
	// the plroblem that we have to manually lock and unlock the the mutex 
	// this could be dangerious if the coder froget to unluck the mutex so the 
	// next thread would never be able to access the shares recourses

	//SOLUTION: automatise the locking operation thus std::lock_guard


	// jthread introduced in C++ 20, auto join, no need for join()
	std::jthread jt1(workOnResourceAutoLock);
	std::jthread jt2(workOnResourceAutoLock);

	// the auto lock is much safer by wrapping the mutex in the std::lock_guard
	// also auto join makes the code looks cleaner and shorter
	std::cin.get();

	return 0;

}

