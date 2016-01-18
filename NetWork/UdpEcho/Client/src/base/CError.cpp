/* +---------------------------------------------------------------------------+
   | File:CError.cpp                                                           |
   | Authors:Ican chen  E-mail:chenmingjianwork@163.com                        |
   | Date:2015/12/31                                                           |
   | Describe:  handing errors                                                 |
   +---------------------------------------------------------------------------+ */

#include "../../include/base/CError.h"

/*Initialze syslog(), if running as daemon.*/
void CError::daemonInetd(const char *pname, int facility)
{
	daemon_proc = 1;
	openlog(pname,LOG_PID,facility);
}

/* Nonfatal error related to system call
 * Print message and return */
void CError::errorRet(const char *fmt, ...)
{
	va_list ap;
	va_start(ap,fmt);
	errorDoit(1,LOG_INFO,fmt,ap);
	va_end(ap);
	return;
}

/* Fatal error related to system call
 * Print message and terminate */
void CError::errorSys(const char *fmt, ...)
{
	va_list ap;
	va_start(ap,fmt);
	errorDoit(1,LOG_ERR,fmt,ap);
	va_end(ap);
	exit(1);
}

/* Fatal error related to system call
 * Print message, dump core, and terminate */
void CError::errorDump(const char *fmt, ...)
{
	va_list ap;
	va_start(ap,fmt);
	errorDoit(1,LOG_ERR,fmt,ap);
	va_end(ap);
	abort();
	exit(1);
}

/* Nonfatal error unrelated to system call
 * Print message and return */
void CError::errorMsg(const char *fmt, ...)
{
	va_list ap;
	va_start(ap,fmt);
	errorDoit(0,LOG_INFO,fmt,ap);
	va_end(ap);
	return;
}

/* Fatal error unrelated to system call
 * Print message and terminate */
void CError::errorQuit(const char *fmt, ...)
{
	va_list ap;
	va_start(ap,fmt);
	errorDoit(0,LOG_ERR,fmt,ap);
	va_end(ap);
	exit(1);
}

/* Print message and return to caller
 * Caller specifies "errnoflag" and "level" */
void CError::errorDoit(int errnoflag,
					   int level, 
					   const char *fmt, 
					   va_list ap)
{
	int errno_save,n;
	char buf[MAXLINE + 1];

	errno_save = errno;

	vsnprintf(buf,MAXLINE,fmt,ap);

	n = strlen(buf);

	if(errnoflag)
		snprintf(buf + n,MAXLINE - n,":%s",strerror(errno_save));
	strcat(buf,"\n");

	if(daemon_proc){
		syslog(level,buf);
	} else {
        fflush(stdout);
        fputs(buf,stderr);
        fflush(stderr);
	}

	return;
}
		