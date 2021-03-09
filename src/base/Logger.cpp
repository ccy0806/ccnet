#include "include/base/Logger.h"
#include <iostream>

namespace ccnet{

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
        m_fout << logger.getSS().str() << std::endl;
    }
}


//从缓冲区将日志输出到stdout
void StdoutLogAppender::writeLog(Logger &logger)
{
    std::cout << logger.getSS().str() << std::endl;
}



}