#ifndef CCNET_BASE_LOGGER
#define CCNET_BASE_LOGGER

#include <memory>
#include "Timestamp.h"
<<<<<<< HEAD
<<<<<<< HEAD
#include "FixBuffer.h"
=======
>>>>>>> c9082b3300f9284a0e38aeffd6e79c9410821ce7
=======
>>>>>>> c9082b3300f9284a0e38aeffd6e79c9410821ce7
#include <sstream>
#include <fstream>
#include <string>
#include <list>
<<<<<<< HEAD
<<<<<<< HEAD
#include <thread>
#include <mutex>
#include <chrono>
#include <functional>
#include <condition_variable>
#include <unistd.h>
namespace ccnet 
{
#include <map>
namespace ccnet 
{


//日志管理器
/*
class LoggerManager
{
public:
    LoggerManager();
    ~LoggerManager();
private:
    map<Logger::ptr, const char*> mp;
};
*/

class LogAppender;


//日志器
class Logger : public std::enable_shared_from_this<Logger>
{
public:
    typedef std::shared_ptr<ccnet::Logger> ptr;
    enum LoggerLevel
    {
        TRACE,
        DEBUG,
        INFO,
        WARN,
        ERROR,
        FATAL,
        NUM_OF_LOGGER_LEVELS,
    };
    Logger(const char* srcfile, size_t line, LoggerLevel level, const char* func);
    ~Logger();
    void writeLog();                                        //写日志到目标
    //Logger::LoggerLevel getLoggerLevel();                   
    std::stringstream& getSS();                             //获取日志流
    static LoggerLevel logLevel();                          //获取限制日志等级
    static void setLoggerLevel(Logger::LoggerLevel level);  //设置日志限制等级
    static void addAppender(std::shared_ptr<LogAppender>);         //添加日志输出地
    static void clearAppender();
    static void startAsyncLog(std::string baseName);
    char * getBuffer();
private:
    char m_buffer[BUFSIZ];                              //日志缓冲流
private:
private:
    std::stringstream m_ss;                         //日志缓冲流
    std::shared_ptr<LogAppender> m_appender;         //日志输出地
    static std::list<std::shared_ptr<LogAppender>> m_appenderList; //日志输出目的地列表
    static std::string m_logName;                          //日志名
    LoggerLevel m_level;                            //日志级别
    size_t m_threadId;                              //线程id
    size_t m_line;                                  //行号
    std::string m_func;                             //函数名
    std::string m_srcfile;                          //文件名
    Timestamp m_ts;                             //时间戳类
    //static std::string timeBuffer;
    size_t getThreadId();
    void formatTime();

    bool m_isAsyncLog;

    //Logger::ptr m_logger;
};

extern Logger::LoggerLevel g_logLevel;              
inline Logger::LoggerLevel Logger::logLevel()
{
  return g_logLevel;
}


//日志输出地，虚基类
class LogAppender
{
friend class Logger;
public:
    typedef std::shared_ptr<LogAppender> ptr;
    virtual ~LogAppender(){}                             //基类析构函数需要定义为虚函数
    virtual void writeLog(Logger &logger) = 0;       //纯虚函数，需要子类定义写日志方法。
    inline void setAppenderState(bool state){m_isActive = state;}
    bool m_isActive = true;
};

//日志输出地:文件
class FileLogAppender : public LogAppender
{
public:
    typedef std::shared_ptr<FileLogAppender> ptr;
    FileLogAppender(std::string);
    ~FileLogAppender();
    void writeLog(Logger &logger) override;
private:
    std::ofstream m_fout;                       //文件流对象
    std::string m_logName;
};


//日志输出地:stdout
class StdoutLogAppender : public LogAppender
{
public:
    typedef std::shared_ptr<StdoutLogAppender> ptr;
    void writeLog(Logger &logger) override;
private:
};

class AsyncOutputAppender : public LogAppender
{
public:
    typedef std::shared_ptr<AsyncOutputAppender> ptr;
    typedef std::shared_ptr<std::stringstream> SSptr;
    
    const int m_BUFFERSIZE = 4000 * 1000;
    AsyncOutputAppender(const std::string baseName, size_t flushInterval = 3, size_t rollSize = 500 * 1000 * 1000);
    ~AsyncOutputAppender();
    void appendLog(SSptr &buffer);          //向缓冲区写日志
    void writeLog(Logger &logger) override;
    void outputLog();
    void test(){ std::cout << "test thread out\n"; }
private:
    std::ofstream m_fout;                       //文件流对象
    const std::string m_baseName;       //日志基本名
    std::string m_logName;              //日志实际名
    size_t m_flushInterval;             //缓冲区刷新频率
    size_t m_rollSize;                  //日志分页大小
    mutable std::mutex m_mutex;         //互斥量
    std::condition_variable m_bufInIsFull;//bufIn满
    //std::condition_variable m_outputBufferIsEmpty;//bufVec为空
    std::thread m_thread;
    std::list<SSptr> m_bufVec;
    bool m_isRunning;               
    SSptr m_bufIn;
};



#define LOG_TRACE if(ccnet::Logger::logLevel() <= ccnet::Logger::LoggerLevel::TRACE)\
    ccnet::Logger(__FILE__, __LINE__, ccnet::Logger::TRACE, __func__).getSS()
#define LOG_DEBUG if(ccnet::Logger::logLevel() <= ccnet::Logger::LoggerLevel::DEBUG)\
    ccnet::Logger(__FILE__, __LINE__, ccnet::Logger::DEBUG, __func__).getSS()
#define LOG_INFO if(ccnet::Logger::logLevel() <= ccnet::Logger::LoggerLevel::INFO)\
    ccnet::Logger(__FILE__, __LINE__, ccnet::Logger::INFO, __func__).getSS()

#define LOG_WARN ccnet::Logger(__FILE__, __LINE__, ccnet::Logger::WARN, __func__).getSS()
#define LOG_ERROR ccnet::Logger(__FILE__, __LINE__, ccnet::Logger::ERROR, __func__).getSS()
#define LOG_FATAL ccnet::Logger(__FILE__, __LINE__, ccnet::Logger::FATAL, __func__).getSS()

#endif

}//namespace ccnet