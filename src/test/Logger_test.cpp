#include "include/base/Logger.h"
#include <iostream>

int main()
{
    ccnet::Logger::setLoggerLevel(ccnet::Logger::LoggerLevel::TRACE);
    LOG_TRACE << "TRACE...";
    LOG_DEBUG << "DEBUG...";
    LOG_INFO << "INFO...";
    //LOG_FATAL << "FATAL...";
    ccnet::Logger::setLoggerLevel(ccnet::Logger::LoggerLevel::INFO);
    LOG_TRACE << "TRACE...";
    LOG_DEBUG << "DEBUG...";
    LOG_INFO << "INFO...";
    LOG_FATAL << "FATAL...";
    LOG_TRACE << "end...";
    return 0;
}