/* +---------------------------------------------------------------------------+
   | File:StdioWraps.cpp                                                       |
   | Authors:Ican chen  E-mail:chenmingjianwork@163.com                        |
   | Date:2015/12/31                                                           |
   | Describe:  StdioWraps.cpp                                                 |
   +---------------------------------------------------------------------------+ */
#include "../../include/base/StdioWraps.h"


void StdioWraps::Fclose(FILE *fp)
{
	if (fclose(fp) != 0)
		errorSys("fclose error");
}

FILE * StdioWraps::Fdopen(int fd, const char *type)
{
	FILE	*fp;

	if ( (fp = fdopen(fd, type)) == NULL)
		errorSys("fdopen error");

	return(fp);
}

char * StdioWraps::Fgets(char *ptr, int n, FILE *stream)
{
	char	*rptr;

	if ( (rptr = fgets(ptr, n, stream)) == NULL && ferror(stream))
		errorSys("fgets error");

	return (rptr);
}

FILE * StdioWraps::Fopen(const char *filename, const char *mode)
{
	FILE	*fp;

	if ( (fp = fopen(filename, mode)) == NULL)
		errorSys("fopen error");

	return(fp);
}

void StdioWraps::Fputs(const char *ptr, FILE *stream)
{
	if (fputs(ptr, stream) == EOF)
		errorSys("fputs error");
}