#include "include/net/Eventloop.h"

//线程局部存储的 Eventloop对象指针
__thread Eventloop* currentThreadLoop = NULL;

Eventloop::Eventloop(Socketbase sockbase) 
: m_looping(false),m_tid(std::this_thread::get_id())
{
    LOG_TRACE << "EventLoop created" << this << " in thread  " << m_tid;
    if(currentThreadLoop)
    {
        LOG_FATAL << "Another Eventloop" << currentThreadLoop << " exists in this thread" << m_tid;

    }
    else
    {
        currentThreadLoop = this;
    }
}

Eventloop::~Eventloop()
{
    currentThreadLoop = NULL;
}
void Eventloop::assertInLoopThread()
{
    if(std::this_thread::get_id() == m_tid)
    {
        LOG_FATAL << "cannot looping on other Eventloop"
        << "current thread id = " << std::this_thread::get_id()
        << "Eventloop thread id = " << m_tid;
    }
}
//禁止跨线程调用
void Eventloop::startLoop()
{
    assert(!m_looping);
    assertInLoopThread();
    m_looping = true;
    LOG_TRACE << "Eventloop" << this << "start looping";
    //关注的事件
    
    LOG_TRACE << "Eventloop" << this << "end looping";
    m_looping = false;
}
//TODO