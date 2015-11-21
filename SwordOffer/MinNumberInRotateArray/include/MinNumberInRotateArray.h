/* +---------------------------------------------------------------------------+
   | File:MinNumberInRotateArray.h                                             |
   | Authors:Ican chen  E-mail:chenmingjianwork@163.com                        |
   | Date:2015/11/20                                                           |
   | Describe:The beginning of an array of several elements to the end of the  |
   | array, we call the array of rotation. Enter a non decreasing sequence of  |
   | a rotation, the output of the smallest element of the array. For example, |
   | an array of {3,4,5,1,2} for a {1,2,3,4,5} of a rotation, the minimum value|
   | of the array is 1                                                         |
   +---------------------------------------------------------------------------+ */
#ifndef _MINNUMBERINROTATEARRAY_H_
#define _MINNUMBERINROTATEARRAY_H_

#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;
using std::vector;

class Solution{
public:
	Solution(){};
	~Solution(){};

	int MinNumberInRotateArray(vector<int> rotatearray);
};




#endif

