#include "include/base/FixBuffer.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "include/base/Threadpool.h"
using namespace std;
const int SIZE = 26;
typedef std::shared_ptr<std::stringstream> SSptr;
std::vector<SSptr> bufVec;
void inputThread(SSptr &bufAptr)
{
    cout << "bufAptr: " << bufAptr->tellp() <<endl;
    if(bufAptr->tellp() > SIZE)
    {
        //交换
        SSptr bufTemp(new std::stringstream );
        int length = bufTemp->tellp();
        cout << "bufTemp: " << length <<endl;
        length = bufAptr->tellp();
        cout << "bufAptr: " << length << endl;
        bufAptr.swap(bufTemp);
        //bufAptr->clear();
        length = bufTemp->tellp();
        cout << "bufTemp: " << length <<endl;
        length = bufAptr->tellp();
        cout << "bufAptr: " << length << endl;
        bufVec.push_back(bufTemp);
        
    }
    (*bufAptr) << "abcddeeeeea" << endl;
}

int main()
{
    SSptr bufAptr(new std::stringstream );
    for(int i = 0; i < 3; ++i)
    {
        inputThread(bufAptr);
    }



    int length = bufAptr->tellp();
    cout << "bufAptr: " << length << endl;

    cout << bufVec.size() <<endl;
    for(auto i = bufVec.begin(); i != bufVec.end(); ++i)
    {
        int length = (*i)->tellp();
        cout << "bufVec: " << length << endl;
    }
    return 0;
}