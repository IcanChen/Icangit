/* +---------------------------------------------------------------------------+
   | File:Ping.cpp                                                             |
   | Authors:Ican chen                                                         |
   | Date:2015/11/09                                                           |
   | Describe:ping                                                             |
   +---------------------------------------------------------------------------+ */
#include "../include/Ping.h"
#include "../include/PingStruct.h"

int Ping::alive = 0;

void Ping::Icmp_Sigint(int signo)
{
	alive = 0;
//	gettimeofday(&tv_end,NULL);
//	tv_interval = Icmp_Tvsub(tv_end,tv_begin);

	return;
}

void Ping::Icmp_Usage()
{
	printf("ping aaa.bbb.cc.ddd\n");
}

unsigned short Ping::Icmp_Cksum(unsigned char *data,int len)
{
	int sum = 0;
	int odd = len & 0x01;
	unsigned short *value = (unsigned short*)data;

	while(len & 0xfffe)
	{
		sum += *(unsigned short*)data;
		data += 2;
		len -= 2;
	}

	if(odd) 
	{
		unsigned short tmp = ((*data) << 8) & 0xff00;
		sum += tmp;
	}

	sum = (sum >> 16) +(sum & 0xffff);
	sum += (sum >> 16);

	return ~sum;
}

void Ping::Icmp_Pack(struct icmp *icmph,int seq,struct timeval *tv,int length)
{
	unsigned char i = 0;

	icmph->icmp_type = ICMP_ECHO;
	icmph->icmp_code = 0;
	icmph->icmp_cksum = 0;
	icmph->icmp_seq = seq;
	icmph->icmp_id = pid & 0xffff;

	for(i = 0;i < length;i++)
		icmph->icmp_data[i] = i;

	icmph->icmp_cksum = Icmp_Cksum((unsigned char*)icmph,length);
}

int Ping::Icmp_Unpack(char *buf,int len)
{
	int i,iphdrlen;
	struct ip *ip = NULL;
	struct icmp *icmp = NULL;

	int rtt;

	ip = (struct ip *)buf;
	iphdrlen = ip->ip_hl*4;
	icmp = (struct icmp *)(buf + iphdrlen);
	len -= iphdrlen;

	if(len < 8)
	{
		printf("ICMP packet \'s length is less than 8\n");
	}

	if((ICMP_ECHOREPLY == icmp->icmp_type) && (pid == icmp->icmp_id))
	{
		struct timeval tv_internel,tv_recv,tv_send;

		pingm_pakcet* packet = Icmp_Findpacket(icmp->icmp_seq);
		if(NULL == packet)
			return -1;
		packet->flag = 0;
		tv_send = packet->tv_begin;

		gettimeofday(&tv_recv,NULL);
		tv_internel = Icmp_Tvsub(tv_recv,tv_send);
		rtt = tv_internel.tv_sec*1000 + tv_internel.tv_usec/1000;

		printf("%d byte from %s: icmp_seq=%u ttl=%d rrt=%d ms\n",
			len,
			inet_ntoa(ip->ip_src),
			icmp->icmp_seq,
			ip->ip_ttl,
			rtt);

		packet_recv++;
	}
	else
		return -1;
	
}

struct timeval Ping::Icmp_Tvsub(struct timeval end,struct timeval begin)
{
	struct timeval tv;

	tv.tv_sec = end.tv_sec - begin.tv_sec;
	tv.tv_usec = end.tv_usec - begin.tv_usec;

	if(tv.tv_usec < 0)
	{
		tv.tv_sec--;
		tv.tv_usec += 1000000;
	}

	return tv;
}

void Ping::Icmp_Send( )
{
	struct timeval tv;
	tv.tv_usec = 0;
	tv.tv_sec = 1;
	gettimeofday(&tv_begin,NULL);

	while(alive)
	{
		int size = 0;
		struct timeval tv;
		gettimeofday(&tv,NULL);

		Icmp_Pack((struct icmp*)send_buff,packet_send,&tv,64);

		size = sendto(rawsock,send_buff,64,0,
			(struct sockaddr *)&dest,sizeof(dest));
		if(size < 0)
		{
			perror("sendto error");
			continue;
		}
		else
		{
			pingm_pakcet *packet = Icmp_Findpacket(-1);

			if(packet) 
			{
				packet->seq = packet_send;
				packet->flag = 1;
				gettimeofday(&packet->tv_begin,NULL);
				packet_send++;
			}
		}

		sleep(1);
	}
}

