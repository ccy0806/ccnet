#include "include/base/Timestamp.h"
#include <iostream>

int main()
{
    Timestamp ts(Timestamp::now());
    std::cout << ts.getMicroSecondsSinceEpoch() << std::endl;
}