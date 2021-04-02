#ifndef CCNET_NET_SOCKETBASE
#define CCNET_NET_SOCKETBASE

#include <sys/types.h>          
#include <sys/socket.h>

namespace ccnet
{

class Socketbase
{
public:
    Socketbase(const char* ip, int port);
    ~Socketbase();
    void initSocket();
    int getFd(){return m_lfd;}
    int getPort(){return m_port;}
    const char* getIp(){return m_ip;}
    int buildConnection(int domain, int type, int protocol, int backlog);   
    int setNonblocking(int fd);
private:
    int m_lfd;   //连接监听fd
    int m_port;     //端口号
    const char* m_ip;   //  ip
    struct sockaddr_in m_serverAddress;
    struct sockaddr_in m_clientAddress;
    int m_connfd;   //维护客户端连接的fd
    socklen_t m_clientAddressLength;
}

}

#endif