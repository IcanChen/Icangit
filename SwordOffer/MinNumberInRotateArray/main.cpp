/* +---------------------------------------------------------------------------+
   | File:main.cpp                                                             |
   | Authors:Ican chen  E-mail:chenmingjianwork@163.com                        |
   | Date:2015/11/20                                                           |
   | Describe:The beginning of an array of several elements to the end of the  |
   | array, we call the array of rotation. Enter a non decreasing sequence of  |
   | a rotation, the output of the smallest element of the array. For example, |
   | an array of {3,4,5,1,2} for a {1,2,3,4,5} of a rotation, the minimum value|
   | of the array is 1                                                         |
   +---------------------------------------------------------------------------+ */
#include "./include/MinNumberInRotateArray.h"

int main()
{
	int a[5] = {3,4,5,1,2};
	Solution solution;
	vector<int> array(a,a+5);
	int i = solution.MinNumberInRotateArray(array);
	cout << i <<endl;
	return 0;
} 
