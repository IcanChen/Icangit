/* +---------------------------------------------------------------------------+
   | File:TcpEchoClient.cpp                                                    |
   | Authors:Ican chen  E-mail:chenmingjianwork@163.com                        |
   | Date:2015/12/31                                                           |
   | Describe:                                                                 |
   +---------------------------------------------------------------------------+ */
#include "../include/TcpEchoClient.h"

void TcpEchoClient::run(int argc,char **argv)
{
	int sockfd;
	struct sockaddr_in servaddr;

	if(argc != 2)
		errorSys("usage: tcpcli <IPaddress>");
	sockfd = echoSock.Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	echoSock.Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

	echoSock.Connect(sockfd, (SA *) &servaddr, sizeof(servaddr));

	strCli(stdin, sockfd);		/* do it all */

	exit(0);
}

void TcpEchoClient::strCli(FILE *fp, int sockfd)
{
	char  sendLine[MAXLINE], recvLine[MAXLINE];

	while (echoStdio.Fgets(sendLine, MAXLINE, fp) != NULL) {

		echoUnix.Writen(sockfd, sendLine, strlen(sendLine));

		if (echoUnix.Readline(sockfd, recvLine, MAXLINE) == 0)
			errorQuit("str_cli: server terminated prematurely");

		echoStdio.Fputs(recvLine, stdout);
	}
}