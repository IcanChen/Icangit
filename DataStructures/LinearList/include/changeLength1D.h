/* +---------------------------------------------------------------------------+
   | File:changeLength1D.h                                                     |
   | Authors:Ican chen  E-mail:chenmingjianwork@163.com                        |
   | Date:2015/12/22                                                           |
   | Describe: change the length of an array.                                  |
  +---------------------------------------------------------------------------+ */
#ifndef _CHANGELENGTH1D_H_
#define _CHANGELENGTH1D_H_

#include "myExceptions.h"

using namespace std;

template<class T>
void changeLength1D(T*& a,int oldLength,int newLength)
{
	if(newLength < 0)
		throw illegalParameterValue("new length must be >= 0");
	T* temp = new T[newLength];
	int number = min(oldLength,newLength);
	copy(a,a + number,temp);
	delete [] a;
	a = temp;
}



#endif