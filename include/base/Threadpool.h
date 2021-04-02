#ifndef CCNET_BASE_THREADPOOL
#define CCNET_BASE_THREADPOOL

#include <vector>
#include <queue>
#include <thread>
#include <functional>
#include <string>
#include <mutex>
#include <condition_variable>
#include "Noncopyable.h"

class Threadpool : Noncopyable
{

public:
	typedef std::function<void ()> Task;
	typedef unsigned int size_t;
	
	Threadpool(size_t threadNum, size_t queueSize);
	~Threadpool();
	void Stop();
	void AddTask(Task task);

private:
	//成员变量
	std::vector<std::thread> m_threadPool;//使用vector存放线程
	std::queue<Task> m_taskQueue;//任务队列
	std::condition_variable m_taskQueueNotFull;//任务队列未满 
	std::condition_variable m_taskQueueNotEmpty;//任务队列非空
	mutable std::mutex m_mutex;//互斥量
	
	size_t m_threadNum;
	size_t m_queueSize;
	bool m_running;
	//成员函数
	void Worker();
	Task GetTask();
	
};


#endif

