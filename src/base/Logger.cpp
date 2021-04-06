#include "include/base/Logger.h"
#include <iostream>

namespace ccnet{
using Unique_Lock = std::unique_lock<std::mutex>;
char t_timebuf[64];


__thread char t_timebuf[64];

__thread time_t t_lastSeconds;

const char* LogLevelName[Logger::LoggerLevel::NUM_OF_LOGGER_LEVELS] =
{
  "TRACE ",
  "DEBUG ",
  "INFO  ",
  "WARN  ",
  "ERROR ",
  "FATAL ",
};
extern std::list<std::shared_ptr<LogAppender>> Logger::m_appenderList; //定义日志输出目的地列表
Logger::Logger(const char* srcfile, size_t line, Logger::LoggerLevel level, const char* func) :
    m_srcfile(srcfile),
    m_line(line),
    m_level(level),
    m_func(func),
    m_ts(Timestamp::now()),
    m_isAsyncLog(false)
{
    m_appender = LogAppender::ptr(new StdoutLogAppender);
    
    formatTime();
}

    m_ts(Timestamp::now())
{
    m_appender = LogAppender::ptr(new StdoutLogAppender);
    formatTime();
    this->getSS() << m_srcfile <<" " << LogLevelName[m_level] << m_func  << ":" << m_line << " ";
}

Logger::~Logger()
{
    // auto self = shared_from_this();
    writeLog();
}
void Logger::formatTime()
{
    int64_t microSecondsSinceEpoch = m_ts.getMicroSecondsSinceEpoch();
    time_t seconds = static_cast<time_t>(microSecondsSinceEpoch / Timestamp::kMicroSecondsPerSecond);
    int microseconds = static_cast<int>(microSecondsSinceEpoch % Timestamp::kMicroSecondsPerSecond);
    if(seconds != t_lastSeconds)
    {
        t_lastSeconds = seconds;
        time_t mytime;
        time(&mytime);
        struct tm * timeinfo = localtime(&mytime);

        strftime(t_timebuf, sizeof(t_timebuf), "%Y-%m-%d %H:%M:%S.", timeinfo);

        //std::cout << t_timebuf << std::endl;
    }
    //char buf[64];
    snprintf(m_buffer, sizeof(m_buffer), "%s%06d %s %s %s:%ld %ld\n", t_timebuf, microseconds, m_srcfile.c_str(), LogLevelName[m_level], m_func.c_str(),m_line, std::this_thread::get_id());
    //this->getSS() << t_timebuf << buf << m_srcfile <<" " << LogLevelName[m_level] << m_func  << ":" << m_line << " ";

    }
    char buf[12];
    snprintf(buf, sizeof(buf), "%06d", microseconds);
    this->getSS() << t_timebuf << buf;

}
void Logger::clearAppender()
{
    m_appenderList.clear();
}
void Logger::addAppender(std::shared_ptr<LogAppender> appender)
{

    m_appenderList.push_back(std::move(appender));
}
void Logger::writeLog()
{
    //std::cout << "appender num:" << m_appenderList.size() << std::endl;

    m_appenderList.push_back(appender);
}
void Logger::writeLog()
{

    if(m_appenderList.empty())
    {
        
        m_appender->writeLog(std::ref(*this));
    }
    else
    {

        for(auto it = m_appenderList.begin(); it != m_appenderList.end(); ++it)
        {
            (*it)->writeLog(std::ref(*this));
            if(g_logLevel == LoggerLevel::FATAL)
            {
                abort();
            }
        }
    }
}

Logger::LoggerLevel initLogLevel()
{
  if (::getenv("CCNET_LOG_TRACE"))
    return Logger::LoggerLevel::TRACE;
  else if (::getenv("CCNET_LOG_DEBUG"))
    return Logger::LoggerLevel::DEBUG;
  else
    return Logger::LoggerLevel::INFO;
}
Logger::LoggerLevel g_logLevel = initLogLevel();


void Logger::setLoggerLevel(Logger::LoggerLevel level)
{
    g_logLevel = level;
}
std::stringstream& Logger::getSS()
{
    return m_ss;
}

char * Logger::getBuffer()
{
    return m_buffer;
}


//--------------------------普通日志输出类--------------------------



