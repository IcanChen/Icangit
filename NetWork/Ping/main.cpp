/* +---------------------------------------------------------------------------+
   | File:main.cpp                                                             |
   | Authors:Ican chen                                                         |
   | Date:2015/11/09                                                           |
   | Describe:ping                                                             |
   +---------------------------------------------------------------------------+ */
#include <iostream>
#include <cstring>

#include "./include/Ping.h"


int main(int argc,char *argv[])
{
	Ping ping;
	ping.ping(argc,argv);

	return 0;
}