/* +---------------------------------------------------------------------------+
   | File:PingStruct.h                                                         |
   | Authors:Ican chen                                                         |
   | Date:2015/11/09                                                           |
   | Describe:ping                                                             |
   +---------------------------------------------------------------------------+ */
#ifndef _PINGSTRUCT_H_
#define _PINGSTRUCT_H_


#define BUFFERSIZE 72	
#define K 1024		



typedef struct pingm_pakcet{
	struct timeval tv_begin;	
	struct timeval tv_end;		
	short seq;				
	int flag;				
								
}pingm_pakcet;




#endif	