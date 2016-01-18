/* +---------------------------------------------------------------------------+
   | File:TcpEchoClient.cpp                                                    |
   | Authors:Ican chen  E-mail:chenmingjianwork@163.com                        |
   | Date:2015/12/31                                                           |
   | Describe:                                                                 |
   +---------------------------------------------------------------------------+ */
#include "../include/UdpEchoClient.h"

void UdpEchoClient::run(int argc,char **argv)
{
	int sockfd;     
	struct sockaddr_in serAddr;

	if(argc != 2)
		errorQuit("Usage: udpcli <IPaddress>");
	bzero(&serAddr,sizeof(serAddr));
	serAddr.sin_family = AF_INET;
	serAddr.sin_port = htons(SERV_PORT);
	echoSock.Inet_pton(AF_INET,argv[1],&serAddr.sin_addr);

	sockfd = echoSock.Socket(AF_INET,SOCK_DGRAM,0);

	dgCli(stdin,sockfd,(SA *) &serAddr,sizeof(serAddr));
	exit(0);
}

void UdpEchoClient::dgCli(FILE *fp, int sockfd,const SA *pseraddr,socklen_t servlen)
{
	int n;
	char sendLine[MAXLINE],recvLine[MAXLINE + 1];

	while(echoStdio.Fgets(sendLine,MAXLINE,fp) != NULL)
	{
		echoSock.Sendto(sockfd,sendLine,strlen(sendLine),0,pseraddr,servlen);

		n = echoSock.Recvfrom(sockfd,recvLine,MAXLINE,0,NULL,NULL);
		recvLine[n] = 0;
		echoStdio.Fputs(recvLine,stdout);
	}
}