/* +---------------------------------------------------------------------------+
   | File:InsertSort.cpp                                                    |
   | Authors:Ican chen  E-mail:chenmingjianwork@163.com                        |
   | Date:2016/03/14                                                           |
   | Describe:                                                                 |
   +---------------------------------------------------------------------------+ */
#include "../include/InsertSort.h"

/*---------------------------------------------------------------
					DirectInsertSort
 ---------------------------------------------------------------*/
void InsertSort::directInsertSort(int a[], int n)
{
	int temp;
	for(int i = 1;i < n;++i)//
	{
		temp = a[i];
		int j;
		for(j = i - 1;j >= 0 && temp < a[j];--j)
		{
			a[j+1] = a[j];
		}
		a[j+1] = temp;
	}

}

/*---------------------------------------------------------------
					ShellInsertSort
 ---------------------------------------------------------------*/
void InsertSort::shellInsertSort(int a[], int n)
{
	int temp,j;
	for(int h = n/2;h > 0;h = h/2)
	{
		for(int i = h;i < n;++i)
		{
			temp = a[i];
			for(j = i - h;j >= 0 && temp < a[j];j -= h)
			{
				a[j+h] = a[j];
			}
			a[j+h] = temp;
		}
	}

}