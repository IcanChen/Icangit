/* +---------------------------------------------------------------------------+
   | File:FindIntFromArray.h                                                   |
   | Authors:Ican chen                                                         |
   | Date:2015/11/06                                                           |
   | Describe:                                                                 |
   +---------------------------------------------------------------------------+ */
#ifndef _FINDINTFROMARRAY_H_
#define _FINDINTFROMARRAY_H_

#include <iostream>
#include <vector>

using namespace std;
using std::vector;

class Solution {
public:
	Solution(){};
	~Solution(){};

    bool Find(vector<vector<int> > array,int target);
};

#endif 