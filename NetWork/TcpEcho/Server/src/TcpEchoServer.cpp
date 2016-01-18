/* +---------------------------------------------------------------------------+
   | File:TcpEchoServer.cpp                                                    |
   | Authors:Ican chen  E-mail:chenmingjianwork@163.com                        |
   | Date:2015/12/26                                                           |
   | Describe:                                                                 |
   +---------------------------------------------------------------------------+ */
#include "../include/TcpEchoServer.h"

void TcpEchoServer::run(int argc,char **argv)
{
	int listenfd,connfd;
	pid_t childpid;
	socklen_t clilen;
	struct sockaddr_in cliaddr,servaddr;

	listenfd = echoSock.Socket(AF_INET,SOCK_STREAM,0);

	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);

	echoSock.Bind(listenfd,(SA *) &servaddr,sizeof(servaddr));
	
	echoSock.Listen(listenfd,LISTENQ);

	while(1)
	{
		clilen = sizeof(cliaddr);
		connfd = echoSock.Accept(listenfd,(SA *) &cliaddr,&clilen);
		if(0 == (childpid = echoUnix.Fork()))
		{
			echoUnix.Close(listenfd);
			strEcho(connfd);
			exit(0);
		}
		echoUnix.Close(connfd);
	}
}

void TcpEchoServer::strEcho(int socketfd)
{
	ssize_t n;
	char buf[MAXLINE];
again:
    while( (n = read(socketfd,buf,MAXLINE)) > 0)
    	echoUnix.Writen(socketfd,buf,n);
    if(n < 0 && errno == EINTR)
    	goto again;
    else if (n < 0)
    	errorSys("str_echo: read error");
}