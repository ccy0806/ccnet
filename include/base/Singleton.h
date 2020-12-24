#ifndef CCNET_BASE_SINGLETON
#define CCNET_BASE_SINGLETON

#include "Noncopyable.h"

template<typename T>
class Singleton : Noncopyable
{
public:
	static T& getInstance()		{
		static T instance;
		return instance;
	}
private:
	Singleton() = delete;
	~Singleton() = delete;
	
};

#endif