#include "include/base/Timestamp.h"
#include <iostream>
Timestamp::Timestamp(int64_t microSecondsSinceEpoch) : m_microSecondsSinceEpoch(microSecondsSinceEpoch){}

Timestamp::~Timestamp(){}

std::string Timestamp::getFormatDay(const std::string format)
{

    time(&mytime);
    struct tm * timeinfo = localtime(&mytime);
    strftime(m_buf, sizeof(m_buf), format.c_str(), timeinfo);

    return std::string(m_buf);
}

Timestamp Timestamp::now()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    int64_t seconds = tv.tv_sec;
    return Timestamp(seconds * kMicroSecondsPerSecond + tv.tv_usec);
}