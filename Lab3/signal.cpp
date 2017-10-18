/*Author: Danielle Gorman
  Date: 9/10/17
  Description: Main Program for Semaphore to run. This program uses 
  semaphores to run task one first, and task two second."
*/

#include "Semaphore.h"
#include <iostream>
#include <thread>

void a1(std::shared_ptr<Semaphore> theSemaphore, int count){
  theSemaphore->Wait();
  count = count + 1;
  theSemaphore->Signal();
}
void b2(std::shared_ptr<Semaphore> theSemaphore, int count){
  theSemaphore->Wait();
  count = count + 1;
  theSemaphore->Signal();
}

int main(void){
  std::thread threadOne, threadTwo, threadThree, threadFour;
  std::shared_ptr<Semaphore> sem( new Semaphore);
  /**< Launch the threads  */
  threadOne=std::thread(a1,sem);
  threadTwo=std::thread(b2,sem);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
