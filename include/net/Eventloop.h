#ifndef CCNET_NET_EVENTLOOP
#define CCNET_NET_EVENTLOOP


#include "include/net/Socketbase.h"
#include "include/base/Noncopyable.h"
#include "include/base/Logger.h"
#include <thread>
namespace ccnet
{
class Eventloop : Noncopyable
{
public:
    Eventloop(Socketbase sockbase);
    ~Eventloop();
    void startLoop();   //启动事件循环
    void endLoop();     //终止事件循环
    void assertInLoopThread();  //用去启动线程时禁止跨线程调用
private:
    Socketbase m_sockbase;
    bool m_looping;     //是否处于事件循环
    std::thread::id m_tid;          //线程id
}
//TODO

}

#endif