/* +---------------------------------------------------------------------------+
   | File:ping.h                                                             |
   | Authors:Ican chen                                                         |
   | Date:2015/11/09                                                           |
   | Describe:ping                                                             |
   +---------------------------------------------------------------------------+ */

#ifndef _PING_H_
#define _PING_H_

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <unistd.h>
#include <signal.h>

#include <arpa/inet.h>
#include <errno.h>
#include <sys/time.h>
#include <stdio.h>
#include <string.h> /* bzero */
#include <netdb.h>
#include <pthread.h>

#include "PingStruct.h"
using namespace std;



class Ping{

public:
	Ping(){
		pid = 0;
		packet_send = 0;
		rawsock = 0;
		packet_recv = 0;
		
	};
	~Ping(){};


	static int alive;
	int ping(int argc,char *argv[]);

private:
	
	unsigned char send_buff[BUFFERSIZE];
	short packet_send;	
	short packet_recv;	
	
	pingm_pakcet pingpacket[128];	
	char recv_buff[2*K];
	char dest_str[80];
	int rawsock;
	pid_t pid;
	struct sockaddr_in dest;
	
	struct timeval tv_begin, tv_end,tv_interval;

	void Icmp_Usage();
	struct timeval Icmp_Tvsub(struct timeval end,struct timeval begin);
	unsigned short Icmp_Cksum(unsigned char *data,int len);
	void Icmp_Pack(struct icmp *icmphh,int seq,struct timeval *tv,int length);
	int Icmp_Unpack(char *buf,int len);
	void Icmp_Send();
	void Icmp_Recv();
	pingm_pakcet *Icmp_Findpacket(int seq);
	void Icmp_Statistics(void);
	static void Icmp_Sigint(int signo);
	
	static void* Send_Thread(void* arg)
	{
		Ping* P = static_cast<Ping*>(arg);
		P->Icmp_Send();
	}

	static void* Recv_Thread(void* arg)
	{
		Ping* P = static_cast<Ping*>(arg);
		P->Icmp_Recv();
	}

};


#endif