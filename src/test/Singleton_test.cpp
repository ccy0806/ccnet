#include "../../include/base/Singleton.h"
#include <thread>
#include <vector>
#include <cstdio>
#include <functional>


class Test
{

public:
	Test()	
	{
		printf("tid = %d, constructing %p\n", std::this_thread::get_id(), this);	
	}
	~Test()
	{
		printf("tid = %d, destructing %p\n", std::this_thread::get_id(), this);	
	}
	
};
void threadFunc()
{
	//std::this_thread::sleep_for (std::chrono::seconds(1));
	printf("tid = %d, %p\n",
		std::this_thread::get_id(),
		&Singleton<Test>::getInstance());
}
void threadFunc2(int num)
{
	printf("threadFunc2 %d  tid = %d, %p\n",
		num,
		std::this_thread::get_id(),
		&Singleton<Test>::getInstance());
}

void test()
{
	std::vector<std::thread> vec;
	for(int i = 0; i < 10; ++i)
	{
		std::thread tmp(threadFunc);
		vec.push_back(std::move(tmp));
		
	}
	for(int i = 0; i < 10; ++i)
		vec[i].join();
}
void test2()
{
	printf("start--\n");
	std::thread t1(threadFunc);
	std::thread t2(threadFunc);
	//std::thread t3(std::bind(&threadFunc2, 5));
	t1.join();
	t2.join();
	//t3.join();
	printf("tid = %d, %p\n",std::this_thread::get_id(),&Singleton<Test>::getInstance());
}
int main()
{
	
	test();
	test2();
	return 0;
}
