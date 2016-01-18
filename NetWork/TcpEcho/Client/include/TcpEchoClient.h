/* +---------------------------------------------------------------------------+
   | File:TcpEchoClient.h                                                      |
   | Authors:Ican chen  E-mail:chenmingjianwork@163.com                        |
   | Date:2015/12/26                                                           |
   | Describe:                                                                 |
   +---------------------------------------------------------------------------+ */
#ifndef _TCPECHOCLIENT_H_
#define _TCPECHOCLIENT_H_

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <unistd.h>  

#include "./base/CError.h"
#include "./base/NetworkGrobleDefine.h"
#include "./base/SockWraps.h"
#include "./base/UnixWraps.h"
#include "./base/StdioWraps.h"


using namespace std;

class TcpEchoClient : public CError
{
	public:
		TcpEchoClient(){};
		~TcpEchoClient(){};

		void run(int argc,char **argv);

	private:
		void strCli(FILE *fp, int sockfd);
		SockWraps echoSock;
		UnixWraps echoUnix;
		StdioWraps echoStdio;
};


#endif