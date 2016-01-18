/* +---------------------------------------------------------------------------+
   | File:StdioWraps.h                                                          |
   | Authors:Ican chen  E-mail:chenmingjianwork@163.com                        |
   | Date:2015/12/31                                                           |
   | Describe:  StdioWraps.h                                                    |
   +---------------------------------------------------------------------------+ */
/*
 * Standard I/O wrapper functions.
 */

#ifndef _STDIOWRAPS_H_
#define _STDIOWRAPS_H_

#include <stdio.h>
#include "./CError.h"

class StdioWraps : public CError
{
	public:
		StdioWraps(){};
		~StdioWraps(){};

		void Fclose(FILE *fp);
		FILE * Fdopen(int fd, const char *type);
		char * Fgets(char *ptr, int n, FILE *stream);
		FILE * Fopen(const char *filename, const char *mode);
		void Fputs(const char *ptr, FILE *stream);

	private:

};


#endif