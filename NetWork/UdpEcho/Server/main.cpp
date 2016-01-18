/* +---------------------------------------------------------------------------+
   | File:main.cpp                                                             |
   | Authors:Ican chen  E-mail:chenmingjianwork@163.com                        |
   | Date:2016/01/07                                                           |
   | Describe:                                                                 |
   +---------------------------------------------------------------------------+ */
#include <iostream>

#include "./include/UdpEchoServer.h"

using namespace std;


int main(int argc,char **argv)
{
	UdpEchoServer echoServer;
	echoServer.run(argc,argv);

	return 0;
}