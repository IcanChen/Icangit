/* +---------------------------------------------------------------------------+
   | File:NetworkGrobleDefine.h                                                      |
   | Authors:Ican chen  E-mail:chenmingjianwork@163.com                        |
   | Date:2015/12/31                                                           |
   | Describe:  NetworkGrobleDefine                                                   |
   +---------------------------------------------------------------------------+ */
#ifndef _NETWORKGROBLEDEFINE_H_
#define _NETWORKGROBLEDEFINE_H_

/* Following could be derived from SOMAXCONN in <sys/socket.h>, but many
   kernels still #define it as 5, while actually supporting many more */
#define	LISTENQ		1024	/* 2nd argument to listen() */

/* Miscellaneous constants */
#define	MAXLINE		4096	/* max text line length */
#define	BUFFSIZE	8192	/* buffer size for reads and writes */
#define	SA	struct sockaddr
#define	SERV_PORT		 9877			/* TCP and UDP */
   
#endif
