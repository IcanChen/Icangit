/* +---------------------------------------------------------------------------+
   | File:main.cpp                                                             |
   | Authors:Ican chen                                                         |
   | Date:2015/11/06                                                           |
   | Describe:In a two-dimensional array, each row in accordance with the order|
   | of increasing from left to right, each column are from top to bottom by   |
   | increasing the sort order.  Please complete a function, enter such a      |
   | two-dimensional array and an integer, determine whether the array contains|
   | the integer.                                                              |
   +---------------------------------------------------------------------------+ */

#include <iostream>
#include <vector>

#include "include/FindIntFromArray.h"

using namespace std;
using std::vector;


int main( )
{
	Solution Solution;
	vector<vector<int> > array;
	int temp = 0;

	for(vector<int>::size_type i = 0;i < 10;i++)
	{
		std::vector<int> T;
		for(size_t j = 0;j < 10;j++)
		{
			T.push_back(temp);
			temp += 2;
		}
		array.push_back(T);
	}

	cout << "2" << endl;
	if(Solution.Find(array,10))
		cout << "true" << endl;
	else
		cout << "flase" << endl;

}