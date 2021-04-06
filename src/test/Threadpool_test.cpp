#include "include/base/Threadpool.h"
#include <iostream>
#include <thread>
#include <chrono>
void Print()
{
	std::cout << "thread_id = " << std::this_thread::get_id() << "is working on Print()" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

void Print2()
{
	std::cout << "thread_id = " << std::this_thread::get_id() << "is working on Print222222222222222222()" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

void test()
{

	Threadpool pool(5,10);
	std::cout << "add task ing...   thread_id: " << std::this_thread::get_id() << std::endl;
	int n = 100;
	while(n)
	{
		pool.AddTask(std::bind(Print));
		n--;
	}

}
int main()
{
	std::cout << "test" << std::endl;
	test();
	return 0;
}
