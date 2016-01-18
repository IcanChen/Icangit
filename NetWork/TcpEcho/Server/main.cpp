/* +---------------------------------------------------------------------------+
   | File:main.cpp                                                             |
   | Authors:Ican chen  E-mail:chenmingjianwork@163.com                        |
   | Date:2015/12/26                                                           |
   | Describe:                                                                 |
   +---------------------------------------------------------------------------+ */
#include <iostream>

#include "./include/TcpEchoServer.h"

using namespace std;


int main(int argc,char **argv)
{
	TcpEchoServer echoServer;
	echoServer.run(argc,argv);

	return 0;
}