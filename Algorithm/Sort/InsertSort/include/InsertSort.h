/* +---------------------------------------------------------------------------+
   | File:DirectInsertSort.h                                                      |
   | Authors:Ican chen  E-mail:chenmingjianwork@163.com                        |
   | Date:2016/03/14                                                           |
   | Describe:                                                                 |
   +---------------------------------------------------------------------------+ */
#ifndef _DIRECTINSERTSORT_H_
#define _DIRECTINSERTSORT_H_

#include <iostream>

using namespace std;


class InsertSort
{
	public:
		InsertSort(){};
		~InsertSort(){};

		void directInsertSort(int a[], int n);
    void shellInsertSort(int a[], int n);
    private:

};




#endif