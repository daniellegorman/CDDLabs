/*Author: Danielle Gorman
  Date: 9/10/17
  Description: Main Program for Semaphore to run. This program uses 
  semaphores to run task one first, and task two second."
*/

#include "Semaphore.h"
#include <iostream>
#include <thread>

void Task1(std::shared_ptr<Semaphore> theSemaphore){
  std::cout << "task a1"<< std::endl;
  theSemaphore->Signal();
  theSemaphore->Wait();
  std::cout << "task a2" << std::endl;
}
void Task2(std::shared_ptr<Semaphore> theSemaphore){
  std::cout << "Task b1" << std::endl;
  theSemaphore->Signal();
  theSemaphore->Wait();
  std::cout << "task b2" << std::endl;
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem(new Semaphore);
  /**< Launch the threads  */
  threadOne=std::thread(Task1,sem);
  threadTwo=std::thread(Task2,sem);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
