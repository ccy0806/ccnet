#include "include/base/Logger.h"
#include <iostream>
namespace ccnet{

__thread time_t t_lastSecond;

Logger::Logger(const char* srcfile, size_t line, Logger::LoggerLevel level, const char* func) :
    m_srcfile(srcfile),
    m_line(line),
    m_level(level),
    m_func(func),
    m_ts(Timestamp::now())
{
    std::cout << m_ts.getMicroSecondsSinceEpoch() << std::endl;
    //formatLogger();
    std::string mytime = m_ts.getFormatDay("%Y%m%d %H:%M:%S");
    m_logName = "logfile-" + mytime + ".log";

    m_appender = LogAppender::ptr(new FileLogAppender(m_logName));
    //m_appender = LogAppender::ptr(new StdoutLogAppender);

    this->getSS() << mytime << " " << m_srcfile <<" " << g_logLevel << " " << m_func  << ":" << m_line << " ";
}

Logger::~Logger()
{
    // auto self = shared_from_this();
    writeLog();
}

void Logger::formatLogger()
{

}

void Logger::writeLog()
{
    //auto self = shared_from_this();
    m_appender->writeLog(std::ref(*this));
    if(m_level == LoggerLevel::FATAL)
    {
        abort();
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

FileLogAppender::FileLogAppender(std::string logName) : m_logName(logName){}
//从缓冲区将日志输出到文件
void FileLogAppender::writeLog(Logger &logger)
{
    m_fout.open(m_logName, std::ofstream::out | std::ofstream::app);
    m_fout << logger.getSS().str() << std::endl;
    m_fout.close();

}


//从缓冲区将日志输出到stdout
void StdoutLogAppender::writeLog(Logger &logger)
{
    std::cout << logger.getSS().str() << std::endl;
}



}