#include "include/net/Socketbase.h"
#include "include/base/Logger.h"

Socketbase::Socketbase(const char* ip, int port) : m_ip(ip), m_port(port)
{

}

Socketbase::~Socketbase()
{

}
void Socketbase::initSocket()
{
    
    bzero(&m_serverAddress, sizeof(m_serverAddress));
    m_serverAddress.sin_family = AF_INET;
    inet_pton(AF_INET, m_ip, &m_serverAddress.sin_addr);
    m_serverAddress.sin_port = htons(m_port);

}
int Socketbase::buildConnection(int domain = PF_INET, int type = SOCK_STREAM, int protocol = 0, int backlog = 5)
{
    m_lfd = socket(domain, type, 0);
    if(m_lfd == -1)
    {
        LOG_INFO << "socket function error";
        return -1;
    }
    int ret = bind(m_lfd, (struct sockaddr*)&m_serverAddress, sizeof(m_serverAddress));
    if(ret == -1)
    {
        LOG_INFO << "bind function error";
        return -1;
    }
    ret = listen(m_lfd, backlog);
    if(ret == -1)
    {
        LOG_INFO << "listen function error";
        return -1;
    }
    m_clientAddressLength = sizeof(m_clientAddress);
    m_connfd = accept(m_lfd, (struct sockaddr*)&m_clientAddress, &m_clientAddressLength);
    if(m_connfd < 0)
    {
        LOG_INFO << "accept function error";
        close(m_lfd);
        return -1;
    }
    return 0;
}