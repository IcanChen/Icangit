/* +---------------------------------------------------------------------------+
   | File:TcpEchoServer.h                                                      |
   | Authors:Ican chen  E-mail:chenmingjianwork@163.com                        |
   | Date:2015/12/26                                                           |
   | Describe:                                                                 |
   +---------------------------------------------------------------------------+ */
#ifndef _TCPECHOSERVER_H_
#define _TCPECHOSERVER_H_

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <unistd.h>  

#include "./base/CError.h"
#include "./base/NetworkGrobleDefine.h"
#include "./base/SockWraps.h"
#include "./base/UnixWraps.h"


using namespace std;

class TcpEchoServer : public CError
{
	public:
		TcpEchoServer(){};
		~TcpEchoServer(){};

		void run(int argc,char **argv);

	private:
		void strEcho(int sockfd);
		SockWraps echoSock;
		UnixWraps echoUnix;
};




#endif
