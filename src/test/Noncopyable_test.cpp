#include "../../include/base/Noncopyable.h"
#include <iostream>
class A : Noncopyable
{
public:
	A(int val) : m_val(val){}
	~A(){}
	int m_val;
	void Print(){std::cout << "A: m_val = " << m_val << std::endl;}
};

void test()
{
	A a(5);
	a.Print();
}

int main()
{
	test();


	return 0;
}

