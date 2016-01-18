/* +---------------------------------------------------------------------------+
   | File:SockWraps.cpp                                                        |
   | Authors:Ican chen  E-mail:chenmingjianwork@163.com                        |
   | Date:2015/12/31                                                           |
   | Describe:  SockWraps.cpp                                                  |
   +---------------------------------------------------------------------------+ */

#include "../../include/base/SockWraps.h"

/* Socket */
int SockWraps::Socket(int family, int type, int protocol)
{
	int n;
	if((n = socket(family, type, protocol)) < 0)
		errorSys("socket error");
	return(n);
}

int SockWraps::Bind(int fd, const struct sockaddr *sa, socklen_t salen)
{
	if(bind(fd, sa, salen) < 0)
		errorSys("bind error");
}

void SockWraps::Connect(int fd, const struct sockaddr *sa, socklen_t salen)
{
	if(connect(fd, sa, salen) < 0)
		errorSys("connect error");
}

int SockWraps::Accept(int fd, struct sockaddr *sa, socklen_t *salenptr)
{
	int	n;

again:
	if((n = accept(fd, sa, salenptr)) < 0) {
		if (errno == EPROTO || errno == ECONNABORTED)

			goto again;
		else
			errorSys("accept error");
	}

	return(n);
}

void SockWraps::Listen(int fd, int backlog)
{
	char *ptr;

		/*4can override 2nd argument with environment variable */
	if ( (ptr = getenv("LISTENQ")) != NULL)
		backlog = atoi(ptr);

	if (listen(fd, backlog) < 0)
		errorSys("listen error");
}

void SockWraps::Getpeername(int fd, struct sockaddr *sa, socklen_t *salenptr)
{
	if (getpeername(fd, sa, salenptr) < 0)
		errorSys("getpeername error");
}

void SockWraps::Getsockname(int fd, struct sockaddr *sa, socklen_t *salenptr)
{
	if (getsockname(fd, sa, salenptr) < 0)
		errorSys("getsockname error");
}

void SockWraps::Getsockopt(int fd, int level, int optname, void *optval, socklen_t *optlenptr)
{
	if (getsockopt(fd, level, optname, optval, optlenptr) < 0)
		errorSys("getsockopt error");
}

ssize_t SockWraps::Recv(int fd, void *ptr, size_t nbytes, int flags)
{
	ssize_t		n;

	if ( (n = recv(fd, ptr, nbytes, flags)) < 0)
		errorSys("recv error");
	return(n);
}

ssize_t SockWraps::Recvfrom(int fd, void *ptr, size_t nbytes, int flags,
		 struct sockaddr *sa, socklen_t *salenptr)
{
	ssize_t		n;

	if ( (n = recvfrom(fd, ptr, nbytes, flags, sa, salenptr)) < 0)
		errorSys("recvfrom error");
	return(n);
}

ssize_t SockWraps::Recvmsg(int fd, struct msghdr *msg, int flags)
{
	ssize_t		n;

	if ( (n = recvmsg(fd, msg, flags)) < 0)
		errorSys("recvmsg error");
	return(n);
}

int SockWraps::Select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds,
       struct timeval *timeout)
{
	int		n;

	if ( (n = select(nfds, readfds, writefds, exceptfds, timeout)) < 0)
		errorSys("select error");
	return(n);		/* can return 0 on timeout */
}

void SockWraps::Send(int fd, const void *ptr, size_t nbytes, int flags)
{
	if (send(fd, ptr, nbytes, flags) != (ssize_t)nbytes)
		errorSys("send error");
}

void SockWraps::Sendto(int fd, const void *ptr, size_t nbytes, int flags,
	   const struct sockaddr *sa, socklen_t salen)
{
	if (sendto(fd, ptr, nbytes, flags, sa, salen) != (ssize_t)nbytes)
		errorSys("sendto error");
}

void SockWraps::Sendmsg(int fd, const struct msghdr *msg, int flags)
{
	unsigned int	i;
	ssize_t			nbytes;

	nbytes = 0;	/* must first figure out what return value should be */
	for (i = 0; i < msg->msg_iovlen; i++)
		nbytes += msg->msg_iov[i].iov_len;

	if (sendmsg(fd, msg, flags) != nbytes)
		errorSys("sendmsg error");
}

void SockWraps::Setsockopt(int fd, int level, int optname, const void *optval, socklen_t optlen)
{
	if (setsockopt(fd, level, optname, optval, optlen) < 0)
		errorSys("setsockopt error");
}

void SockWraps::Shutdown(int fd, int how)
{
	if (shutdown(fd, how) < 0)
		errorSys("shutdown error");
}

int SockWraps::Sockatmark(int fd)
{
	int		n;

	if ( (n = sockatmark(fd)) < 0)
		errorSys("sockatmark error");
	return(n);
}

void SockWraps::Socketpair(int family, int type, int protocol, int *fd)
{
	int		n;

	if ( (n = socketpair(family, type, protocol, fd)) < 0)
		errorSys("socketpair error");
}


const char *SockWraps::Inet_ntop(int family, const void *addrptr, char *strptr, size_t len)
{
	const char	*ptr;

	if (strptr == NULL)		/* check for old code */
		errorQuit("NULL 3rd argument to inet_ntop");
	if ( (ptr = inet_ntop(family, addrptr, strptr, len)) == NULL)
		errorSys("inet_ntop error");		/* sets errno */
	return(ptr);
}

void SockWraps::Inet_pton(int family, const char *strptr, void *addrptr)
{
	int		n;

	if ( (n = inet_pton(family, strptr, addrptr)) < 0)
		errorSys("inet_pton error for %s", strptr);	/* errno set */
	else if (n == 0)
		errorQuit("inet_pton error for %s", strptr);	/* errno not set */

	/* nothing to return */
}