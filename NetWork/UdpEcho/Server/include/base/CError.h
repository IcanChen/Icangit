/* +---------------------------------------------------------------------------+
   | File:CError.h                                                             |
   | Authors:Ican chen  E-mail:chenmingjianwork@163.com                        |
   | Date:2015/12/31                                                           |
   | Describe:  handing errors                                                 |
   +---------------------------------------------------------------------------+ */
#ifndef _CERRROR_H_
#define _CERRROR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <stdarg.h>		
#include <syslog.h>	
#include <errno.h>	

#include "./NetworkGrobleDefine.h"

using namespace std;

class CError
{
	public:
		CError(){};
		~CError(){};

		int daemon_proc;
        void daemonInetd(const char *pname, int facility);      
		void errorRet(const char *fmt, ...);
		void errorSys(const char *fmt, ...);
		void errorDump(const char *fmt, ...);
		void errorMsg(const char *fmt, ...);
		void errorQuit(const char *fmt, ...);

	private:
		void errorDoit(int errnoflag, int level, const char *fmt, va_list ap);
};




#endif