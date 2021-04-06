#include "include/base/Threadpool.h"
#include <exception>
#include <iostream>

using Unique_Lock = std::unique_lock<std::mutex>;
Threadpool::Threadpool(size_t threadNum, size_t queueSize) : m_threadNum(threadNum)
, m_queueSize(queueSize)
{
	
	if(threadNum <= 0 || queueSize <= 0)
	{
		throw std::exception();
	}
	m_running = true;
	m_threadPool.reserve(m_threadNum);
	for(size_t i = 0; i < m_threadNum; ++i)
	{
		printf("create thread %dth\n", i + 1);
		m_threadPool.emplace_back(std::thread(&Threadpool::Worker, std::ref(*this)));
	}
}


Threadpool::~Threadpool()
{
	if(m_running)
	{
		Stop();
	}

}
//工作线程，获取任务
void Threadpool::Worker()
{
	
	while(m_running)
	{
		Task task = GetTask();
		if(task)
		{
			task();
		}
	}
	
<<<<<<< HEAD
=======
	
>>>>>>> c9082b3300f9284a0e38aeffd6e79c9410821ce7
}

void Threadpool::Stop()
{
	{
		Unique_Lock lck(m_mutex);
		m_running = false;
		m_taskQueueNotFull.notify_all();
		m_taskQueueNotEmpty.notify_all();
	}
	for(auto &thr : m_threadPool)
	{
		thr.join();
	}
}

//向任务队列添加任务
void Threadpool::AddTask(Task task)
{ 
	//std::cout << "AddTask wait for lock" << std::endl;
	Unique_Lock lck(m_mutex);
	//std::cout << "AddTask get lock" << std::endl;
	//等待任务队列空余
	while(m_running && m_taskQueue.size() == m_queueSize)
	{
		m_taskQueueNotFull.wait(lck);
	}
	m_taskQueue.push(task);
	m_taskQueueNotEmpty.notify_all();
	std::cout << "AddTask notify_all" << std::endl;
}

Threadpool::Task Threadpool::GetTask()
{
	//等待任务队列中出现任务
	Unique_Lock lck(m_mutex);
	while(m_running && m_taskQueue.empty())
	{
		std::cout << "wait for lock" << std::endl;
		m_taskQueueNotEmpty.wait(lck);
	}
	//从队列获取任务
	Task task = m_taskQueue.front();
	m_taskQueue.pop();
	m_taskQueueNotFull.notify_all();
	//std::cout << "GetTask notify_all" << std::endl;
	return task;
}
