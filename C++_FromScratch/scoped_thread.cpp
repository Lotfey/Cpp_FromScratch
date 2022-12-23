// scoped_thread.cpp

#include <iostream>
#include <thread>



class scoped_thread 
{
private:
    std::thread _t;

public:

    //explicit constructor with move semantic 
    explicit scoped_thread(std::thread t) : _t(std::move(t))
    {
        // joinable() returns true then the thread is working 
        // and  returns false if the thread is not. 
        if (!_t.joinable())
        {
            throw std::logic_error("No thread");
        }
    }

    ~scoped_thread()
    {
        std::cout << "join thread and destroy the thread scope object!!!"<<std::endl;
        _t.join();
    }
    //no copy constructor is allowed
    scoped_thread(scoped_thread&) = delete;
    scoped_thread& operator=(scoped_thread const&) = delete;
};


int main()
{
    std::thread t1;

    scoped_thread t(std::thread([] {std::cout << "Thread Id# " << std::this_thread::get_id() << std::endl; }));
    
    // t1 is not an active thread, thus expecting an exception 
    try
    {
        scoped_thread(std::move(t1));
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }   

   //std::cin.get();
    return 0;
}