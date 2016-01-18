/* +---------------------------------------------------------------------------+
   | File:main.cpp                                                             |
   | Authors:Ican chen  E-mail:chenmingjianwork@163.com                        |
   | Date:2015/11/20                                                           |
   | Describe:                                                                 |
   +---------------------------------------------------------------------------+ */

#include <iostream>
#include "./include/UdpEchoClient.h"

using namespace std;

int main(int argc,char **argv)
{
	UdpEchoClient echoClient;
	echoClient.run(argc,argv);

	return 0;
}