void Ping::Icmp_Recv( )
{
	struct timeval tv;
	tv.tv_usec = 200;
	tv.tv_sec = 0;
	fd_set readfd;

	while(alive)
	{
		int ret = 0;
		FD_ZERO(&readfd);
		FD_SET(rawsock,&readfd);
		ret = select(rawsock+1,&readfd,NULL,NULL,&tv);
		switch(ret)
		{
			case -1:
				break;
			case 0:
				break;
			default:

				{
					int fromlen = 0;
					struct sockaddr from;
					int size = recv(rawsock,recv_buff,sizeof(recv_buff),0);
					if(EINTR == errno)
					{
						perror("recvfrom error");
						continue;
					}

					ret = Icmp_Unpack(recv_buff,size);
					if(-1 == ret)
					{
						continue;
					}
				}
				break;
		}
	}
}

pingm_pakcet *Ping::Icmp_Findpacket(int seq)
{
	int i = 0;
	pingm_pakcet *found = NULL;

	if(-1 == seq)
	{
		for(int i = 0;i < 128;i++)
		{
			if(0 == pingpacket[i].flag)
			{
				found = &pingpacket[i];
				break;
			}
		}
	}
	else if(seq >= 0)
	{
		for(i = 0;i < 128;i++)
		{
			if(pingpacket[i].seq == seq)
			{
				found = &pingpacket[i];
				break;
			}
		}
	}

	return found;
}

void Ping::Icmp_Statistics(void)
{
	gettimeofday(&tv_end,NULL);
	tv_interval = Icmp_Tvsub(tv_end,tv_begin);
	long time = (tv_interval.tv_sec * 1000) + (tv_interval.tv_usec/1000);
	printf("--- %s ping statistics ---\n",dest_str);
	printf("%d packets transmitted, %d received, %d%c packet loss, time %dms\n",
		packet_send,
		packet_recv,
		(packet_send - packet_recv)*100/packet_send,
		'%',
		time);
}


int Ping::ping(int argc,char *argv[])
{

	struct hostent *host = NULL;
	struct protoent *protocol = NULL;
	char protoname[] = "icmp";
	unsigned long inaddr = 1;
	int size = 128*K;

	if(argc < 2)
	{
		Icmp_Usage();
		return -1;
	}

	protocol = getprotobyname(protoname);
	if(NULL == protocol)
	{
		perror("getprotobyname()");
		return -1;
	}

	memcpy(dest_str,argv[1],strlen(argv[1]) + 1);

	rawsock = socket(AF_INET,SOCK_RAW,protocol->p_proto);

	if(rawsock < 0)
	{
		perror("socket");
		return -1;
	}

	pid = getuid();

	setsockopt(rawsock,SOL_SOCKET,SO_RCVBUF,&size,sizeof(size));
	bzero(&dest,sizeof(dest));

	dest.sin_family = AF_INET;


	inaddr = inet_addr(argv[1]);
	if(INADDR_NONE == inaddr)
	{
		host = gethostbyname(argv[1]);
		if(NULL == host)
		{
			perror("gethostbyname");
			return -1;
		}

		memcpy((char *)&dest.sin_addr,host->h_addr,host->h_length);	
	}
	else
	{
		memcpy((char *)&dest.sin_addr,&inaddr,sizeof(inaddr));
	}

	inaddr = dest.sin_addr.s_addr;

	printf("PING %s (%d.%d.%d.%d) 56(84) bytes of data.\n",
		dest_str,
		(inaddr&0x000000FF) >> 0,
		(inaddr&0x0000FF00) >> 8,
		(inaddr&0x00FF0000) >> 16,
		(inaddr&0xFF000000) >> 24);

	signal(SIGINT,Icmp_Sigint);

	alive = 1;
	pthread_t send_id,recv_id;
	int err = 0;
	err = pthread_create(&send_id,NULL,Send_Thread,this);
	if(err < 0)
	{
		return -1;
	}
	err = pthread_create(&send_id,NULL,Recv_Thread,this);
	if(err < 0)
	{
		return -1;
	}

	pthread_join(send_id,NULL);
	pthread_join(recv_id,NULL);

	close(rawsock);
	Icmp_Statistics();
	return 0;
}