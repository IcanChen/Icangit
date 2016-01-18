/* +---------------------------------------------------------------------------+
   | File:UnixWraps.cpp                                                        |
   | Authors:Ican chen  E-mail:chenmingjianwork@163.com                        |
   | Date:2015/12/31                                                           |
   | Describe:  UnixWraps.cpp                                                  |
   +---------------------------------------------------------------------------+ */

#include "../../include/base/UnixWraps.h"


void * UnixWraps::Calloc(size_t n, size_t size)
{
	void	*ptr;

	if ( (ptr = calloc(n, size)) == NULL)
		errorSys("calloc error");
	return(ptr);
}

void UnixWraps::Close(int fd)
{
	if (close(fd) == -1)
		errorSys("close error");
}

void UnixWraps::Dup2(int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
		errorSys("dup2 error");
}

int UnixWraps::Fcntl(int fd, int cmd, int arg)
{
	int	n;

	if ( (n = fcntl(fd, cmd, arg)) == -1)
		errorSys("fcntl error");
	return(n);
}

void UnixWraps::Gettimeofday(struct timeval *tv, struct timezone *tz)
{
	if (gettimeofday(tv, tz) == -1)
		errorSys("gettimeofday error");
	return;
}

int UnixWraps::Ioctl(int fd, int request, void *arg)
{
	int		n;

	if ( (n = ioctl(fd, request, arg)) == -1)
		errorSys("ioctl error");
	return(n);	/* streamio of I_LIST returns value */
}

pid_t UnixWraps::Fork(void)
{
	pid_t	pid;

	if ( (pid = fork()) == -1)
		errorSys("fork error");
	return(pid);
}

void * UnixWraps::Malloc(size_t size)
{
	void	*ptr;

	if ( (ptr = malloc(size)) == NULL)
		errorSys("malloc error");
	return(ptr);
}
/*
int UnixWraps::Mkstemp(char *template)
{
	int i;

#ifdef HAVE_MKSTEMP
	if ((i = mkstemp(template)) < 0)
		errorQuit("mkstemp error");
#else
	if (mktemp(template) == NULL || template[0] == 0)
		errorQuit("mktemp error");
	i = Open(template, O_CREAT | O_WRONLY, FILE_MODE);
#endif

	return i;
}
*/

void * UnixWraps::Mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset)
{
	void	*ptr;

	if ( (ptr = mmap(addr, len, prot, flags, fd, offset)) == ((void *) -1))
		errorSys("mmap error");
	return(ptr);
}

int UnixWraps::Open(const char *pathname, int oflag, mode_t mode)
{
	int		fd;

	if ( (fd = open(pathname, oflag, mode)) == -1)
		errorSys("open error for %s", pathname);
	return(fd);
}

void UnixWraps::Pipe(int *fds)
{
	if (pipe(fds) < 0)
		errorSys("pipe error");
}

ssize_t UnixWraps::Read(int fd, void *ptr, size_t nbytes)
{
	ssize_t		n;

	if ( (n = read(fd, ptr, nbytes)) == -1)
		errorSys("read error");
	return(n);
}

void UnixWraps::Sigaddset(sigset_t *set, int signo)
{
	if (sigaddset(set, signo) == -1)
		errorSys("sigaddset error");
}

void UnixWraps::Sigdelset(sigset_t *set, int signo)
{
	if (sigdelset(set, signo) == -1)
		errorSys("sigdelset error");
}

void UnixWraps::Sigemptyset(sigset_t *set)
{
	if (sigemptyset(set) == -1)
		errorSys("sigemptyset error");
}

void UnixWraps::Sigfillset(sigset_t *set)
{
	if (sigfillset(set) == -1)
		errorSys("sigfillset error");
}

int UnixWraps::Sigismember(const sigset_t *set, int signo)
{
	int		n;

	if ( (n = sigismember(set, signo)) == -1)
		errorSys("sigismember error");
	return(n);
}

void UnixWraps::Sigpending(sigset_t *set)
{
	if (sigpending(set) == -1)
		errorSys("sigpending error");
}

void UnixWraps::Sigprocmask(int how, const sigset_t *set, sigset_t *oset)
{
	if (sigprocmask(how, set, oset) == -1)
		errorSys("sigprocmask error");
}

char * UnixWraps::Strdup(const char *str)
{
	char	*ptr;

	if ( (ptr = strdup(str)) == NULL)
		errorSys("strdup error");
	return(ptr);
}

long UnixWraps::Sysconf(int name)
{
	long	val;

	errno = 0;		/* in case sysconf() does not change this */
	if ( (val = sysconf(name)) == -1)
		errorSys("sysconf error");
	return(val);
}

/*

#ifdef	HAVE_SYS_SYSCTL_H
void UnixWraps::Sysctl(int *name, u_int namelen, void *oldp, size_t *oldlenp,
	   void *newp, size_t newlen)
{
	if (sysctl(name, namelen, oldp, oldlenp, newp, newlen) == -1)
		errorSys("sysctl error");
}
#endif
*/

void UnixWraps::Unlink(const char *pathname)
{
	if (unlink(pathname) == -1)
		errorSys("unlink error for %s", pathname);
}

pid_t UnixWraps::Wait(int *iptr)
{
	pid_t	pid;

	if ((pid = wait(iptr)) == -1)
		errorSys("wait error");
	return(pid);
}

pid_t UnixWraps::Waitpid(pid_t pid, int *iptr, int options)
{
	pid_t	retpid;

	if ( (retpid = waitpid(pid, iptr, options)) == -1)
		errorSys("waitpid error");
	return(retpid);
}

void UnixWraps::Write(int fd, void *ptr, size_t nbytes)
{
	if (write(fd, ptr, nbytes) != nbytes)
		errorSys("write error");
}

void UnixWraps::Writen(int fd, void *ptr, size_t nbytes)
{
	if (writen(fd, ptr, nbytes) != nbytes)
		errorSys("writen error");
}

/* Write "n" bytes to a descriptor. */
ssize_t	UnixWraps::writen(int fd, const void *vptr, size_t n)
{
	size_t		nleft;
	ssize_t		nwritten;
	const char	*ptr;

	ptr = (const char *)vptr;
	nleft = n;
	while (nleft > 0) {
		if ( (nwritten = write(fd, ptr, nleft)) <= 0) {
			if (nwritten < 0 && errno == EINTR)
				nwritten = 0;		/* and call write() again */
			else
				return(-1);			/* error */
		}

		nleft -= nwritten;
		ptr   += nwritten;
	}
	return(n);
}