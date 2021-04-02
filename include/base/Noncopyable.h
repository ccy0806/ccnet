#ifndef CCNET_BASE_NONCOPYABLE
#define CCNET_BASE_NONCOPYABLE

class Noncopyable
{
public:
	Noncopyable(const Noncopyable &) = delete;
	void operator=(const Noncopyable &) = delete;	
//如果不写构造函数，则编译器自动设为私有。
protected:
	Noncopyable() = default;
	~Noncopyable() = default;
};




#endif
