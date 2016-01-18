/* +---------------------------------------------------------------------------+
   | File:UdpEchoServer.cpp                                                    |
   | Authors:Ican chen  E-mail:chenmingjianwork@163.com                        |
   | Date:2016/01/07                                                           |
   | Describe:                                                                 |
   +---------------------------------------------------------------------------+ */
#include "../include/UdpEchoServer.h"

void UdpEchoServer::run(int argc,char **argv)
{
	int sockfd;
	struct sockaddr_in servAddr,cliAddr;

	sockfd = echoSock.Socket(AF_INET,SOCK_DGRAM,0);

	bzero(&servAddr,sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(SERV_PORT);

	echoSock.Bind(sockfd,(SA *) &servAddr,sizeof(servAddr));
	dgEcho(sockfd,(SA *) &cliAddr,sizeof(cliAddr));
}

void UdpEchoServer::dgEcho(int sockfd,SA *pcliaddr,socklen_t cliLen)
{
	int n;
	socklen_t len;
	char mesg[MAXLINE];

	while(1)
	{
		len = cliLen;
		n = echoSock.Recvfrom(sockfd,mesg,MAXLINE,0,pcliaddr,&len);

		echoSock.Sendto(sockfd,mesg,n,0,pcliaddr,len);
	}
}