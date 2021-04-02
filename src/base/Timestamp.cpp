#include "include/base/Timestamp.h"
#include <iostream>
Timestamp::Timestamp(int64_t microSecondsSinceEpoch) : m_microSecondsSinceEpoch(microSecondsSinceEpoch){}

Timestamp::~Timestamp(){}
/*
std::string Timestamp::getFormatDay(const std::string format)
{

    time(&mytime);
    struct tm * timeinfo = localtime(&mytime);
    strftime(m_buf, sizeof(m_buf), format.c_str(), timeinfo);

    return std::string(m_buf);
}
*/
Timestamp Timestamp::now()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    //m_seconds = tv.tv_sec;
    //m_microseconds = tv.tv_usec;
    return Timestamp(tv.tv_sec * kMicroSecondsPerSecond + tv.tv_usec);
}