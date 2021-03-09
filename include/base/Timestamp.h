#ifndef CCNET_BASE_TIMESTAMP
#define CCNET_BASE_TIMESTAMP

#include <ctime>
#include <string>
#include <memory>
#include <sys/time.h>
class Timestamp
{
public:
    //typedef std::shared_ptr<Timestamp> ptr;
    Timestamp(int64_t microSecondsSinceEpoch);
    ~Timestamp();
    //std::string getFormatDay(const std::string format);
    int64_t getMicroSecondsSinceEpoch() {return m_microSecondsSinceEpoch;}
    static Timestamp now();
    static const int kMicroSecondsPerSecond = 1000 * 1000;

private:
    //time_t mytime;                        //日期：年月日
    //const std::string m_format;
    //char m_buf[64];                       //日期缓存
    int64_t m_microSecondsSinceEpoch;     //自1970-01-01过了多少微妙
    //int64_t m_seconds;                    //秒
    //int m_microseconds;                   //微秒

};
inline double timeDifference(Timestamp high, Timestamp low)
{
  int64_t diff = high.getMicroSecondsSinceEpoch() - low.getMicroSecondsSinceEpoch();
  return static_cast<double>(diff) / Timestamp::kMicroSecondsPerSecond;
}


#endif
