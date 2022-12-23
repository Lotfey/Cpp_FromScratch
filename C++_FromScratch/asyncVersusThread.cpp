 // asyncVersusThread.cpp

 #include <future> // std:async
 #include <thread>
 #include <iostream>

 int main(){

  std::cout << std::endl;

  int res;

  // create a thread and pass its work via lambda expression captured by reference 
  std::thread t([&]{ res = 2000 + 22; });
  t.join();
  
  std::cout << "res: " << res << std::endl;

  // work performed asyncroniously with std::async and lambda expression 
  // thanks to future::get () method, we can access to the retured result
  auto fut= std::async([]{ return 2000 + 22; });
  std::cout << "fut.get(): " << fut.get() << std::endl;

  std::cin.get();
 }