FileLogAppender::FileLogAppender(std::string logName) : m_logName(logName)
{
    m_fout.open(m_logName, std::ofstream::out | std::ofstream::app);
}
FileLogAppender::~FileLogAppender()
{
    m_fout.close();
}

//从缓冲区将日志输出到文件
void FileLogAppender::writeLog(Logger &logger)
{
    if(m_isActive)
    {
        m_fout << logger.getBuffer();
        //m_fout.flush();
    }
}

//--------------------------标准输出类--------------------------

        m_fout << logger.getSS().str() << std::endl;
    }
}


//从缓冲区将日志输出到stdout
void StdoutLogAppender::writeLog(Logger &logger)
{

    //std::cout << logger.getBuffer();
}

//--------------------------异步日志输出类--------------------------

AsyncOutputAppender::AsyncOutputAppender(const std::string baseName, size_t flushInterval, size_t rollSize):
m_baseName(baseName),
m_flushInterval(flushInterval),
m_rollSize(rollSize),
m_bufIn(new std::stringstream)
{
    
    m_isRunning = true;
    std::string logname = "";
    time_t mytime;
    time(&mytime);
    struct tm * timeinfo = localtime(&mytime);

    strftime(t_timebuf, sizeof(t_timebuf), "%Y-%m-%d", timeinfo);
    logname += baseName + "." + t_timebuf + ".log";
    m_fout.open(logname, std::ofstream::out | std::ofstream::app);
    m_thread = std::thread(&AsyncOutputAppender::outputLog, this);
    
    //sleep(1);
    //std::cout << "AsyncOutputAppender init\n";
    
}
AsyncOutputAppender::~AsyncOutputAppender()
{
    //std::cout << "AsyncOutputAppender destructed\n";
    if (m_isRunning)
    {
        m_isRunning = false;
        m_bufInIsFull.notify_one();
        
        //std::cout << "m_fout close\n";
        
        m_thread.join();
        m_fout.close();
        
        //std::cout << "AsyncOutputAppender close\n";
    }

}
void Logger::startAsyncLog(std::string baseName)
{
    //m_isAsyncLog = true;
    Logger::clearAppender();
    LogAppender::ptr asyncOut(new AsyncOutputAppender(baseName));
    addAppender(asyncOut);
    //std::cout << "appender num:" << m_appenderList.size() << std::endl;
    
}

void AsyncOutputAppender::writeLog(Logger &logger)
{
    //std::cout << "writeLog begin\n";
    
    Unique_Lock lck(m_mutex);
    if(m_bufIn->tellp() < m_BUFFERSIZE)         //m_BUFFERSIZE = 4000*1000
    {
        (*m_bufIn) << logger.getBuffer();
        ////std::cout  << "bufIn长度：" << m_bufIn->tellp() << std::endl;
        ////std::cout  << "bufIn内容：" << (m_bufIn->str()) << std::endl;
    }
    else
    {
        ////std::cout  << "bufIn长度不足，交换buffer" << std::endl;
        SSptr bufTemp(new std::stringstream );
        m_bufIn.swap(bufTemp);
        m_bufVec.push_back(std::move(bufTemp));
        //std::cout  << "m_bufInIsFull notify_all" << std::endl;
        m_bufInIsFull.notify_one();         //唤醒线程
    }
}

//后端，将填满的缓冲区数据写到日志中
void AsyncOutputAppender::outputLog()
{
    //std::cout << "outputLog begin\n";
    
    while(m_isRunning)
    {
        Unique_Lock lck(m_mutex);
        
        //如果后端buffer为空
        //std::cout << "wait\n";
        m_bufInIsFull.wait(lck, [this]{
            if(!m_bufVec.empty() || !m_isRunning)
                return true;
            return false;
        });//交出锁等待bufIn填满

        //std::cout << "后端buffer块大小" << m_bufVec.size() << std::endl;
        //后端缓冲区到日志
        while(m_bufVec.size() > 0)
        {
            //std::cout << m_bufVec.front()->str();

            m_fout << m_bufVec.front()->str();
            
            m_bufVec.pop_front();
            //std::cout << m_bufVec.size() << std::endl;
        }
        m_fout.flush();
    }
    //停止异步日志后，把缓冲区里的数据输出到日志。
    m_fout << m_bufIn->str();
}

    std::cout << logger.getSS().str() << std::endl;
}




}