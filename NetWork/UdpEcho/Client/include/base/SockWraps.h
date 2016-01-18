/* +---------------------------------------------------------------------------+
   | File:SockWraps.h                                                          |
   | Authors:Ican chen  E-mail:chenmingjianwork@163.com                        |
   | Date:2015/12/31                                                           |
   | Describe:  SockWraps.h                                                    |
   +---------------------------------------------------------------------------+ */
/*
 * Socket wrapper functions.
 * These could all go into separate files, so only the ones needed cause
 * the corresponding function to be added to the executable.  If sockets
 * are a library (SVR4) this might make a difference (?), but if sockets
 * are in the kernel (BSD) it doesn't matter.
 *
 * These wrapper functions also use the same prototypes as POSIX.1g,
 * which might differ from many implementations (i.e., POSIX.1g specifies
 * the fourth argument to getsockopt() as "void *", not "char *").
 *
 * If your system's headers are not correct [i.e., the Solaris 2.5
 * <sys/socket.h> omits the "const" from the second argument to both
 * bind() and connect()], you'll get warnings of the form:
 *warning: passing arg 2 of `bind' discards `const' from pointer target type
 *warning: passing arg 2 of `connect' discards `const' from pointer target type
 */

#ifndef _SOCKWRAPS_H_
#define _SOCKWRAPS_H_

#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>
 
#include "./CError.h"

class SockWraps : public CError
{
	public:
		SockWraps(){};
		~SockWraps(){};

		int Socket(int family, int type, int protocol);
		int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr);
		int Bind(int fd, const struct sockaddr *sa, socklen_t salen);
		void Connect(int fd, const struct sockaddr *sa, socklen_t salen);
		void Getpeername(int fd, struct sockaddr *sa, socklen_t *salenptr);
		void Getsockname(int fd, struct sockaddr *sa, socklen_t *salenptr);
		void Getsockopt(int fd, int level, int optname, void *optval, socklen_t *optlenptr);
		void Listen(int fd, int backlog);
		ssize_t Recv(int fd, void *ptr, size_t nbytes, int flags);
		ssize_t Recvfrom(int fd, void *ptr, size_t nbytes, int flags,
		                  struct sockaddr *sa, socklen_t *salenptr);
		ssize_t Recvmsg(int fd, struct msghdr *msg, int flags);
		int Select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds,
       			   struct timeval *timeout);
		void Send(int fd, const void *ptr, size_t nbytes, int flags);
		void Sendto(int fd, const void *ptr, size_t nbytes, int flags,
	   				const struct sockaddr *sa, socklen_t salen);
		void Sendmsg(int fd, const struct msghdr *msg, int flags);
		void Setsockopt(int fd, int level, int optname, const void *optval, socklen_t optlen);
		void Shutdown(int fd, int how);
		int Sockatmark(int fd);
		void Socketpair(int family, int type, int protocol, int *fd);

		const char *Inet_ntop(int family, const void *addrptr, char *strptr, size_t len);
		void Inet_pton(int family, const char *strptr, void *addrptr);
	private:


};

#endif