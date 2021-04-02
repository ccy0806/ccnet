#include <iostream>
#include <sstream>
#include <fstream>
#include "include/base/Timestamp.h"
using namespace std;
#define N 10000
void testStringStream()
{

    Timestamp start(Timestamp::now());
    stringstream os;

    for (size_t i = 0; i < N; ++i)
    {
      os << i;
    }
    Timestamp end(Timestamp::now());

    printf("StringStream %f\n", timeDifference(end, start));
}
void testFStream()
{
    Timestamp start(Timestamp::now());
    //stringstream os;
    char buf[10];
    ofstream fout;
    fout.open("test1.log", std::ofstream::out | std::ofstream::app);
    for (size_t i = 0; i < N ; ++i)
    {
      snprintf(buf, sizeof(buf), "%ld", i);
      fout << buf;
      fout.flush();
    }
    fout.close();
    Timestamp end(Timestamp::now());

    printf("FStream %f\n", timeDifference(end, start));

}
void testFStream2()
{
    Timestamp start(Timestamp::now());

    ofstream fout;
    fout.open("test2.log", std::ofstream::out | std::ofstream::app);
    for (size_t i = 0; i < N ; ++i)
    {
      fout << i;
      fout.flush();
    }
    fout.close();
    Timestamp end(Timestamp::now());

    printf("FStream2 %f\n", timeDifference(end, start));

}
int main()
{
    testStringStream();
    testFStream();
    testFStream2();
    return 0;
}