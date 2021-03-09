#include "include/base/Logger.h"
#include "include/base/Timestamp.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <list>
void bench(const std::string dst)
{
    ccnet::Logger::clearAppender();
    ccnet::Logger::clearAppender();
    ccnet::LogAppender::ptr la(new ccnet::FileLogAppender(dst));
    ccnet::Logger::addAppender(la);
    
    int n = 1000 * 1000;
    const bool kLongLog = false;
    const std::string empty = " ";
    const std::string longStr(3000, 'X');
    Timestamp start(Timestamp::now());
    for(int i = 0; i < n; ++i)
    {
        LOG_INFO << "Hello 0123456789" << " abcdefghijklmnopqrstuvwxyz"<< (kLongLog ? longStr : empty)<< i;
    }
    Timestamp end(Timestamp::now());
    double seconds = timeDifference(end, start);
    FILE* file = fopen(dst.c_str(), "rb");
    fseek(file, 0, SEEK_END);
    int total = ftell(file);
    fclose(file);
    printf("%12s: %f seconds, %d bytes, %10.2f msg/s, %.2f MiB/s\n",\
    dst, seconds, total, n / seconds, total / seconds / (1024 * 1024));
}
int main()
{
    bench("nop");
    bench("/dev/null");
    //bench("test1.log");
    //bench("test2.log");
    //bench("test3.log");

    ccnet::LogAppender::ptr la2(new ccnet::FileLogAppender("log2.log"));
    ccnet::Logger::addAppender(la2);
    la2->setAppenderState(true);
    ccnet::Logger::setLoggerLevel(ccnet::Logger::LoggerLevel::TRACE);
    LOG_TRACE << "TRACE...";
    LOG_DEBUG << "DEBUG...";
    LOG_INFO << "INFO...";
    //LOG_FATAL << "FATAL...";
    ccnet::Logger::setLoggerLevel(ccnet::Logger::LoggerLevel::INFO);
    ccnet::Logger::clearAppender();
    LOG_TRACE << "TRACE...";
    LOG_DEBUG << "DEBUG...";
    LOG_INFO << "INFO...";
    LOG_FATAL << "FATAL...";
    LOG_TRACE << "end...";
    return 0;
}