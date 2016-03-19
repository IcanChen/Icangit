/* +---------------------------------------------------------------------------+
   | File:main.cpp                                                             |
   | Authors:Ican chen  E-mail:chenmingjianwork@163.com                        |
   | Date:2016/03/14                                                           |
   | Describe:                                                                 |
   +---------------------------------------------------------------------------+ */
#include <iostream>

#include "./include/InsertSort.h"

using namespace std;

/*---------------------------------------------------------------
					Display array
 ---------------------------------------------------------------*/
void display(int a[],int n)
{
	for(int i = 0;i < n;++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

/*---------------------------------------------------------------
					main
 ---------------------------------------------------------------*/
int main(int argc,char **argv)
{
	int a[] = {2,41,13,15,1,51,5,15,6};
    cout << sizeof(a) / sizeof(a[0]) << endl;
	display(a,sizeof(a)/sizeof(a[0]));

	InsertSort insertSort;
//	insertSort.directInsertSort(a,sizeof(a)/sizeof(a[0]));
	insertSort.shellInsertSort(a,sizeof(a)/sizeof(a[0]));
	display(a,sizeof(a)/sizeof(a[0]));
	return 0;
}
