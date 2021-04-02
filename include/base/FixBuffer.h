#ifndef CCNET_BASE_FIXBUFFER
#define CCNET_BASE_FIXBUFFER
#include "Noncopyable.h"
#include <cstring>
#include <string>
#include <iostream>
namespace ccnet
{
template<int SIZE>
class FixBuffer : Noncopyable
{
public:
    FixBuffer(){m_cur = m_data;}
    ~FixBuffer(){}
    void append(const char* buf, int len)
    {
        //int len = sizeof(buf);              //退化为指针 只有8个字节
        std::cout << "len: " << len << std::endl;
        if(avail() > len)
        {
            memcpy(m_cur, buf, len);
            m_cur += len;
        }
    }
    int avail() const { return static_cast<int>(end() - m_cur); }
    int length() const { return static_cast<int>(m_cur - m_data); }
    char* current() { return m_cur; }
    char* data() { return m_data; }
    void add(size_t len) { m_cur += len; }
    void reset() { m_cur = m_data; }
    void bzero() { memset(m_data, sizeof(m_data), '0'); }
    std::string toString() const { return string(m_data, length()); }
private:
    char* m_cur;
    char m_data[SIZE];
    const char* end() const {return m_data + sizeof(m_data);}
};

}

#endif