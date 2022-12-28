// threadMethods.cpp

#include <iostream>
#include <thread>

using namespace std;

int main() 
{	
	// change the flag display 
	bool flag = 0;
	cout << "boolalpha "<<boolalpha << flag<< endl;
	cout << "boolalpha " << noboolalpha << flag << endl;
	cout << endl;

	//C++11
	//Returns the number of concurrent threads supported by the implementation
	cout << thread::hardware_concurrency()<< " concurrent threads are supported.\n";
	cout << endl;

	// return the thread Id via lambda expression
	// use std::this_thread::get_id()
	thread t1([] {cout << "From lambda expression t1 with id= " << this_thread::get_id() << endl; });
	thread t2([] {cout << "From lambda expression t2 with id= " << this_thread::get_id() << endl; });
	cout << endl;
	
	//Use thread method get_id() to return the thread id 
	cout << "FROM MAIN: id of t1 " << t1.get_id() << endl;
	cout << "FROM MAIN: id of t2 " << t2.get_id() << endl;
	cout << endl;

	//Exchanges the underlying handles of two thread objects
	swap(t1, t2);
	cout << "FROM MAIN: id of t1 " << t1.get_id() << endl;
	cout << "FROM MAIN: id of t2 " << t2.get_id() << endl;
	cout << endl;

	cout << "FROM MAIN: id of main= " << this_thread::get_id() << endl;
	cout << endl;

	// return if the thread is not working and 1 if it is working 
	cout << "t1.joinable(): " << t1.joinable() << endl;
	cout << "t2.joinable(): " << t2.joinable() << endl;
	cout << endl;

	t1.join();
	t2.join();
}


