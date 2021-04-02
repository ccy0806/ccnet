#include "include/base/Logger.h"
#include "include/base/Timestamp.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <list>

void bench()
{
    
    int n = 1000 * 1000;
    //int n = 100;
    const bool kLongLog = false;
    const std::string empty = " ";
    const std::string longStr(3000, 'X');
    std::cout << "begin bench\n";
    Timestamp start(Timestamp::now());
    for(int i = 0; i < n; ++i)
    {
        LOG_INFO << "Hello 0123456789" << " abcdefghijklmnopqrstuvwxyz"<< (kLongLog ? longStr : empty)<< i;
    }
    Timestamp end(Timestamp::now());
    double seconds = timeDifference(end, start);
}
int main()
{
    ccnet::Logger::startAsyncLog("asynclog");
    bench();

}